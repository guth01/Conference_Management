#include <string>
#include <iostream>
#include <vector>
#include <map>

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
        DateTime(std :: string date, std :: string time)
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

        std :: string displayTime()
        {
            return "";
            // @Sharvesh define this
        } // needs to be defined

        static bool checkDateTime(std :: string& date_, std :: string& time_)
        {
            return true; // @Sharvesh define this
        }

        //@gauthum operator overloading of ==

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
                    std :: cout << "\nVenue Found";
                    std :: cout << "\nVenue Chosen Successfully.";
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

        static bool checkVenue(const std :: string venue_name_)
        {
            // @Uditanshu 
        }
        //@gauthum operator overloading of ==

};

class User;
class Organiser;
class Participant;
class Sponsor;

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
        void showAvailableTimeSlots() // what does this do?
        {
            std :: cout << "Available Time Slots:" << std :: endl;
            std :: cout << "1. 8:00 AM - 10:00 AM" << std :: endl;
            std :: cout << "2. 10:00 AM - 12:00 PM" << std :: endl;
            std :: cout << "3. 2:00 PM - 5:00 PM" << std :: endl;
            std :: cout << "4. 5:00 PM - 7:00 PM" << std :: endl;
        }
        static bool isTimeSlotAvailable(DateTime datetime_, Venue venue_) 
        {
            
            std :: map <std :: string, Conference*> :: iterator it = conferenceMap.begin();
            for (std :: map <std :: string, Conference*> :: iterator end = conferenceMap.end(); it != end; ++ it)
            {
                Conference* conference_ = it -> second;
                // if (conference_ -> datetime == datetime_ && conference_ -> venue == venue_)
                // {
                //     return false;
                // }
            }
            return true;
        }
};

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
        virtual void display() const {//virtual keyword is used so that the method display can be overidden by base classes when necessary
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

        void displayOrganiserInfo() const
        {
            display(); // Display user information from the base class
            std::cout << "Organisation Name: " << organisationName << "\nOrganiser Title: " << organiserTitle << std::endl;
        }
        void organiseConference(Conference *conference){};
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
    DateTime* newDateTime = new DateTime(conference -> getDateTime());
    scheduledConferences.push_back(conference);
    scheduledDateTimes.push_back(newDateTime);
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
        Sponsor(User &User){};

        void display() const override
        {
            std :: cout << "Sponsor: ";
            User :: display();
            std :: cout << ", Event: " << sponsoredEvent << ", Amount: ₹" << amount;
        }
        void sponsorConference(Conference* conference){}
    
};
std :: string Venue :: placeList[MAX_VENUES];
int Venue :: numVenues = 0;
std::map<std::string, User*> User::userMap;
std :: map <std :: string, Conference*> Conference :: conferenceMap;