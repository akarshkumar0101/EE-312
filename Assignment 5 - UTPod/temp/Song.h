#ifndef SONG_H
#define SONG_H
#include <string>

class Song {

private: 
	std::string title;
	std::string artist;
	int size;

public:
	Song();
	Song(std::string title, std::string artist, int size);
	~Song();

	std::string getTitle() const;
	std::string getArtist() const;
	int getSize() const;


	//Title, Artist, size in MB (one song per line)
	//std::ostream& operator<<(std::ostream& os, const Song& song);
	friend std::ostream& operator<<(std::ostream &os, const Song &song);

	friend bool operator==(const Song &s1, const Song &s2);
	
	friend bool operator>(const Song &s1, const Song &s2);
	friend bool operator<(const Song &s1, const Song &s2);

};


#endif
