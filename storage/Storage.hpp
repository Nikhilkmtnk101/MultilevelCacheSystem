#ifndef Storage_hpp
#define Storage_hpp
#include "bits/stdc++.h"

class Storage{
public:
    virtual void add(string key, string value)=0;
    virtual string get(string key)=0;
    virtual void remove(string key)=0;
    virtual double get_current_usage()=0;
};
#endif