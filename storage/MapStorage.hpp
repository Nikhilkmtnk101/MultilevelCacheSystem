#ifndef MapStorage_hpp
#define MapStorage_hpp

#include "bits/stdc++.h"
#include "Storage.hpp"
#include "Exceptions.hpp"

class MapStorage: public Storage{
private:
    unordered_map<string , string > *storage;
    int capacity;

public:
    explicit MapStorage(int capacity=0){
        this->capacity=capacity;
        this->storage = new unordered_map<string , string >();
    }

    void add(string key, string value) override{
        if(this->storage->size()== this->capacity){
           throw StorageFullException();
        }
        (*this->storage)[key]=value;
    }

    string get(string key) override{
        if(this->storage->count(key)==0){
            throw KeyNotFoundException();
        }
        return (*this->storage)[key];
    }

    void remove(string key) override{
        if(this->storage->count(key)==0){
            throw KeyNotFoundException();
        }
        this->storage->erase(key);
    }

    double get_current_usage() override{
        int current_size = this->storage->size();
        return (1.0*current_size)/(1.0* this->capacity);
    }
};

#endif