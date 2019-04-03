/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Song.h"
#include "UtPod.h"

using namespace std;


void testSong(){
	cout<<"TESTING SONG CLASS"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------"<<endl;
	string artist = "Toto";
	string title = "Africa";
	int size = 8;
	cout<<"Song being created with artist: "<<artist<<" and title: "<<title << " and size: "<<size<<" MB" <<endl;
	Song s(artist,title,size);
	cout<<"Song created: ";
	cout<<s<<endl;

	cout<<"\n\n"<<endl;

	artist = "";
	title = "Africa";
	size = 8;
	cout<<"Song being created with artist: "<<artist<<" and title: "<<title << " and size: "<<size<<" MB" <<endl;
	Song sa(artist,title,size);
	cout<<"Song created: ";
	cout<<sa<<endl;

	cout<<"\n\n"<<endl;

	artist = "Toto";
	title = "";
	size = 8;
	cout<<"Song being created with artist: "<<artist<<" and title: "<<title << " and size: "<<size<<" MB" <<endl;
	Song sb(artist,title,size);
	cout<<"Song created: ";
	cout<<sb<<endl;

	cout<<"\n\n"<<endl;

	artist = "Toto";
	title = "Africa";
	size = -10;
	cout<<"Song being created with artist: "<<artist<<" and title: "<<title << " and size: "<<size<<" MB" <<endl;
	Song sc(artist,title,size);
	cout<<"Song created: ";
	cout<<sc<<endl;

	cout<<"\n\n"<<endl;

	Song s1("Toto","Africa",8);
	Song s2("Zoto","Africa",8);
	Song s3("Toto","Zfrica",8);
	Song s4("Toto","Africa",16);
	Song s5("Toto","Africa",8);
	cout<<"Created 5 songs for testing comparison of songs: "<<endl;
	cout<<"s1: "<<s1<<endl;
	cout<<"s2: "<<s2<<endl;
	cout<<"s3: "<<s3<<endl;
	cout<<"s4: "<<s4<<endl;
	cout<<"s5: "<<s5<<endl;

	cout<<"\n\n"<<endl;

	cout<<"s1 > s2: "<<(s1 > s2)<<endl;
	cout<<"s1 < s2: "<<(s1 < s2)<<endl;

	cout<<"s1 > s3: "<<(s1 > s3)<<endl;
	cout<<"s1 < s3: "<<(s1 < s3)<<endl;

	cout<<"s1 > s4: "<<(s1 > s4)<<endl;
	cout<<"s1 < s4: "<<(s1 < s4)<<endl;

	cout<<"s1 == s2: "<<(s1 == s2)<<endl;
	cout<<"s1 == s5: "<<(s1 == s5)<<endl;


	cout<<"---------------------------------------------------------------------------------------------------"<<endl;

}


string appendToString(string str, int i){
	stringstream ss;
	ss << str;
	ss << i;
	return ss.str();
}
void add25Songs(UtPod& pod){
	for(int i=1; i <=25;i++){

		string artist = appendToString("artist",i);
		string title = appendToString("song",i);
		int size = i;
		Song s(artist,title,size);
		pod.addSong(s);
	}
}
void removeEvenSongs(UtPod& pod){
	for(int i=2; i <=25;i+=2){
		string artist = appendToString("artist",i);
		string title = appendToString("song",i);
		int size = i;
		Song s(artist,title,size);
		pod.removeSong(s);
	}
}

void testUtPod(){
	cout<<"TESTING UTPOD CLASS"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------"<<endl;

	cout<<"Creating pod with 256 MB of memory";
	UtPod pod(256);
	cout<<"Pod created!"<<endl;

	cout<<"\n\n\n";
	cout<<"Total memory in pod: ";
	cout<<pod.getTotalMemory()<<" MB"<<endl;


	cout<<"\n\n\n";
	cout<<"Adding 25 songs";
	cout<<"\n\n\n";

	add25Songs(pod);
	pod.showSongList();

	cout<<"\n\n\n";
	cout<<"Remaining memory in pod: ";
	cout<<pod.getRemainingMemory()<<" MB"<<endl;


	cout<<"\n\n\n";
	cout<<"Suffling";
	cout<<"\n\n\n";

	pod.shuffle();
	pod.showSongList();

	cout<<"\n\n\n";
	cout<<"Sorting pod";
	cout<<"\n\n\n";

	pod.sortSongList();
	pod.showSongList();

	cout<<"\n\n\n";
	cout<<"Sorting pod reverse";
	cout<<"\n\n\n";

	pod.sortSongListReverse();
	pod.showSongList();

	cout<<"\n\n\n";
	cout<<"Removing even songs";
	cout<<"\n\n\n";

	removeEvenSongs(pod);
	pod.showSongList();

	cout<<"\n\n\n";
	cout<<"Remaining memory in pod: ";
	cout<<pod.getRemainingMemory()<<" MB"<<endl;

	cout<<"\n\n\n";
	cout<<"Clearing pod's memory";

	pod.clearMemory();
	pod.showSongList();

	cout<<"\n\n\n";
	cout<<"Remaining memory in pod: ";
	cout<<pod.getRemainingMemory()<<" MB"<<endl;



	cout<<"---------------------------------------------------------------------------------------------------"<<endl;

}

void instructorGivenTest(){
	cout<<"DEFAULT TESTS GIVEN BY PRIEBE"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------"<<endl;
	
	UtPod t;
	
	Song s1("Beatles", "Hey Jude1", 4);
	int result = t.addSong(s1);
	cout << "result = " << result << endl;
	
	t.showSongList();
		  
	Song s2("Beatles", "Hey Jude2", 5);
	result = t.addSong(s2);
	cout << "result = " << result << endl;
	
	t.showSongList();

	Song s3("Beatles", "Hey Jude3", 6);
	result = t.addSong(s3);
	cout << "result = " << result << endl;

	Song s4("Beatles", "Hey Jude4", 7);
	result = t.addSong(s4);
	cout << "result = " << result << endl;

	Song s5("Beatles", "Hey Jude5", 241);
	result = t.addSong(s5);
	cout << "add result = " << result << endl;
	
	t.showSongList();
	t.shuffle();

	cout<< endl;
	t.showSongList();
	
	t.sortSongList();
	//t.swap(0,1);
	cout<< endl;
	t.showSongList();
	
	result = t.removeSong(s2);
	cout << "delete result = " << result << endl;
  
	result = t.removeSong(s3);
	cout << "delete result = " << result << endl;

	t.showSongList();
	
	result = t.removeSong(s1);
	cout << "delete result = " << result << endl;
 
	result = t.removeSong(s5);
	cout << "delete result = " << result << endl;
	
	result = t.removeSong(s4);
	cout << "delete result = " << result << endl;
	
	
	t.showSongList();
	
	result = t.addSong(s5);
	cout << "add result = " << result << endl;
	
	t.showSongList();
	cout << "memory = " << t.getRemainingMemory() << endl;
	cout<<"---------------------------------------------------------------------------------------------------"<<endl;
}
int main(int argc, char *argv[])
{   
	srand(time(NULL));

	testSong();
	testUtPod();
	instructorGivenTest();


}
