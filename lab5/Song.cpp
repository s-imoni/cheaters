//
// Created by simon on 3/30/2020.
//

#include "Song.h"

using namespace std;
//Made three constructors for different input parameters
Song::Song() {
    this->artist = "";
    this->title = "";
    this->size = 0;
}

Song::Song(string artist, string title) {
    this->artist = artist;
    this->title = title;
    this->size = 0;
}

Song::Song(string artist, string title, int size) {
    this->artist = artist;
    this->title = title;
    this->size = size;
}

void Song::setTitle(string title) {
    this->title = title ;
}

void Song::setArtist(string artist) {
    this->artist = artist;
}

void Song::setSize(int size) {
    this->size = size;
}

// Checks by artist, then title, then size.
bool Song::operator>(Song const &rhs) {
    bool ret = false;
    if (artist.compare(rhs.artist) > 0){
        ret = true;
    }
    if (title.compare(rhs.title) > 0 && artist.compare(rhs.artist) == 0){
        ret = true;
    }
    if (size > rhs.size && artist.compare(rhs.artist) == 0 && title.compare(rhs.title) == 0){
        ret = true;
    }
    return ret;
}

// Checks by artist, then title, then size.
bool Song::operator<(Song const &rhs) {
    if (artist.compare(rhs.artist) < 0){ //if title1 is smaller than title2
        return true;
    }
    if (title.compare(rhs.title) < 0 && artist.compare(rhs.artist) == 0){
        return true;
    }
    if (size < rhs.size && artist.compare(rhs.artist) == 0 && title.compare(rhs.title) == 0){
        return true;
    }
    return false;
}
bool Song::operator==(Song const &rhs) {
    return (title == rhs.title) &&
           (artist == rhs.artist) &&
           (size == rhs.size);
}

Song::~Song() {
}

string Song::getTitle() const {
    return title;
}

string Song::getArtist() const {
    return artist;
}

int Song::getSize() const {
    return size;
}
