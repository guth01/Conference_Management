#include <iostream>
#include <string>

// class User {
//     private:
//         std :: string name;
//         std :: string email;
    
//     public:
//         User(std :: string name, std :: string email): name(name), email(email) {}
        
//         void display()
//         {
//             std :: cout << "Name: " << name << ", Email: " << email;
//         }
// };

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
        // Constructor
        User(std :: string name, short int age, std :: string regNO, std :: string gender, 
            std :: string username, std :: string password, std :: string email)
        : name(name), age(age), regNO(regNO), gender(gender), 
        username(username), password(password), email(email) {}

        // Default Constructor
        User() : age(0) {}

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
        // Password getter not provided for security reasons

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