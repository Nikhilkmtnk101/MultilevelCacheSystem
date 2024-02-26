#ifndef LevelCacheDataModel_hpp
#define LevelCacheDataModel_hpp

class LevelCacheData {

private:
    double read_time, write_time;

public:
    LevelCacheData()=default;
    LevelCacheData(double read_time, double write_time) {
        this->read_time = read_time;
        this->write_time = write_time;
    }

    double get_read_time() const {
        return this->read_time;
    }

    double get_write_time() const {
        return this->write_time;
    }

};
#endif