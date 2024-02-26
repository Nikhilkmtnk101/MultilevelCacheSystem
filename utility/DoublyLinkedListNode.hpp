#ifndef DoublyLinkedListNode_hpp
#define DoublyLinkedListNode_hpp
#include <bits/stdc++.h>

class Node{
public:
    string data;
    Node *left, *right;

    explicit Node(string data){
        this->data = data;
        left = right = nullptr;
    }
};
#endif