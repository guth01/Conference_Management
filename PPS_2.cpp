//#include <iostream>

// class D
// {
//     protected:
//     virtual float distMeters(){}
// };

// class DM : D
// {
//     int meters;
//     float cms;

//     float distMeters()
//     override
//     {
//         return (float) meters + (cms * 0.01);
//     }
// };

// class DB : D
// {
//     int feet;
//     float inches;

//     float distMeters()
//     {
//         return ((float) feet * 0.3) + inches * 0.0254;
//     }
// };
#include <string>
#include <iostream>
using namespace std;

class Car
{
    string make;
    string model;
    int year;
    float rprice;
    
    public:
    Car() {};
    Car(string make, string model, int year, float rprice)
    {
        this -> make = make;
        this -> model = model;
        this -> year = year;
        this -> rprice = rprice;
    }
};

int main(void)
{
    int n;
    string make;
    string model;
    int year;
    float rprice;
    
    cin >> n;
    Car *cars = new Car[n]; //for dynamic array of cars
    for (int i = 0; i < n; i ++)
    {
        cin >> make;
        cin >> model;
        cin >> year;
        cin >> rprice;
        cars[i] = Car(make, model, year, rprice);
    }
}
#include <ctime> 
void showTime()  
{  
    time_t t = time(0); 
    tm* now = std::localtime(&t);  
    cout << endl << endl 
        << "The code was executed at: "   
        << (now->tm_year + 1900) << '-'   
        << (now->tm_mon + 1) << '-'  
        << now->tm_mday << ' '  
        << now->tm_hour << ':'  
        << now->tm_min << ':'  
        << now->tm_sec  
        << endl;  
}  