#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H

#include <iostream>
#include <string>
#include "Album.h"
#include "Criteria.h"

using namespace std;

class MediaFactory {
		
	public:
		// create a Song 
		bool createSong(const string& name, const string& artist, Song**) const;

		// create an Album
		bool createAlbum(const string& name, const string& artist, Album**) const;

		// create Criteria
		bool createCriteria(const string& artist, const string& category, Criteria**) const;
	
};
#endif