#include <map>
#include <iostream>
#include <string>
#include <vector>

#include "Conference.cpp"


void page_1();
void page_2(User& user);
void exploreConferences(User& user);
void createConferences();

void createConferences()
{
    std :: string name;
    std :: string temp1, temp2;
    Venue venue;
    std :: cout << "\nEnter the name of the conference: ";
    getline(std :: cin, name);
    std :: cout << "\n\n\n";
    Venue :: showVenues();
    std :: cout << "\n\n";
    std :: cout << "\nEnter the name of the venue: ";
    std :: cin >> temp1;
    DateTime datetime(temp1, temp2);
    std :: cout << "\nEnter the date for the conference (e.g., 2024-04-15): ";
    getline(std :: cin, date);
    showAvailableTimeSlots();
    cout << "\nChoose the time slot by number (1-4): ";
    int choice;
    cin >> choice;
    cin.ignore(std :: numeric_limits<std :: streamsize>::max(), '\n'); // Clear the input buffer after reading

    switch (choice) 
    {
        case 1: timeSlot = "8:00 AM - 10:00 AM"; break;
        case 2: timeSlot = "10:00 AM - 12:00 PM"; break;
        case 3: timeSlot = "2:00 PM - 5:00 PM"; break;
        case 4: timeSlot = "5:00 PM - 7:00 PM"; break;
        default:
            cout << "Invalid choice. Defaulting to the first time slot." << endl;
            timeSlot = "8:00 AM - 10:00 AM";
    }

    if (!isTimeSlotAvailable(date, timeSlot)) 
    {
        cout << "There is already a conference scheduled on " << date << " at " << timeSlot << ". Please choose another time." << endl;
    } 
    else 
    {
        conferences.push_back({name, date, timeSlot});
        cout << "Conference scheduled successfully!" << endl;
    }
}


// int main() 
// {
//     CreateConference scheduler;
//     char choice;

//     do 
//     {
//         scheduler.schedule();

//         cout << "\nDo you want to schedule another conference? (y/n): ";
//         cin >> choice;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
//     } 
//     while (choice == 'y' || choice == 'Y');

//     return 0;
// }


bool isDigits(const std::string &str) 
{
    for (char c : str) 
    {
        if (!std :: isdigit(static_cast <unsigned char> (c))) 
        {
            return false;
        }
    }
    return true;
}

std :: map <std :: string, Conference*> :: iterator getConference(int n = 10)
{
    int i = 0;
    while (true)
    {
        auto it = Conference :: conferenceMap.begin();
        size_t size = Conference :: conferenceMap.size();
        size_t i = 0;
        while (true)
        {
            while (i < n - 1 && i < size)
            {
                std :: cout << i << "." << it -> first << "\n";
                ++ i;
                ++ it;
            }

            std :: cout << "Enter your choice [n / next / prev]: ";
            std :: string resp;
            std :: cin >> resp;
            std :: cout << "\n";
            if (isDigits(resp))
            {
                std :: advance(it, n - 1);
                return it;
            }
            else if (resp == "next")
            {
                if ((size - 10) < i) 
                {
                    i = 0;
                    n = 10;
                }
                else 
                {
                    i += 10;
                    n += 10;
                }
            }
            else if (resp == "prev")
            {
                if (i != 0)
                {
                    i -= 10;
                    n -= 10;
                };
            }
        }

    }
    // Conference* selectedConference = it -> second;

}
void page_2(User &user)
{
    std :: cout << "\n\t\tMAIN MENU";
    std :: cout << "\n1. Explore Conferences"; 
    std :: cout << "\n2. Create Conference";
    std :: cout << "\n3. Exit";
    int resp;
    std :: cout << "\n: ";
    std :: cin >> resp;
    while (true);
    {
        switch(resp)
        {
            case 1:
                exploreConferences(user);
                break;
            case 2:
                createConferences();
                break;
            case 3:
                // the followign code will be added to an deleteAll() function
                for (std :: map <std :: string, Conference*> :: iterator it = Conference :: conferenceMap.begin(); it != Conference :: conferenceMap.end(); ++ it)
                {
                    delete it -> second;
                }
                Conference :: conferenceMap.clear();
                for (std :: map <std :: string, User*> :: iterator it = User :: userMap.begin(); it != User :: userMap.end(); ++ it)
                {
                    delete it -> second;
                }
                Conference :: conferenceMap.clear();
                User :: userMap.clear();
                // paricipant and sponsor ones to be added as well
                exit(0);
            default:
                std :: cout << "\nInvalid response\n";

        }
    }
}

