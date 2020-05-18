#include <iostream>
#include "linkedlist.h"
#include <string>
#include <dirent.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <stdlib.h>


#include <sys/types.h>

using namespace std;

struct fileCollision {
    string fileNameA;
    string fileNameB;
    int numCollision;
};

void sortCheaters(vector<fileCollision> &collisions);   //sort most similar files to least similar files

int getFileNames(string dir, vector<string> &fileNames);//gets files from directory

int generateValue(vector<string> key);  //generates the Key for the hash table given the n-word chunk

void
countCheaters(vector<fileCollision> &collisions, int n, int threshold, vector<vector<int> > &a, vector<string> fileNames,
              int filesSize);
//traverses 2D array to count number of files which number of similar n-word sequences is above threshold


int main(int argc, char *argv[]) {
    const int HASH_SIZE = 100000;   //Size of Hash Table

    int n = atoi(argv[2]);  //Gets n-word criteria
    int threshold = atoi(argv[3]);
    string dir = argv[1];

    vector<string> files = vector<string>();
    getFileNames(dir, files);   //gets name files from directory
    files.erase(files.begin(), files.begin() + 2);

    int filesSize = files.size();
    vector<vector<int> > a;
    a.resize(filesSize, vector<int>(filesSize, 0)); //creates a 2D vector

    vector<linkedlist> arr; //creates vector Hash Table
    arr.resize(HASH_SIZE);

    // loop through file (on slide with drawing) and generate key
    for (int k = 0; k < filesSize; k++) {
        ifstream inFile;
        string file = dir + files[k];
        const char *filearr = file.c_str();
        inFile.open(filearr);
        bool firstTime = true;
        string s;   //used for getting words from file
        vector<string> chunk;

        while (inFile) {
            if (firstTime) {    //get first full n-word chunk once
                for (int i = 0; i < n; i++) {   //removes all punctuation, white spaces, and capital letters
                    inFile >> s;
                    string result = "";
                    for (int i = 0; i < s.size(); i++) {
                        if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
                            result += s.at(i) + 32;
                        } // check if uppercase, make
                        else if (s.at(i) >= 'a' && s.at(i) <= 'z') {
                            result += s.at(i);
                        }
                    }
                    chunk.push_back(result);
                }
                firstTime = false;
            } else {    //removes first word in vector, adds next word from file to end of vector
                chunk.erase(chunk.begin());
                inFile >> s;
                string result = "";
                for (int i = 0; i < s.size(); i++) {
                    if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
                        result += s.at(i) + 32;
                    } // check if uppercase, make
                    else if (s.at(i) >= 'a' && s.at(i) <= 'z') {
                        result += s.at(i);
                    }
                }
                chunk.push_back(result);
            }
            int value = generateValue(chunk);   //passes n-word chunk to generate key for Hash Table
            arr[k].addToHashTable(value, k, arr);   //add file number at hash table value
        }
    }

    vector<fileCollision> collisions;

    // create 2D array by looping through hash table
    for (int i = 0; i < HASH_SIZE; i++) {
        arr[i].addToArray(a, i, arr);
    }

    // create array of structs with # of collisions > threshold
    countCheaters(collisions, n, threshold, a, files, filesSize);

    // sort array from greatest to least
    sortCheaters(collisions);

    // print based on format iven
    for (int i = 0; i < collisions.size(); i++) {
        cout << collisions[i].numCollision << ": " << collisions[i].fileNameA << ", " << collisions[i].fileNameB
             << endl;
    }

    return 0;
}

// Get vector of file names from a directory. Code provided by Dr. Priebe
int getFileNames(string dir, vector<string> &fileNames) {
    DIR *dp;
    struct dirent *dirp;
    if ((dp = opendir(dir.c_str())) == NULL) {
        cout << "Error in opening file" << endl;
        return -1;
    }

    while ((dirp = readdir(dp)) != NULL) {
        fileNames.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

// Looping in reverse through the chunk of 6 words, for each letter
// sum =+ ascii * 37 ^ count
// where count counts the # of letters
int generateValue(vector<string> key) {
    const int HASH_SIZE = 100000;
    int count = 0;
    int sum = 0;
    for (int i = key.size() - 1; i >= 0; i--) {
        for (int j = key[i].length() - 1; j >= 0; j--) {
            int ch = key[i].at(j);
            sum += ch * pow(37, i);
            count++;
        }
    }
    // mod by hash table size
    return abs(sum % HASH_SIZE);
}


void countCheaters(vector<fileCollision> &collisions, int n, int threshold, vector<vector<int> > &a, vector<string> fileNames,
              int filesSize) {
    fileCollision collide;
    // traverse 2D array
    for (int i = 0; i < filesSize - 1; i++) {
        for (int j = i + 1; j < filesSize; j++) {
            // if greater than threshold, add to collisions
            int numCollisions = a[i][j] + a[j][i];
            if (numCollisions > threshold) {
                collide.fileNameA = fileNames[i];
                collide.fileNameB = fileNames[j];
                collide.numCollision = numCollisions;
                collisions.push_back(collide);
            }
        }
    }
}

void sortCheaters(vector<fileCollision> &collisions) {
    fileCollision temp;
    // selection sort
    for (int i = 0; i < collisions.size(); i++) {
        int data = 0;
        int tempIndex = 0;
        for (int j = i; j < collisions.size(); j++) {
            if (collisions[j].numCollision > data) {
                data = collisions[j].numCollision;
                tempIndex = j;
            }
        }
        temp = collisions[tempIndex];
        collisions[tempIndex] = collisions[i];
        collisions[i] = temp;
    }
}




















