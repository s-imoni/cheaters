//
// Created by simon on 3/30/2020.
//

#ifndef LAB5_SONG_H
#define LAB5_SONG_H

using namespace std;
#include <string>

class Song {
    private:
        string title;
        string artist;
        int size;

        static const int MAX_SIZE = 512;
        static const int MIN_SIZE = 0;

    public:
        Song();
        Song(string artist, string title);
        Song(string artist, string title, int size);

        string getTitle() const;
        string getArtist() const;
        int getSize() const;

        void setTitle(string title);
        void setArtist(string artist);
        void setSize(int size);

        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);

        ~Song();
};


#endif //LAB5_SONG_H
