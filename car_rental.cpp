#include <iostream>
#include "Car.h"
int main(void)
{
    Car::setZero();
    
    class Car c1("Maruti Suzuki", "Swift", 2022, 15000);
    class Car c2("Maruti Suzuki", "Swift", 2022, 15000);
    std::cout << c1.totalRentalPrice();
    return 0;
}