#ifndef ORGANISER_H
#define ORGANISER_H

#include <string>
#include "User.h"

class Organiser : public User 
{
private:
    std::string organisationName;
    std::string organiserTitle;

public:
    // Constructor
    Organiser();
    Organiser(std::string name, short int age, std::string regNO, std::string gender, 
              std::string username, std::string password, std::string email, 
              std::string orgName, std::string title);

    // Getters and Setters
    void setOrganisationName(std::string orgName);
    std::string getOrganisationName() const;

    void setOrganiserTitle(std::string title);
    std::string getOrganiserTitle() const;

    // Display organiser information
    void displayOrganiserInfo() const;
};

#endif // ORGANISER_H
