#include "Songify.h"

//constructors
Songify::Songify() {
    // albums = Array<Album*>();
    mf = MediaFactory();
}

//destructor
Songify::~Songify() {
    for(int i = 0; i < albums.getSize(); i++) {
		delete albums[i];
	}
}

bool Songify::addAlbum ( const string & artist , const string & albumTitle ) {
    if (albums.getSize() >= MAX_ARRAY) { return false; }

    Album* newAlbum;
    mf.createAlbum(albumTitle, artist, &newAlbum);

    albums += newAlbum;
    return true;
}

bool Songify::addSong ( const string & artist , const string & songTitle , const string & albumTitle ) {
    Song* newSong;
    if(!mf.createSong(artist, songTitle, &newSong)) {
        return false;
    }

    //Loop through the albums until find a match, then add the song into it
    for(int i = 0; i < albums.getSize(); i++) {
        if(albums[i]->matches(artist, albumTitle)) {
            return albums[i]->addSong(newSong);
        }
    }

    return false;
}

bool Songify::removeSong ( const string & artist , const string & songTitle , const string & albumTitle ) {
    Song* removedSong;
    bool removed = false;

    //Loop through the albums until find a match, then remove the song frmo it
    for(int i = 0; i < albums.getSize(); i++) {
        if(albums[i]->matches(artist, albumTitle)) {
            for(int j = 0; j < albums[i]->getSize(); j++) {
                removed = albums[i]->removeSong(songTitle, &removedSong);
                delete removedSong;
                return removed;
            }
        }
    }

    return removed;
}

bool Songify::removeAlbum ( const string & artist , const string & albumTitle ) {
    Album* removedAlbum;
    
    for(int i = 0; i < albums.getSize(); i++) {
        if(albums[i]->matches(artist, albumTitle)) {
            removedAlbum = albums[i];
            albums -= removedAlbum;
            return true;
        }
    }

    delete removedAlbum;
    return false;
}

bool Songify::getAlbum(int index, Album** a) const {
    if(index < 0 || index >= albums.getSize()) { return false; }

    *a = albums[index];
    return true;
}

const Array<Album*>& Songify::getAlbums() const {
    return albums;
}

void Songify::getPlaylist(const string& artist, const string& category, Array<Song*>& playlist) const {
    Criteria* c;
    if(!mf.createCriteria(artist, category, &c)) {
        return;
    }

    for(int i = 0; i < albums.getSize(); i++) {
        for(int j = 0; j < albums[i]->getSize(); j++) {
            if(c->matches(*albums[i]->operator[](j))) {
                playlist += albums[i]->operator[](j);
            }
        }
    }

    cout<<playlist.getSize()<<endl;
    for(int i = 0; i < playlist.getSize(); i++) {
        cout<<*playlist[i]<<endl;
    }

    delete c;
}