void exploreConferences(User &user)
{
    std :: cout << "\n1. Join";
    std :: cout << "\n2. Organise";
    std :: cout << "\n3. Sponsor";
    std :: cout << "\n4. Back to main menu";
    std :: cout << "\nEnter your choice: ";
    int choice;
    std :: cin >> choice;

    switch(choice)
    {
        case 1:
        {
            // needs remodelling 
            // participant is its own thing not just of one conference 
            // update : remodelling complete
            Participant* participant = new Participant(user);
            choice = 'y';
            do
            {
                std :: map <std :: string, Conference*> :: iterator it = getConference();
                std :: cout << "\nYou selected: " << it -> first;
                participant -> scheduleConference(it -> second);
                std :: cout << "\nSchedule More? [y / any key]: ";
                std :: cin >> choice;
                // want to use goto but thats bad design
                // update : goto not required
            }
            while (choice == 'y');
            break;
        }
        case 2:
        {
            // Code to organise the conference
            Organiser* organiser = new Organiser(user);
            choice = 'y';
            do
            {
                std :: map <std :: string, Conference*> :: iterator it = getConference();
                std :: cout << "\nYou selected: " << it -> first;
                organiser -> organiseConference(it -> second);
                std :: cout << "\nOrganise More? [y / any key]: ";
                std :: cin >> choice;
            }
            while (choice == 'y');
            break;
        }
        case 3:
        {
            // Code to sponsor the conference
            Sponsor* sponsor = new Sponsor(user);
            choice = 'y';
            do
            {
                std :: map <std :: string, Conference*> :: iterator it = getConference();
                std :: cout << "\nYou selected: " << it -> first;
                sponsor -> sponsorConference(it -> second);
                std :: cout << "\nSponsor More? [y / any key]: ";
                std :: cin >> choice;
            }
            while (choice == 'y');
            break;
        }
        case 4:
        {
            page_2(user);
            break;
        }
        default:
        {
            std::cout << "\nInvalid choice. Please try again.\n";
        }
    }
}





void sign_up()
{
    std::string name;
    short int age;
    std::string regNO;
    std::string gender;
    std::string username;
    std::string password;
    std::string email;

    std::cout << "\nEnter your details:\n";
    std::cout << "\nName: ";
    std::cin >> name;
    std::cout << "\nAge: ";
    std::cin >> age;
    std::cout << "\nRegistration Number: ";
    std::cin >> regNO;
    std::cout << "\nGender: ";
    std::cin >> gender;
    std::cout << "\nUsername: ";
    std::cin >> username;
    std::cout << "\nPassword: ";
    // have to create a function for setting good password
    std::cin >> password;
    std::cout << "\nEmail: ";
    std::cin >> email;

    // Create a new User and add it to the userMap
    new User(name, age, regNO, gender, username, password, email);

    std::cout << "\nSigned up successfully.\n\n";
    page_1();
}

void sign_in()
{
    // Implementation can be changed for security reasons
    while (true)
    {
        std :: string username;
        std :: string password;
        std :: cout << "\nUsername : ";
        std :: cin >> username;
        std :: cout << "\nPassword : ";
        std :: cin >> password;
        User *user = User :: getUserByUsername(username);
        if (user != nullptr && user -> getPassword() == password)
        {
            std :: cout << "\nPassword is correct.";
            std :: cout << "\nSigned in successfully.";
            page_2(*user);
        }
        else
        {
            std::cout << "\nInvalid username or password.";
        }
    }
}

void deleteAll()
{
    // delete all pointer memebers from conference
    // needs to used everywhere
}

void page_1()
{
    std :: cout << "\n\t\tMAIN MENU\n";
    std :: cout << "\n1. Sign-In\n";
    std :: cout << "\n2. Sign-Up\n";
    std :: cout << "\n3. Exit\n";
    int resp;
    std :: cin >> resp;
    while (true)
        switch(resp)
        {
            case 1:
                sign_in();
                break;
            case 2:
                sign_up();
                break;
            case 3:
                exit(0);
            default:
                std :: cout << "Invalid response\n";

        }
}

int main(void)
{
    page_1();

    return 0;
}