#include <map>
#include <iostream>
#include <string>
#include <vector>
//#include <limits>
class Conference;
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
        std :: string displayTime(){}; // needs to be defined
};

class Venue
{
    private:
        static const int MAX_VENUES = 100; // Maximum number of venues
        static std :: string placeList[MAX_VENUES]; // Array to store venue names
        static int numVenues; // Number of venues currently stored
        std :: string venue_name;

    public:
        Venue(){};
        Venue(const std :: string& p) 
        {
            for (int i = 0; i < numVenues; ++i) 
            {
                if (placeList[i] == p) 
                {
                    venue_name = p;
                    std :: cout << "Venue Found\n";
                    std :: cout << "Venue Chosen Successfully.\n";
                }
            }
        }
        ~Venue(){};

        static void addVenue(const std :: string& p) 
        {
            for (int i = 0; i < numVenues; ++i) 
            {
                if (placeList[i] == p) 
                {
                    std::cout << "Cannot add venue: " << p << " is already in the list.\n";
                    return;
                }
            }
            if (numVenues < MAX_VENUES)
            {
                placeList[numVenues++] = p; // Add the new venue to the list
            } 
            else 
            {
                std::cerr << "Error: Venue list is full!\n";
            }
        }

        static void deleteVenue(const std :: string& p) 
        {
            int index = -1;
            for (int i = 0; i < numVenues; ++i) 
            {
                if (placeList[i] == p) 
                {
                    index = i;
                    break;
                }
            }
            if (index != -1)
            {
                for (int i = index; i < numVenues - 1; ++ i)
                {
                    placeList[i] = placeList[i + 1]; // Shift venues to fill the gap
                }
                numVenues--; // Decrease the number of venues
            } 
            else 
            {
                std :: cerr << "Error: Venue not found!\n";
            }
        }

        static void showVenues()
        {
            std::cout << "Places in the venue list:\n";
            for (int i = 0; i < numVenues; ++i) 
            {
                std::cout << "- " << placeList[i] << '\n';
            }
        }

        static void editVenue(const std :: string& oldPlace, const std :: string& newPlace) 
        {

            int index = -1;
            for (int i = 0; i < numVenues; ++ i) 
            {
                if (placeList[i] == oldPlace) 
                {
                    index = i;
                    break;
                }
            }

            if (index != -1) 
            {
                placeList[index] = newPlace; // Replace the old venue with the new one
            } 
            else 
            {
                std::cerr << "Error: Venue not found!\n";
            }
        }
};

std :: string Venue :: placeList[MAX_VENUES];
int Venue :: numVenues = 0;

class User
{
    private:
        std :: string name;
        short int age;
        std :: string regNO;
        std :: string gender;
        std :: string username;
        std :: string password;
        std :: string email;

    public:
        static std :: map<std::string, User*> userMap;
        // Constructor
        User(std :: string name, short int age, std :: string regNO, std :: string gender, 
            std :: string username, std :: string password, std :: string email)
        : name(name), age(age), regNO(regNO), gender(gender), 
        username(username), password(password), email(email) 
        {
            userMap[username] = this;
        }

        // Default Constructor
        User() {}; 
        // This implementation must be removed
        // default cons

        static User* getUserByUsername(const std::string& username) 
        {
            if (userMap.find(username) != userMap.end()) 
            {
                std :: cout << "User Found";
                return userMap[username];
            }
            else 
            {
                std :: cout << "User Not Found";
                return nullptr;
            }
        }
        // Getters and Setters
        void setName(std :: string n) { name = n; }
        std :: string getName() const { return name; }

        void setAge(short int a) { age = a; }
        short int getAge() const { return age; }

        void setRegNO(std :: string r) { regNO = r; }
        std :: string getRegNO() const { return regNO; }

        void setGender(std :: string g) { gender = g; }
        std :: string getGender() const { return gender; }

        void setUsername(std :: string u) { username = u; }
        std :: string getUsername() const { return username; }

        void setPassword(std :: string p) { password = p; }
        std :: string getPassword() const { return password; }

        void setEmail(std :: string e) { email = e; }
        std :: string getEmail() const { return email; }

        // Display user information
        void display() const {
            std :: cout << "Name: " << name << "\nAge: " << age 
                << "\nRegistration Number: " << regNO 
                << "\nGender: " << gender << "\nUsername: " 
                << username << "\nEmail: " << email << std :: endl;
        }

        // Login verification
        bool verifyLogin(std :: string uname, std :: string pword) {
            return uname == username && pword == password;
        }

        // Update Information
        void updateEmail(std :: string newEmail) {
            email = newEmail;
        }

        void updatePassword(std :: string newPassword) {
            password = newPassword;
        }

        // More functions like updateName, updateAge, etc. can be added similarly
};
std::map<std::string, User*> User::userMap;

class Organiser : public User 
{
    private:
        std::string organisationName;
        std::string organiserTitle;

    public:
        // Constructor
        Organiser(){};
        Organiser(const User& user) : User(user){};
        Organiser(std::string name, short int age, std::string regNO, std::string gender,
                std::string username, std::string password, std::string email,
                std::string orgName, std::string title)
                : User(name, age, regNO, gender, username, password, email),
                organisationName(orgName), organiserTitle(title) {}

        // Getters and Setters
        void setOrganisationName(std::string orgName) { organisationName = orgName; }
        std::string getOrganisationName() const { return organisationName; }

        void setOrganiserTitle(std::string title) { organiserTitle = title; }
        std::string getOrganiserTitle() const { return organiserTitle; }

