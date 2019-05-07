//
//  HashTable.h
//  Assignment 8 - Cheaters!
//
//  Created by Akarsh Kumar on 5/5/19.
//  Copyright © 2019 Akarsh Kumar. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <tuple>
#include "LinkedList.h"
#include "PlagiarismCatcher.h"

//#include <cstdlib>

using namespace std;

class PlagiarismCatcher;


class HashTable {
private:
    
    int numBuckets;
    LinkedList<std::tuple<int,int>> * table;
    
    
    static int hashFunc(string str){
        int hash = 0;
        for(int i=0; i < (int)str.length();i++){
            hash += (str[i]<<i);
        }
        return hash;
    }
    static int indexOf(string str, int numBuckets){
        return (abs(hashFunc(str)))%numBuckets;
    }
    
public:
    HashTable(int numBuckets){
        this->numBuckets = numBuckets;
        table = new LinkedList<std::tuple<int,int>>[numBuckets];
    }
    ~HashTable(){
        delete[] table;
    }
    
    void put(string key, int fileID, int chunkLocation){
        int index = indexOf(key, numBuckets);
        table[index].add(make_tuple(fileID, chunkLocation));
    }
    
    LinkedList<std::tuple<int,int>>* get(string key){
        int index = indexOf(key, numBuckets);
        return &table[index];
    }
    
    
    
};


#endif /* HashTable_h */
