#ifndef CacheService_hpp
#define CacheService_hpp

#include <bits/stdc++.h>
#include <ILevelCache.hpp>

class CacheService{
private:
    int last_count;
    vector<double> last_reads;
    vector<double> last_writes;
    ILevelCache *leve_cache;

    void add_write_time(double write_time){
        if(this->last_writes.size()== this->last_count){
            this->last_writes.erase(this->last_writes.begin());
        }
        this->last_writes.push_back(write_time);
    }

    void add_read_time(double read_time){
        if(this->last_reads.size()== this->last_count){
            this->last_reads.erase(this->last_reads.begin());
        }
        this->last_reads.push_back(read_time);
    }

    double get_avg_write_time(){
        double total_write_time=0.0;
        int count=0;
        for(auto u: this->last_writes){
            total_write_time+=u;
            count++;
        }
        return total_write_time/count;
    }

    double get_avg_read_time(){
        double total_read_time=0.0;
        int count=0;
        for(auto u: this->last_reads){
            total_read_time+=u;
            count++;
        }
        return total_read_time/count;
    }

public:
    CacheService()=default;
    CacheService(int last_count, ILevelCache* leve_cache){
        this->last_count = last_count;
        this->leve_cache = leve_cache;
    }

    WriteResponse write(string key, string value){
        WriteResponse write_response =  this->leve_cache->write(key, value);
        this->add_write_time(write_response.get_write_time());
        return write_response;
    }

    ReadResponse read(string key){
       ReadResponse read_response = this->leve_cache->read(key);
       this->add_read_time(read_response.get_read_time());
       return read_response;
    }

    StatsResponse stats(){
        double avg_read_time = this->get_avg_read_time();
        double avg_write_time = this->get_avg_write_time();
        vector<double> current_usage = this->leve_cache->stats();
        return StatsResponse(avg_read_time, avg_write_time, current_usage);
    }
};

#endif