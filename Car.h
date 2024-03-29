#include <iostream>
#include <string.h>
using namespace std;

class Car
{
    char make[15];
    char model[20];
    int year;
    float price;

    public:
        static float price_sum;
        static float highest_price;

        Car(const char *make, const char *model, int year, float price)
        {
            strcpy(this -> model, model);
            strcpy(this -> make, make);
            this -> year;
            this -> price;
            price_sum += price;
            if (price > highest_price) highest_price = price;
        }
        static float totalRentalPrice()
        {
            return price_sum;
        }

        static float highestRentPrice()
        {
            return highest_price;
        }
        static void setZero()
        {
            static float price_sum = 0;
            static float highest_price = 0;

        }
};
