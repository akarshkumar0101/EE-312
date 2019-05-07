//
//  PlagiarismCatcher.h
//  Assignment 8 - Cheaters!
//
//  Created by Akarsh Kumar on 5/5/19.
//  Copyright © 2019 Akarsh Kumar. All rights reserved.
//

#ifndef PlagiarismCatcher_h
#define PlagiarismCatcher_h

#include <vector>
#include <tuple>

#include "dir_help.h"
#include "HashTable.h"



string cleanWord(string input){
    string clean = "";
    
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    
    for(int i=0; i < (int)input.length();i++){
        char c = input[i];
        
        if(c>='a'&&c<='z'){
            clean += c;
        }
    }
    
    
    return clean;
}

/*

int manualNumCollisions(int x, int y, int n){
    int collisions = 0;
    
    vector<string>& file1Content = fileContents[x];
    vector<string>& file2Content = fileContents[y];
    
    for(int i1 = 0; i1<file1Content.size()-n; i1++){
        for(int i2 = 0; i2<file2Content.size()-n; i2++){
            bool isEqual = true;
            
            for(int i=0; i < n;i++){
                //cout<< file1Content.at(i1+i)<<" "<<file2Content.at(i2+i)<<endl;
                if(file1Content.at(i1+i)!=file2Content.at(i2+i)){
                    isEqual = false;
                    break;
                }
            }
            
            if(isEqual){
                collisions++;
            }
        }
    }
    
    return collisions;
}
void manualCheck(int n){
    int collisions[fileContents.size()][fileContents.size()];
    
    for(int y=0; y<fileContents.size();y++){
        for(int x=0; x<fileContents.size();x++){
            collisions[y][x] = 0;
        }
    }
    for(int y=0; y<fileContents.size();y++){
        for(int x=y+1; x<fileContents.size();x++){
            collisions[x][y] = manualNumCollisions(y, x, n);
            cout<<x<< " ";
        }
        cout<<endl;
    }
    
    
    for(int y=0; y<fileContents.size();y++){
        for(int x=0; x<fileContents.size();x++){
            if(collisions[x][y]>200){
                cout<<fileNames.at(y)<< " and " << fileNames.at(x)<< " "<< collisions[x][y] <<endl;
            }
            //cout<<setw(6)<<collisions[x][y];
        }
        //cout<<endl;
    }
}

*/

class PlagiarismCatcher{
public:
    int n;
    int threshold;
    
    vector<string> fileNames;
    vector<vector<string>*> fileContents;
    
    HashTable* hashTable;
    
    bool isEqual(string str, int fileID, int wordLocation){
        string found = "";
        
        for(int i=0; i <n;i++){
            if(wordLocation+i >= (int)fileContents.at(fileID)->size()){
                return false;
            }
            found+=fileContents.at(fileID)->at(wordLocation+i);
        }
        return str == found;
    }
    
public:
    PlagiarismCatcher(string directoryOfFiles, int n){
        this->n = n;
        if(*(directoryOfFiles.end()-1) != '/' || *(directoryOfFiles.end()-1)!= '\\'){
            directoryOfFiles += '/';
        }
        
        fileNames = filesInDirectory(directoryOfFiles);
        
        
        int numWords =0;
        for(vector<string>::iterator it = fileNames.begin(); it!=fileNames.end();it++){
            ifstream file;
            file.open(directoryOfFiles+ *it);
            
            char output[10000];
            vector<string>* words = new vector<string>;
            if (file.is_open()) {
                while (!file.eof()) {
                    file >> output;
                    string word = output;
                    word = cleanWord(word);
                    
                    words->push_back(word);
                }
                cout<<"Successly opened "<<*it<<", has "<<words->size()<<" words in it."<<endl;
                
                fileContents.push_back(words);
                
                
                numWords+=words->size();
                
            }
            else{
                cout<<"COULD NOT OPEN FILE: "<< *it<<endl;
            }
            
            file.close();
        }
        
        hashTable = new HashTable(numWords/2);
        
    }
    
    
    
    void calculateFile(int fileID){
        vector<string>*& content = fileContents.at(fileID);
        for(int i=0; i <(int)content->size()-n;i++){
            string str = "";
            for(int x=0;x<n;x++){
                str+=content->at(i+x);
            }
            hashTable->put(str, fileID, i);
        }
    }
    void calculateEveryFile(){
        for(int fileID =0; fileID<(int)fileNames.size();fileID++){
            calculateFile(fileID);
        }
    }
    
    int calculatePlagarism(int file1ID, int file2ID){
        int collisions = 0;
        
        vector<string>*& content1 = fileContents.at(file1ID);
        for(int i=0; i <(int)content1->size()-n;i++){
            string str = "";
            for(int x=0;x<n;x++){
                str+=content1->at(i+x);
            }
            LinkedList<std::tuple<int,int>>* list = hashTable->get(str);
            for(int hit=0; hit < (int)list->size();hit++){
                
                if(get<0>(list->get(hit))==file2ID){
                    collisions++;
                    break;
                }
                 
            }
        }
        
        
        return collisions;
    }
    
};


#endif /* PlagiarismCatcher_h */
