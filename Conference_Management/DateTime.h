#ifndef DATETIME_H
#define DATETIME_H
#include <string>

class DateTime
{
    private:
        std :: string date;
        std :: string day;
        std :: string time;

    public:
        DateTime();
        std :: string displayDate(std :: string format){}
};

#endif