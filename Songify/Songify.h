#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Album.h"
#include "MediaFactory.h"

using namespace std;

class Songify {
		
	public:
		//constructors
		Songify();

		//destructor
		~Songify();

		// add and remove Songs and Albums
		bool addAlbum ( const string & artist , const string & albumTitle );
		bool addSong ( const string & artist , const string & songTitle , const string & albumTitle );
		bool removeSong ( const string & artist , const string & songTitle , const string & albumTitle );
		bool removeAlbum ( const string & artist , const string & albumTitle );

		bool getAlbum(int, Album**) const;
		const Array<Album*>& getAlbums() const;
		void getPlaylist(const string& artist, const string& category, Array<Song*>& playlist) const;
	
	private:
		Array<Album*> albums;
		MediaFactory mf;
};
#endif