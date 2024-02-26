#ifndef StatsResponseModel_hpp
#define StatsResponseModel_hpp
#include <bits/stdc++.h>

class StatsResponse {

private:
    double avg_read_time, avg_write_time;
    vector<double> each_layer_usages;

public:
    StatsResponse()=default;

    StatsResponse(double avg_read_time, double avg_write_time, vector<double> each_layer_usages){
        this->avg_read_time = avg_read_time;
        this->avg_write_time = avg_write_time;
        this->each_layer_usages = each_layer_usages;
    }

    double get_avg_read_time() const {
        return this->avg_read_time;
    }

    double get_avg_write_time() const {
        return this->avg_write_time;
    }

    vector<double> get_each_layer_usages() const {
        return this->each_layer_usages;
    }

};

#endif