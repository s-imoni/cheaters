#include <vector>
using namespace std;
#ifndef CHEATERS_LINKEDLIST_H
#define CHEATERS_LINKEDLIST_H

class linkedlist {
private:

    // List Node
    struct ListNode
    {
        int fileNum;
        ListNode *next;
    };

    ListNode *head; // head pointer

public:

    linkedlist();

    // add to linked list
    void add(int num, vector<linkedlist> &pointers, int fileNum);

    // adds to 2D array from Hash Table
    void addToArray(vector<vector<int> > &a, int value, vector<linkedlist> &pointers);

    // adds file num to value on Hash Table
    void addToHashTable(int value, int fileNum, vector<linkedlist> &pointers);

    ~linkedlist();
};




#endif //CHEATERS_LINKEDLIST_H
