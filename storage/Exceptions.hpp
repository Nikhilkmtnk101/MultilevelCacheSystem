#ifndef Exceptions_hpp
#define Exceptions_hpp
#include "exception"
using namespace std;

class StorageFullException: public exception{
    const char * what() const noexcept override{
        return "Cache storage is full";
    }
};

class KeyNotFoundException: public exception{
    const char * what() const noexcept override{
        return "Key does not exist";
    }
};

#endif