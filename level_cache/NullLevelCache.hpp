#ifndef NullLevelCache_hpp
#define NullLevelCache_hpp
#include "ILevelCache.hpp"
class NullLevelCache: public ILevelCache{
public:
    WriteResponse write(string key, string value) override{
        return WriteResponse(0.0);
    }

    ReadResponse read(string key) override{
        return ReadResponse(nullptr, 0.0);
    }

    vector<double> stats() override{
        return vector<double>();
    }
};

#endif