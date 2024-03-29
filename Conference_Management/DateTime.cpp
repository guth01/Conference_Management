#include <iostream>
#include <string>

class DateTime
{
    private:
        std :: string date;
        std :: string day;
        std :: string time;

    public:
        DateTime() : date("12-03-2005"), time("13:00:00"), day("Sunday")
        {
            // constructor for sample purpose only
        }
        std :: string displayDate(std :: string format)
        {
            if (format == "HHHH")
            {
                return day;
            }
            else if (format == "MM-DD-YYYY")
            {
                return (date.substr(3, 4) + '-' + date.substr(0, 1) + '-' + date.substr(6, 9));
            }
            else if (format == "DD-MM-YYYY")
            {
                return (date.substr(0, 1) + '-' + date.substr(3, 4) + '-' + date.substr(6, 9));
            }
            else
            {
                throw std :: invalid_argument("Error: Not a valid Date Format\n");
            }
        }
};