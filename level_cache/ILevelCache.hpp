#ifndef ILevelCache_hpp
#define ILevelCache_hpp
#include "ReadResponseModel.hpp"
#include "WriteResponseModel.hpp"
#include "StatsResponseModel.hpp"

class ILevelCache{
public:
    virtual WriteResponse write(string key, string value)=0;
    virtual ReadResponse read(string key)=0;
    virtual vector<double> stats()=0;
};

#endif