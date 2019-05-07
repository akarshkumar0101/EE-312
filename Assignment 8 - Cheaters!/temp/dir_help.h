
#ifndef DIR_HELP_H
#define DIR_HELP_H

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

static int getdir(string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        string filename = string(dirp->d_name);
        if(filename!= "." && filename!=".."){
            files.push_back(filename);
        }
    }
    closedir(dp);
    return 0;
}

vector<string> filesInDirectory(string dir)
{
    vector<string> files = vector<string>();
    getdir(dir, files);
    return files;
}


#endif
