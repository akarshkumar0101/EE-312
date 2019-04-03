#include <string>
#include <iostream>
#include "Song.h"


Song::Song(){
	this->title = "";
	this->artist = "";
	this->size = 0;
}
Song::Song(std::string artist, std::string title, int size){
	if(title.empty() || artist.empty()|| size<= 0){
		std::cout << "Cannot create a song with title: " << title << ", artist: " << artist << ", and size: " << size << " (Invalid)"<<std::endl;
		
	}
	if(title.empty()){
		this->title = "untitled";
	}
	else{
		this->title = title;
	}
	if(artist.empty()){
		this->artist = "untitled";
	}
	else{
		this->artist = artist;
	}
	if(size<=0){
		this->size = 1;
	}
	else{
		this->size = size;	
	}
	
}
Song::~Song(){}

std::string Song::getTitle() const{
	return title;
}
std::string Song::getArtist() const{
	return artist;
}
int Song::getSize() const{
	return size;
}

//Title, Artist, size in MB (one song per line)
std::ostream& operator<<(std::ostream& os, const Song& song){
	os << song.getTitle() << ", by: " << song.getArtist() << ", " << song.getSize() << " MB";
	return os;
}
bool operator==(const Song &s1, const Song &s2){
	return s1.title ==s2.title && s1.artist == s2. artist && s1.size == s2.size;
}
bool operator>(const Song &s1, const Song &s2){
	if(s1.artist==s2.artist){
		if(s1.title==s2.title){
			if(s1.size==s2.size){
				return false;
			}
			else{
				return s1.size>s2.size;
			}
		}
		else{
			return s1.title>s2.title;
		}
	}
	else {
		return s1.artist>s2.artist;
	}
}
bool operator<(const Song &s1, const Song &s2){
	if(s1.artist==s2.artist){
		if(s1.title==s2.title){
			if(s1.size==s2.size){
				return false;
			}
			else{
				return s1.size<s2.size;
			}
		}
		else{
			return s1.title<s2.title;
		}
	}
	else {
		return s1.artist<s2.artist;
	}
}

