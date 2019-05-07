
The following files are needed to compile plagiarismCatcher:
 - main.cpp
 - PlagiarismCatcher.h
 - dir_help.h
 - LinkedList.h
 - HashTable.h
 - makefile


To compile this project, simply have all of these files in the same folder and run "make" on the command line.

To actually run, type "./plagiarismCatcher [directory of text files] [integer length of sequences to search for] [the collision threshold]"
ex: ./plagiarismCatcher sm_doc_set/ 6 200


The way the program works is by first reading all the files and storing the words of a file in a vector of strings (words).
It then hashes each 6 word sequence of all the files into a hashtable that maps the key sequence to a value of location(where to locate this sequence, which file and what location).
Then to calculate the collisions between two files, it goes through the first file and and goes through each 6 word sequence and finds if some other file has the same sequence based on looking at the hashtable and seeing if the location of the found file is the second file.

