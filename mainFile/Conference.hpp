#ifndef CONFERENCE_HPP
#define CONFERENCE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>

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
        Conference(){}

        // Method to get Conference instance by name
        static Conference* getConferenceByName(const std::string& name){}
        std :: string getName(){}
        DateTime getDateTime(){}

};

class DateTime
{
    private:
        std :: string date;
        std :: string day;
        std :: string time;

    public:
        DateTime(){}
        std :: string displayDate(std :: string format);
        std :: string displayTime();
    
};

class Venue
{
    private:
        static const int MAX_VENUES = 100;
        static std :: string placeList[MAX_VENUES];
        static int numVenues;
        std :: string venue_name;

    public:
        Venue();
        Venue(const std :: string& p);
        ~Venue();

        static void addVenue(const std :: string& p);
        static void deleteVenue(const std :: string& p);
        static void showVenues();
        static void editVenue(const std :: string& oldPlace, const std :: string& newPlace);
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
        static std :: map<std :: string, User*> userMap;

        User(std :: string name, short int age, std :: string regNO, std :: string gender, 
            std :: string username, std :: string password, std :: string email);

        User();

        static User* getUserByUsername(const std :: string& username);

        void setName(std :: string n);
        std :: string getName() const;

        void setAge(short int a);
        short int getAge() const;

        void setRegNO(std :: string r);
        std :: string getRegNO() const;

        void setGender(std :: string g);
        std :: string getGender() const;

        void setUsername(std :: string u);
        std :: string getUsername() const;

        void setPassword(std :: string p);
        std :: string getPassword() const;

        void setEmail(std :: string e);
        std :: string getEmail() const;

        virtual void display() const;

        bool verifyLogin(std :: string uname, std :: string pword);

        void updateEmail(std :: string newEmail);

        void updatePassword(std :: string newPassword);
};

class Organiser : public User 
{
    private:
        std :: string organisationName;
        std :: string organiserTitle;

    public:
        Organiser();
        Organiser(const User& user);
        Organiser(std :: string name, short int age, std :: string regNO, std :: string gender,
                std :: string username, std :: string password, std :: string email,
                std :: string orgName, std :: string title);

        void setOrganisationName(std :: string orgName);
        std :: string getOrganisationName() const;

        void setOrganiserTitle(std :: string title);
        std :: string getOrganiserTitle() const;

        void displayOrganiserInfo() const;
        void organiseConference(Conference *conference);
};

class Participant : public User 
{
    private:
        std :: vector <Conference*> scheduledConferences;
        std :: vector <DateTime*> scheduledDateTimes;

    public:
        Participant(const User& user);
        Participant();
        ~Participant();

        void scheduleConference(Conference *conference);
        void showConferences();
        void showTimes();
};

class Sponsor : public User 
{
    private:
        std :: string sponsoredEvent;
        double amount;

    public:
        Sponsor();
        Sponsor(std :: string name, short int age, std :: string regNO, std :: string gender, 
                std :: string username, std :: string password, std :: string email, 
                std :: string event, double amt);
        Sponsor(User &User);

        void display() const override;
        void sponsorConference(Conference* conference);
};


#endif