#include "linkedlist.h"
#include <vector>
#include <iostream>
using namespace std;

void linkedlist::add(int num, vector<linkedlist> &pointers, int value) {
    // Add to front of Linked List
    ListNode* temp = new ListNode;
    temp->fileNum = num;
    temp->next = pointers[value].head;
    pointers[value].head = temp;
}

linkedlist::linkedlist() {
    head = nullptr;
}

void linkedlist::addToArray(vector<vector<int> > &a, int value, vector<linkedlist> &pointers) {
    // Gets all combination of files at a specific value
    ListNode *headpt = pointers[value].head;
    ListNode *temp;
    // Outer Loop
    while(headpt != nullptr){
        temp = headpt->next;
        // Inner Loop
        while(temp != nullptr){
            // add to 2d array
            a[headpt->fileNum][temp->fileNum] = a[headpt->fileNum][temp->fileNum] + 1;
            temp = temp->next;
        }
        headpt = headpt->next;
    }
}

void linkedlist::addToHashTable(int value, int fileNum, vector<linkedlist> &pointers) {
    ListNode *temp = pointers[value].head;
    // if not other fileNums at value
    if(temp == nullptr){
        add(fileNum, pointers, value);
    }
    // make sure fileNum not already in linked list
    else if(fileNum != temp->fileNum) {
        add(fileNum, pointers, value);
    }
    // else return
}

linkedlist::~linkedlist() {
    while(head != nullptr){
        ListNode *temp = head;
        head = head -> next;
        delete temp;
    }
}


