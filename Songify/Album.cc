#include "Album.h"

//Constructor
Album::Album(const string& artist, const string& title) {
    this->artist = artist;
    this->title = title;
}

//Destructor
Album::~Album() {
   for(int i = 0; i < songs.getSize(); i++) {
		delete songs[i];
	}
}

//Checks for matching artist and title
bool Album::matches(const string& artist, const string& title) const {
    return ((this->artist.compare(artist) == 0) && (this->title.compare(title) == 0));
}

bool Album::lessThan(const Album& alb) const {
    //Check if artist is less than the provided album
    if(this->artist.compare(alb.artist) < 0) {
        return true;
    }else if(this->artist.compare(alb.artist) > 0) {
        return false;
    }

    //If album same, compare titles
    return (this->title.compare(alb.title) < 0);
}

bool Album::addSong(Song* s) {
    //Check that the artists are the same before adding
    if(this->artist.compare(s->getArtist()) != 0 || songs.isFull()) { return false; }
    
    songs += s;
    return true;
}

bool Album::getSong(const string& title, Song** s) const {
    for(int i = 0; i < songs.getSize(); i++) {
        if(songs[i]->matches(artist, title)) {
            *s = songs[i];
            return true;
        }
    }

    *s = NULL;
    return false;
}

bool Album::removeSong(const string& title, Song** s) {
    bool found = false;
    for(int i = 0; i < songs.getSize(); i++) {
        if(songs[i]->matches(artist, title)) {
            *s = songs[i];
            found = true;
        }
    }

    if(found) {
        songs -= *s;
        return true;
    }

    *s = NULL;
    return false;
}

bool Album::removeSong(const int index, Song** s) {
    if(index < 0 || index >= songs.getSize()) { 
        *s = NULL;
        return false; 
        }

    *s = songs[index];
    songs -= *s;
    return true;
}

int Album::getSize() const {
    return songs.getSize();
}

Song*& Album::operator[](int index) const {
    return songs[index];
}

void Album::printShort(ostream& o) const {
    o<<title<<" Album By " <<artist<<endl;
}

void Album::print(ostream& o) const {
    printShort(o);
    for(int i = 0; i < songs.getSize(); i++) {
        songs[i]->print(o);
    }
}

ostream& operator<<(ostream& o, const Album& a) {
    a.print(o);
    return o;
}