        // Display organiser information
        void displayOrganiserInfo() const {
            display(); // Display user information from the base class
            std::cout << "Organisation Name: " << organisationName << "\nOrganiser Title: " << organiserTitle << std::endl;
        }
};


class Participant: public User
{
    private:
        std :: vector <Conference*> scheduledConferences = {};
        std :: vector <DateTime*> scheduledDateTimes = {};
    
        // bool conferenceScheduled;

    public:
        // Constructor
        // copy constructor should be the only way to init
        Participant(const User& user) : User(user){};

        // This seems to be not required
        Participant(){};

        ~Participant(){};

        void scheduleConference(Conference *conference);
        void showConferences();
        void showTimes(/*std :: string format*/); // format arguments to be added in the future
};

void Participant :: scheduleConference(Conference *conference)
{
    // Check if participant already registered for the conference
    for (Conference* conference_ : scheduledConferences)
    {
        // should be changed to getID()
        if (conference_ -> getName() == conference -> getName())
        {
            std :: cout << "\nConference already registered.";
            return;
        }
    }
    scheduledConferences.push_back(conference);
    scheduledDateTimes.push_back(&(conference -> getDateTime()));
    // needs to code for the conference to register a participant
    // conference -> register(&participant)
    std :: cout << "\nConference registered successfully.";
}

void Participant :: showConferences()
{
    if (scheduledConferences.empty())
    {
        std :: cout << "\nNo conferences scheduled.";
        return;
    }

    std :: cout << "\nScheduled Conferences : ";
    for (Conference *conference_ : scheduledConferences)
    {
        std :: cout << "\nConference Name: " << conference_ -> getName();
        DateTime datetime_ = conference_ -> getDateTime();
        std :: cout << "\nDay: " << datetime_.displayDate("HHHH") << ", Time: " << datetime_.displayTime(/*some time format*/);
    }
}

void Participant :: showTimes(/*std :: string format*/)
{
    for (DateTime *datetime_ : scheduledDateTimes)
    {
        std :: cout << "\n" << datetime_ -> displayDate("DD-MM-YYYY"/*format1*/) << datetime_ -> displayTime(/*format2*/);
    }
}

class Sponsor : public User {
    private:
        std :: string sponsoredEvent;
        double amount;
    
    public:
        Sponsor(){};
        Sponsor(std::string name, short int age, std::string regNO, std::string gender, 
        std::string username, std::string password, std::string email, std :: string event, double amt) 
        : User(name, age, regNO, gender, username, password, email),
        sponsoredEvent(event), amount(amt) {};

        void display()
        {
            std :: cout << "Sponsor: ";
            User :: display();
            std :: cout << ", Event: " << sponsoredEvent << ", Amount: ₹" << amount;
        }
    
};

// int main() {
//     std :: string name, email, event;
//     double amount;
    
//     std :: cout << "Enter sponsor's name: ";
//     getline(std :: cin, name);
    
//     cout << "Enter sponsor's email: ";
//     getline(cin, email);
    
//     cout << "Enter sponsored event: ";
//     getline(cin, event);
    
//     cout << "Enter sponsorship amount: ";
//     cin >> amount;

//     Sponsor sponsor1(name, email, event, amount);
//     sponsor1.display();
    
//     cout << endl;

//     return 0;
    
// }


class Conference
{
    protected:
        DateTime datetime;
        Venue venue;
        std :: vector <Organiser*> organisers;
        std :: vector <Participant*> participants;
        std :: vector <Sponsor*> sponsors;
        double generated_amt;
        std :: string conference_id;
        std :: string name;

    public:
        static std :: map <std :: string, Conference*> conferenceMap;
        static int no_of_conferences;

        // Constructor
        Conference()
        {
            // Add this Conference instance to the map
            conferenceMap[name] = this;
        }

        // Method to get Conference instance by name
        static Conference* getConferenceByName(const std::string& name) 
        {
            if (conferenceMap.find(name) != conferenceMap.end()) 
            {
                return conferenceMap[name];
            } 
            else 
            {
                return nullptr;
            }
        }
        std :: string getName()
        { 
            return name; 
        }
        DateTime getDateTime()
        {
            return datetime;
        }

};

std :: map <std :: string, Conference*> Conference :: conferenceMap;
void page_1();

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
        while (true)
        {
            while (i < n - 1 && i < size)
            {
                std :: cout << i << "." << it -> first << "\n";
                ++ i;
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
        case 3:
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
        case 4:
            page_2(user);
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}

void createConferences()
{
    new Conference();
};

void page_2(User &user)
{
    std :: cout << "\n\t\tMAIN MENU";
    std :: cout << "\n1. Explore Conferences"; 
    std :: cout << "\n2. Create Conference";
    std :: cout << "\n3. Exit";
    int resp;
    std :: cout << ": ";
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

void sign_up()
{
    std::string name;
    short int age;
    std::string regNO;
    std::string gender;
    std::string username;
    std::string password;
    std::string email;

    std::cout << "Enter your details:\n";
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

    std::cout << "Signed up successfully.\n\n";
    page_1();
}

void sign_in()
{
    // Implementation can be changed for security reasons
    while (true)
    {
        std :: string username;
        std :: string password;
        std :: cout << "Username : ";
        std :: cin >> username;
        std :: cout << "Password : ";
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
    std :: cout << "1. Sign-In\n";
    std :: cout << "2. Sign-Up\n";
    std :: cout << "3. Exit\n";
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