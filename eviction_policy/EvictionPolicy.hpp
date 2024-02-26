#ifndef EvictionPolicy_hpp
#define EvictionPolicy_hpp
#include <bits/stdc++.h>

class EvictionPolicy {
public:
   virtual void key_accessed(string const &key)=0;
   virtual string evict()=0;
};
#endif