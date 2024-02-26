#ifndef LRUEvictionPolicy_hpp
#define LRUEvictionPolicy_hpp
#include "bits/stdc++.h"
#include "DoublyLinkedList.hpp"
#include "EvictionPolicy.hpp"

class LRUEvictionPolicy: public EvictionPolicy{
private:
    map<string , Node*> *mp;
    DoublyLinkedList *dll;

public:
    LRUEvictionPolicy(){
        this->mp = new map<string , Node*> ();
        this->dll = new DoublyLinkedList();
    }

    void key_accessed(const string& key) override{
        Node * node = (*this->mp)[key];
        if (node!= nullptr){
            this->dll->remove_node(node);
        }
        this->dll->add_front(key);
        (*this->mp)[key]= this->dll->start;
    }

    string evict() override {
        Node * end = this->dll->end;
        string key = end->data;
        this->dll->remove_node(end);
        this->mp->erase(key);
        return key;
    }
};
#endif