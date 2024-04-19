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
        User
        (std :: string name, short int age, std :: string regNO, std :: string gender, 
        std :: string username, std :: string password, std :: string email)
        : name(name), age(age), regNO(regNO), gender(gender), 
        username(username), password(password), email(email) 
        {
            userMap[username] = this;
        }

        // Default Constructor
        // User() {}; 
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
        void updateEmail(std :: string newEmail)
        {
            email = newEmail;
        }

        void updatePassword(std :: string newPassword)
        {
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
        // Organiser(){};
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
        void organiseConference(Conference *conference){;}
        // @ needs to be defined
        // needs to add the pointer to this instance to the sponsors in Conefrence class
};

class Participant: public User
{
    private:
        std :: vector <Conference*> scheduledConferences_ = {};
        std :: vector <DateTime*> scheduledDateTimes_ = {};
    
        // bool conferenceScheduled;

    public:
        // Constructor
        // copy constructor should be the only way to init
        Participant(const User& user) : User(user){};

        ~Participant(){};
        friend void registerParticipant(Conference* conference, Participant* participant);
        void scheduleConference(Conference *conference)
        {
            // Check if participant already registered for the conference
            for (Conference* conference_ : scheduledConferences_)
            {
                // should be changed to getID()
                if (conference_ -> getName() == conference -> getName())
                {
                    std :: cout << "\nConference already registered.";
                    return;
                }
            }
            DateTime* newDateTime = new DateTime(conference -> getDateTime());
            scheduledConferences_.push_back(conference);
            scheduledDateTimes_.push_back(newDateTime);
            
            // needs to code for the conference to register a participant

            conference -> registerParticipant(this);
            std :: cout << "\nConference registered successfully.";
        }

        void showConferences()
        {
            if (scheduledConferences_.empty())
            {
                std :: cout << "\nNo conferences scheduled.";
                return;
            }

            std :: cout << "\nScheduled Conferences : ";
            for (Conference *conference_ : scheduledConferences_)
            {
                std :: cout << "\nConference Name: " << conference_ -> getName();
                DateTime datetime_ = conference_ -> getDateTime();
                std :: cout << "\nDay: " << datetime_.displayDate("HHHH") << ", Time: " << datetime_.displayTime(/*some time format*/);
            }
        }

        void showTimes(/*std :: string format*/)
        {
            for (DateTime *datetime_ : scheduledDateTimes_)
            {
                std :: cout << "\n" << datetime_ -> displayDate("DD-MM-YYYY"/*format1*/) << datetime_ -> displayTime(/*format2*/);
            }
        }
};

class Sponsor : public User {
    private:
        std :: string sponsored_event_;
        double amount_;
    
    public:
        Sponsor(std::string name, short int age, std::string regNO, std::string gender, 
        std::string username, std::string password, std::string email, std :: string event, double amt) 
        : User(name, age, regNO, gender, username, password, email),
        sponsored_event_(event), amount_(amt) {};
        Sponsor(User &user) : User(user), amount_(0.0){};

        std :: string getEventName(){return sponsored_event_;}

        void display() const override
        {
            std :: cout << "Sponsor: ";
            User :: display();
            std :: cout << ", Event: " << sponsored_event_ << ", Amount: ₹" << amount_;
        }
        void sponsorConference() 
        {
            double sponsored_amount;
            std :: cout << "\nEnter the amount to sponsor: ";
            std :: cin >> sponsored_amount;
            Conference* conference = Conference :: getConferenceByName(sponsored_event_);
            
            for (Sponsor* sponsor : conference -> getSponsors()) 
            {
                if (sponsor == this) {
                    // Conference already sponsored, update sponsorship amount

                    conference -> updateSponsoredAmount(sponsored_amount, amount_);
                    std::cout << "\nSponsorship amount for the conference updated successfully.";
                    return;
                }
            }
            // Conference not sponsored yet, sponsor it
            conference -> updateSponsoredAmount(sponsored_amount);
            std::cout << "\nConference sponsored successfully.";
        }

        double getSponsoredAmount() const 
        {
            return amount_;
        } 
};