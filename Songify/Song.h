#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song {

	friend ostream& operator<<(ostream& o, const Song& s);
		
	public:
		//constructors
		Song(const string& artist, const string&  title, const string& category, const string& content);

		//getters
		const string& getTitle() const;
		const string& getArtist() const;
		const string& getCategory() const;

		bool matches(const string& artist, const string& title) const;

		void print(ostream& o) const;
		void play(ostream& o) const;
	
	private:
		string title;
		string artist;
		string content;
		string category;
};
#endif