#ifndef ReadResponseModel_hpp
#define ReadResponseModel_hpp
#include <bits/stdc++.h>

class ReadResponse {

private:
    string* value;
    double read_time;

public:
    ReadResponse()=default;
    ReadResponse(string* value, double read_time){
        this->value = value;
        this->read_time = read_time;
    }

    string* get_value() {
        return this->value;
    }

    double get_read_time() {
        return this->read_time;
    }
};

#endif