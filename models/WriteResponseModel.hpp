#ifndef WriteResponseModel_hpp
#define WriteResponseModel_hpp

class WriteResponse {

private:
    double write_time;

public:
    WriteResponse()=default;
    WriteResponse(double write_time){
        this->write_time = write_time;
    }

    double get_write_time() const {
        return this->write_time;
    }
};

#endif