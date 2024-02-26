#ifndef ICacheProvider_hpp
#define ICacheProvider_hpp
#include "bits/stdc++.h"

class ICacheProvider{
public:
    virtual void write(string key, string value)=0;
    virtual string read(string key)=0;
    virtual double get_current_usage()=0;
};

#endif