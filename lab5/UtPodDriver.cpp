//
// Created by simon on 3/30/2020.
//

/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {

    UtPod t;
    cout << "t: remaining memory = " << t.getRemainingMemory() << endl;
    cout << "t: total memory = " << t.getTotalMemory() << endl;
    UtPod s(200); // Sets size to 200
    cout << "s: remaining memory = " << s.getRemainingMemory() << endl;
    cout << "s: total memory = " << s.getTotalMemory() << endl;
    UtPod u(600); // Sets size to 600
    cout << "u: remaining memory = " << u.getRemainingMemory() << endl;
    cout << "u: total memory = " << u.getTotalMemory() << endl;
    UtPod v(0); // Sets size to 600
    cout << "v: remaining memory = " << v.getRemainingMemory() << endl;
    cout << "v: total memory = " << v.getTotalMemory() << endl;

    cout << "\nTesting t: " << endl;

    cout << "Songs in empty UtPod t:" << endl;
    t.sortSongList(); // Sort 1 element list
    t.showSongList();
    cout << "Songs in empty UtPod t:" << endl;
    t.shuffle(); // Shuffle 1 element list
    t.showSongList();

    Song s1("ABBA", "Waterloo", 8);
    int result = t.removeSong(s1); // Removes a song from empty list, should fail
    cout << "delete song from empty pod result = " << result << endl;
    result = t.addSong(s1);
    cout << "add result success = " << result << endl;

    cout << "\nSorted Songs in UtPod t with 1 song:" << endl;
    t.sortSongList(); // Sort 1 element list
    t.showSongList();
    cout << "\nShuffled Songs in UtPod t with 1 song:" << endl;
    t.shuffle(); // Shuffle 1 element list
    t.showSongList();

    Song s2("Big Bird", "abcdefghijklmnopqrstuvwxyz", 26);
    result = t.addSong(s2);
    cout << "\nadd result = " << result << endl;

    cout << "\nSongs in UtPod t with 2 song:" << endl;
    t.showSongList();

    Song s3("Ginuwine", "Pony", 101);
    result = t.addSong(s3);
    cout << "\nadd result = " << result << endl;

    Song s4("Roddy Rich", "The Box", 98);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Carrie Underwood", "Two Black Cadillacs", 239);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("Big Bird", "abcdefghijklmnopqrstuvwxyz", 10); // Same song, different size
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("Carrie Underwood", "Church Bells", 30); // Same artist, different title
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    cout << "t: remaining memory = " << t.getRemainingMemory() << endl; // Should Print 0

    cout << "\nSongs in UtPod t:" << endl;
    t.showSongList();
    cout << "\nSorted Songs in UtPod t:" << endl;
    t.sortSongList(); // Sort
    t.showSongList();
    cout << "\nShuffled Songs in UtPod t:" << endl;
    t.shuffle(); // Shuffle
    t.showSongList();

    Song s8("Don Mclean", "American Pie (Full Length Version)", 300);
    result = t.addSong(s8);
    cout << "no memory add result = " << result << endl; // Add should fail, not enough remaining memory

    Song s9("FunnyBear", "Gummy Bear", 30);
    result = t.removeSong(s9); // Song isn't in list, should fail
    cout << "\nnonexistant song delete result = " << result << endl;

    Song s10("Big Bird", "abcdefghijklmnopqrstuvwxyz", 10); // Different variable, song in list, success
    result = t.removeSong(s10);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    cout << "\nSongs in UtPod t:" << endl;
    t.showSongList();
    t.clearMemory(); // check clear
    cout << "\nList After Clearing Memory" << endl;
    t.showSongList();
    cout << "EndList After Clearing Memory" << endl;

    result = t.addSong(s1);
    cout << "\nadd result = " << result << endl;
    result = t.addSong(s1);
    cout << "add same song result = " << result << endl;
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s1);
    cout << "delete same song result = " << result << endl;

    cout << "Done testing UtPod t" << endl << endl;

    // u:
    // Test if remove works for  a list with one song
    // Test if remove works for first song and last song in a list
    // Test all song constructors

    cout << "Testing u:" << endl;

    result = u.addSong(s3);
    cout << "\nadd result = " << result << endl;

    cout << "\nSongs in UtPod: " << endl;
    u.showSongList();

    result = u.removeSong(s3);
    cout << "delete only song result = " << result << endl;

    cout << "\nSongs in UtPod: " << endl;
    u.showSongList();

    Song s11;
    s11.setArtist("Lizzo");
    s11.setTitle("Juice");
    s11.setSize(40);
    result = u.addSong(s11);
    cout << "\nadd result = " << result << endl;

    Song s12("Lizzo", "Good as Hell");
    s12.setSize(35);
    result = u.addSong(s12);
    cout << "add result = " << result << endl;

    result = u.addSong(s3);
    cout << "add result = " << result << endl;

    result = u.addSong(s5);
    cout << "add result = " << result << endl;

    cout << "\nSongs in UtPod: " << endl;
    u.showSongList();

    result = u.removeSong(s11);
    cout << "\nremove last song result = " << result << endl;

    result = u.removeSong(s5);
    cout << "remove first song result = " << result << endl;

    cout << "\nSongs in UtPod: " << endl;
    u.showSongList();

    cout << "\nSongs in UtPod: " << endl;
    cout << "End of testing UtPod u" << endl << endl;

    // s: Exceed 200 size limit
    // Continue adding all the same songs (size 3) using a while loop
    // Sort the song list
    // Get non-zero remaining memory

    Song s13("Crazy Frog", "Axel F", 3);
    cout << "Testing UtPod s: " << endl;
    while(s.addSong(s13) == 0);

    cout << "\nSongs in UtPod: " << endl;
    s.showSongList();

    s.sortSongList();
    cout << "\nSorted Songs in UtPod: " << endl;
    s.showSongList();

    cout << "\ns: remaining memory = " << s.getRemainingMemory() << endl;
    cout << "s: total memory = " << s.getTotalMemory() << endl;

    while(s.removeSong(s12) == 0);

    cout << "\nSongs remaining: " << endl;
    s.showSongList();

    cout << "\nDone with testing UtPod s" << endl;
    
    // Don't clear memory for UtPods U and V to make sure destructor works

}