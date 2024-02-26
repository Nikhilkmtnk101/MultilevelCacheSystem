#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp
#include "DoublyLinkedListNode.hpp"

class DoublyLinkedList {
public:
    Node *start, *end;
    DoublyLinkedList(){
        this->start= this->end= nullptr;
    }

    void add_front(string data){
        Node *node = new Node(data);
        if(this->start == nullptr){
            this->start= this->end = node;
        }
        this->start->right = node;
        this->start = node;
    }

    void add_back(string data){
        Node *node = new Node(data);
        if(this->start == nullptr){
            this->start= this->end = node;
        }
        this->end->right = node;
        this->end = node;
    }

    void remove_node(Node *node){
        // Handle the case when list have only one node
        if(this->start==this->end){
            Node* temp_node = this->start;
            this->start= this->end= nullptr;
            delete temp_node;
            return;
        }
        Node *left_node = node->left;
        Node *right_node = node->right;

        if(node==this->start){
            this->start = right_node;
        }

        if(node==this->end){
            this->end = left_node;
        }

        if(left_node!= nullptr){
            left_node->right = right_node;
        }

        if(right_node != nullptr){
            right_node->left = left_node;
        }

        delete node;

    }
};
#endif
