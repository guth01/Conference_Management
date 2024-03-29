#ifndef SPONSOR_H
#define SPONSOR_H

#include <string>
#include "User.h"

class Sponsor : public User 
{
private:
    std::string sponsoredEvent;
    double amount;

public:
    // Constructor
    Sponsor(std::string name, short int age, std::string regNO, std::string gender, 
            std::string username, std::string password, std::string email, 
            std::string event, double amt);

    // Display method
    void display();
};

#endif // SPONSOR_H