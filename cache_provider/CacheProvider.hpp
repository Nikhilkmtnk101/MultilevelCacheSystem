#ifndef CacheProvider_hpp
#define CacheProvider_hpp
#include "ICacheProvider.hpp"
#include "MapStorage.hpp"
#include "LRUEvictionPolicy.hpp"
#include "bits/stdc++.h"

class CacheProvider: public ICacheProvider{
private:
    Storage  *storage;
    EvictionPolicy *eviction_policy;

public:
    CacheProvider(Storage  *storage, EvictionPolicy *eviction_policy){
        this->storage = storage;
        this->eviction_policy = eviction_policy;
    }

    void write(string key, string value) override{
        try {
            this->storage->add(key, value);
            this->eviction_policy->key_accessed(key);
        }catch (StorageFullException e){
            string evicted_key= this->eviction_policy->evict();
            this->storage->remove(evicted_key);
            cout<<"Got storage full exception, evicting key: "<<key<<endl;
        }
        this->write(key, value);
    }

    string read(string key) override{
        string value = this->storage->get(key);
        this->eviction_policy->key_accessed(key);
        return value;
    }

    double get_current_usage() override{
        return this->storage->get_current_usage();
    }

};
#endif