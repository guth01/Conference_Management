#include <memory>
#include "Conference.cpp"
#include <limits>

void page_1();
void page_2(User& user);
void exploreConferences(User& user);
void createConferences(User& user);


void deleteAllExit()
{
    // // delete all pointer memebers from conference
    // // needs to used everywhere
    // for (std :: map <std :: string, Conference*> :: iterator it = Conference :: conferenceMap.begin(); it != Conference :: conferenceMap.end(); ++ it)
    // {
    //     delete it -> second;
    // }
    // Conference :: conferenceMap.clear();
    // for (std :: map <std :: string, User*> :: iterator it = User :: userMap.begin(); it != User :: userMap.end(); ++ it)
    // {
    //     delete it -> second;
    // }
    // Conference :: conferenceMap.clear();
    // User :: userMap.clear();
    // // paricipant and sponsor ones to be added as well
    // // @ needs to be completed
    // exit(0);
}

void createConferences(User& user)
{
    std :: string name;
    std :: string date, timeSlot;
    std :: string venue_name;
    int choice;

    std :: cout << "\nEnter the name of the conference: ";
    getline(std :: cin, name);
    std :: cout << "\n\n\n";

    Venue :: showVenues();
    std :: cout << "\n\n";

    while (true)
    {
        std :: cout << "\nEnter the name of the venue: ";
        getline(std :: cin, venue_name);
        Venue venue(venue_name);
        
        if (Venue :: checkVenue(venue_name))
        {
            std :: cout << "\nVenue exists.";
            Conference :: showAvailableTimeSlots(venue);
            std :: cout << "\nEnter date in DD-MM-YYYY format.\n";
            getline(std :: cin, date);

            std :: cout << "\nChoose the time slot by number (1-4): ";
            std :: cin >> choice;
            std :: cin.ignore(std :: numeric_limits<std :: streamsize> :: max(), '\n'); // Clear the input buffer after reading

            switch (choice) 
            {
                case 1: timeSlot = "8:00 AM"; break;
                case 2: timeSlot = "10:00 AM"; break;
                case 3: timeSlot = "2:00 PM"; break;
                case 4: timeSlot = "5:00 PM"; break;
                default:
                    std :: cout << "Invalid choice. Defaulting to the first time slot." << std :: endl;
                    timeSlot = "8:00 AM";
            }

            DateTime datetime(date, timeSlot);
            if (Conference :: isTimeSlotAvailable(datetime, venue))
            {
                std :: cout << "\nSlot Available.\nSlot booked successfully.";
            }
            std :: cout << "\nSlot already booked.\nTry Again.\n";
            std :: unique_ptr<Organiser> organiser = std :: make_unique<Organiser>(user);
            Conference conference(datetime, venue, organiser.get());
        }
        else
        {
            std :: cout << "\nVenue doesn't exist.\nTry Again.";
        }  
    }
}

bool isDigits(const std :: string &str) 
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
                }
            }
        }

    }
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
    while (true)
    {
        std :: cout << "error:1";
        switch(resp)
        {
            case 1:
                exploreConferences(user);
                break;
            case 2:
                createConferences(user);
                break;
            case 3:
                deleteAllExit();
               
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
            std :: unique_ptr<Participant> participant = std :: make_unique<Participant>(user);
            choice = 'y';
            do
            {
                std :: map <std :: string, Conference*> :: iterator it = getConference();
                std :: cout << "\nYou selected: " << it -> first;
                participant -> scheduleConference(it -> second);
                std :: cout << "\nSchedule More? [y / any key]: ";
                std :: cin >> choice;
            }
            while (choice == 'y');
            break;
        }
        case 2:
        {
            // Code to organise the conference
            std :: unique_ptr<Organiser> organiser = std :: make_unique<Organiser>(user);
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
            std :: unique_ptr<Sponsor> sponsor = std :: make_unique<Sponsor>(user);
            choice = 'y';
            do
            {
                std :: map <std :: string, Conference*> :: iterator it = getConference();
                std :: cout << "\nYou selected: " << it -> first;
                sponsor -> sponsorConference();
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
    std :: make_unique<User>(name, age, regNO, gender, username, password, email);

    std :: cout << "\nSigned up successfully.\n\n";
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