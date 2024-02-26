#ifndef DefaultLevelCache_hpp
#define DefaultLevelCache_hpp
#include "ILevelCache.hpp"
#include "LevelCacheDataModel.hpp"
#include "CacheProvider.hpp"

class DefaultLevelCache: public ILevelCache{
private:
    ILevelCache *next;
    ICacheProvider *cache_provider;
    LevelCacheData level_cache_data;

public:
    DefaultLevelCache(ILevelCache *next, ICacheProvider *cache_provider,  LevelCacheData level_cache_data){
        this->next = next;
        this->cache_provider=cache_provider;
        this->level_cache_data=level_cache_data;
    }

    WriteResponse write(string key, string value){
        double total_time = 0.0;
        string* old_value= nullptr;

        try{
            total_time+= this->level_cache_data.get_read_time();
            string temp = this->cache_provider->read(key);
            old_value = &temp;
        }catch (KeyNotFoundException e){
            cout<<"Key: "<<key<<" does not exists at this level"<<endl;
        }

        if(old_value==nullptr || (*old_value)!=value){
            this->cache_provider->write(key, value);
            total_time += this->level_cache_data.get_write_time();
            total_time += this->next->write(key, value).get_write_time();
        }

        return WriteResponse(total_time);
    }

    ReadResponse read(string key){
        double total_time = 0.0;
        string* value= nullptr;

        try {
            total_time+= this->level_cache_data.get_read_time();
            string temp = this->cache_provider->read(key);
            value = &temp;
        }catch (KeyNotFoundException e){
            cout<<"Key: "<<key<<" does not exists at this level"<<endl;
        }

        if(value==nullptr){
            ReadResponse next_layer_read_response = this->next->read(key);
            value = next_layer_read_response.get_value();
            if(value!= nullptr){
                this->cache_provider->write(key, *value);
                total_time += (this->level_cache_data.get_write_time()
                        + next_layer_read_response.get_read_time());
            }
        }

        return ReadResponse(value, total_time);
    }

    vector<double> stats() override{
        vector<double> stats;
        if(this->next!=nullptr){
            stats=this->next->stats();
        }
        stats.insert(stats.begin(),this->cache_provider->get_current_usage());
        return stats;
    }
};

#endif