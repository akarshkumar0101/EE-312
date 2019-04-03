#include <iostream>
#include <cstdlib>
#include "UtPod.h"


//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
	this->podMemSize = MAX_MEMORY;
	songs = NULL;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){
	if(size>MAX_MEMORY || size <=0){
		this->podMemSize = MAX_MEMORY;
	}
	else{
		this->podMemSize = size;
	}
	songs = NULL;
}

UtPod::~UtPod(){
	this->clearMemory();
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
		 o returns a 0 if successful
		 o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/

int UtPod::addSong(Song const &s){
	if(this->memCurrentlyTaken()+s.getSize()>this->podMemSize){
		std::cout<< "Cannot add song: "<< s << ", not enough space" << std::endl;
		return NO_MEMORY;
	}

	SongNode* songNodePtr = new SongNode;
	songNodePtr->s = s;
	songNodePtr->next = NULL;

	if(songs == NULL){
		songs = songNodePtr;
	}
	else{
		SongNode* currentNode = songs;
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		currentNode->next = songNodePtr;
	}

	return SUCCESS;
}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
		 o returns 0 if successful
		 o returns -1 if nothing is removed


	 input parms -

	 output parms -
*/

int UtPod::removeSong(Song const &s){
	int index = this->indexOf(s);
	if(index==-1){
		return NOT_FOUND;
	}

	if(songs->s == s){
		SongNode* next = songs->next;
		delete songs;
		songs = next;
		return SUCCESS;
	}

	SongNode* prevNode = this->get(index-1);
	SongNode* currentNode = prevNode->next;
	SongNode* nextNode = currentNode->next;

	delete currentNode;
	prevNode->next = nextNode;

	return SUCCESS;
}

int UtPod::length(){
	int length = 0;
	UtPod::SongNode* currentNode = this->songs;
	while(currentNode != NULL) {
		currentNode = currentNode->next;
		length++;
	}
	return length;
}

int UtPod::memCurrentlyTaken(){
	int size = 0;
	UtPod::SongNode* currentNode = this->songs;
	while(currentNode != NULL) {
		size += currentNode->s.getSize();
		currentNode = currentNode->next;
	}
	return size;
}

int UtPod::indexOf(const Song& song){
	int index = 0;
	UtPod::SongNode* currentNode = this->songs;
	while(currentNode != NULL) {
		if(currentNode->s == song){
			return index;
		}
		currentNode = currentNode->next;
		index++;
	}
	return -1;
}

UtPod::SongNode* UtPod::get(int index){
	int i = 0;
	UtPod::SongNode* currentNode = this->songs;
	while(currentNode != NULL) {
		if(i==index){
			return currentNode;
		}
		currentNode = currentNode->next;
		i++;
	}
	return NULL;
}

void UtPod::swap(int index1, int index2){
	if(index1 == index2){
		return;
	}
	if(index2 < index1){
		int temp = index1;
		index1 = index2;
		index2 = temp;
	}
	int length = this->length();


	if(index2 >= length || index1 <0){
		std::cout << "Invalid input for replace, indices: " << index1 <<","<<index2 << std::endl;
		return;
	}

	SongNode* node1 = this->get(index1);
	SongNode* node2 = this->get(index2);

	Song songTemp = node1->s;
	node1->s = node2->s;
	node2->s = songTemp;

}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
		o will do nothing if there are less than two songs in the current list

	 input parms -

	 output parms -
*/

void UtPod::shuffle(){
	int length = this->length();

	for(int i=0; i <length;i++){
		int j = rand() % length;
		if(i!=j){
			this->swap(i,j);
		}
	}
}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

	 input parms -

	 output parms -
*/

void UtPod::showSongList(){
	SongNode* currentNode = songs;
	while(currentNode != NULL){
		std::cout << (currentNode->s) << std::endl;
		currentNode = currentNode->next;
	}
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
		o will do nothing if there are less than two songs in the current list

	 input parms -

	 output parms -
*/

void UtPod::sortSongList(){
	int length = this->length();
	for(int i=0; i <length;i++){
		for(int j=0; j<length-1;j++){
			SongNode* node1 = this->get(j);
			SongNode* node2 = this->get(j+1);
			if((node1->s) > (node2->s)){
				this->swap(j,j+1);
			}
		}
	}
}
void UtPod::sortSongListReverse(){
	int length = this->length();
	for(int i=0; i <length;i++){
		for(int j=0; j<length-1;j++){
			SongNode* node1 = this->get(j);
			SongNode* node2 = this->get(j+1);
			if((node1->s) < (node2->s)){
				this->swap(j,j+1);
			}
		}
	}
}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

	 input parms -

	 output parms -
*/
void UtPod::clearMemory(){
	SongNode *currentNode = songs;
	while(currentNode != NULL){
		SongNode *thisNode = currentNode;
		currentNode = currentNode->next;
		delete thisNode;
	}
	songs = NULL;
}



/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

	 input parms -

	 output parms -
*/

int UtPod::getRemainingMemory(){
	return podMemSize-this->memCurrentlyTaken();
}
