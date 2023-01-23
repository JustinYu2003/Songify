#include "Song.h"

//constructors
Song::Song(const string& artist, const string&  title, const string& category, const string& content) {
    this->artist = artist;
    this->title = title;
    this->category = category;
    this->content = content;
}

//getters
const string& Song::getTitle() const { return title; }
const string& Song::getArtist() const { return artist; }
const string& Song::getCategory() const { return category; }

bool Song::matches(const string& artist, const string& title) const {
    return (this->artist.compare(artist) == 0 && this->title.compare(title) == 0);
}

void Song::print(ostream& o) const {
    o<<title<<" by "<<category<< " artist "<<artist<<endl;
}

void Song::play(ostream& o) const {
    print(o);
    o<<content<<endl;
}

ostream& operator<<(ostream& o, const Song& s) {
    o<<s.title<<" by "<<s.artist<<endl;
    return o;
}
	