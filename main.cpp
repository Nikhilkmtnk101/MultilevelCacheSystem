#include <bits/stdc++.h>
#include "DefaultLevelCache.hpp"
#include "NullLevelCache.hpp"
#include "CacheService.hpp"

using namespace std;

int main(){
    Storage *storage = new MapStorage(5);
    EvictionPolicy *eviction_policy = new LRUEvictionPolicy();
    ICacheProvider *cache_provider = new CacheProvider(storage, eviction_policy);
    ILevelCache *null_level_cache = new NullLevelCache();
    ILevelCache *l2 = new DefaultLevelCache(
            null_level_cache, cache_provider,
            LevelCacheData(1, 1));

    ILevelCache *l1 = new DefaultLevelCache(
            l2, cache_provider,
            LevelCacheData(1, 1));
    CacheService cache_service = CacheService(10, l1);

    while(true){
        cout<<"Enter Operation"<<endl;
        string operation;
        cin>>operation;
        if (operation=="GET"){
            string key;
            cin>>key;
            ReadResponse read_response = cache_service.read(key);
            if(read_response.get_value()!= nullptr){
                cout<<"key: "<<key<<" value: "<<(*read_response.get_value())<<" time taken: "<<read_response.get_read_time()<<endl;
            }else{
                cout<<"key: "<<key<<"does not exist"<<" time taken: "<<read_response.get_read_time()<<endl;
            }

        }else if(operation=="SET"){
            string key, value;
            cin>>key>>value;
            WriteResponse write_response = cache_service.write(key, value);
            cout<<"time taken: "<<write_response.get_write_time()<<endl;
        }else if(operation=="STATS"){
            StatsResponse stats_response = cache_service.stats();
            cout<<"last operation average read time: "<<stats_response.get_avg_read_time()<<endl;
            cout<<"last operation average write time: "<<stats_response.get_avg_write_time()<<endl;
            cout<<"Current usages of each level: "<<endl;
            for(auto u:stats_response.get_each_layer_usages()){
                cout<<u<<" ";
            }
            cout<<endl;
        }else{
            cout<<"Incorrect Operation"<<endl;
        }
    }
}