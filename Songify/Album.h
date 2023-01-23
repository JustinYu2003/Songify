#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Song.h"
#include "Array.h"

using namespace std;

class Album {

	//Overload << operator
	friend ostream& operator<<(ostream& o, const Album& a);
		
	public:
		//constructors
		Album(const string& artist, const string& albumTitle);

		//destructor
		~Album();

		//getters
		const string& getTitle() const{return title;}
		const string& getArtist() const{return artist;}

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;
		bool lessThan(const Album&) const;

		//add and remove
		bool addSong(Song*);
		bool getSong(const string& songTitle, Song**) const;
		bool removeSong(const string& songTitle, Song**);
		bool removeSong(int, Song**);

		//Operator overloading
		Song*& operator[](int) const;

		int getSize() const;
		void printShort(ostream& o) const;
		void print(ostream& o) const;
	
	private:
		string title;
		string artist;
		Array<Song*> songs;
};

#endif