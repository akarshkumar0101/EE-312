//
//  main.cpp
//  Assignment 8 - Cheaters!
//
//  Created by Akarsh Kumar on 5/4/19.
//  Copyright © 2019 Akarsh Kumar. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include "PlagiarismCatcher.h"

#include "dir_help.h"


using namespace std;


vector<string> fileNames;
vector<vector<string>> fileContents;




void insertSorted(vector<tuple<int,int,int>>& plagarisms, int file1, int file2, int collisions){
    tuple<int,int,int> tup = make_tuple(file1, file2, collisions);
    
    for(vector<tuple<int,int,int>>::iterator it = plagarisms.begin(); it!=plagarisms.end();it++){
        if(get<2>(*(it))<=collisions){
            plagarisms.insert(it, tup);
            return;
        }
    }
    
    plagarisms.push_back(tup);
}

int main(int argc, const char * argv[]) {
    if(argc<4){
        std::cout<<"Need more command line arguments: path n threshold"<<std::endl;
        return 0;
    }
    string directoryOfFiles = argv[1];
    
    int n = stoi(argv[2]);
    int threshold = stoi(argv[3]);
    
    PlagiarismCatcher catcher(directoryOfFiles, n);
    catcher.calculateEveryFile();
    
    vector<std::tuple<int,int,int>> plagarisms;
    
    for(int x=0; x <(int)catcher.fileNames.size();x++){
        for(int y=x+1; y <(int)catcher.fileNames.size();y++){
            int coll = catcher.calculatePlagarism(x, y);
            if(coll>threshold){
                insertSorted(plagarisms, x, y, coll);
            }
            //cout<<setw(6)<<coll;
        }
        cout<<((float)x/(int)catcher.fileNames.size())*100<<"% done."<<endl;
    }
    
    for(vector<std::tuple<int,int,int>>::iterator it = plagarisms.begin(); it!=plagarisms.end();it++){
        int file1 = get<0>(*it);
        int file2 = get<1>(*it);
        int collisions = get<2>(*it);
        cout<<collisions<<": "<<catcher.fileNames.at(file1) <<", " <<catcher.fileNames.at(file2) <<endl;
        
        
    }
    
    return 0;
}



/*

 hal10.txt and catchmeifyoucan.txt 311
 bef1121.txt and edo14.txt 423
 sra31.txt and jrf1109.txt 1662
 ecu201.txt and catchmeifyoucan.txt 290
 tyc12.txt and catchmeifyoucan.txt 384
 edo26.txt and abf0704.txt 678
 abf0704.txt and abf70402.txt 531
 
 */

