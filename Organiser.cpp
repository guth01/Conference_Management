#include <iostream>
#include <string>

using namespace std;

class User {
    private:
    string name;
    string email;
    
    public:
    User(string name, string email): name(name), email(email) {}
    
    void display()
    {
        cout << "Name: " << name << ", Email: " << email;
    }
};

class Sponsor : public User {
    private:
    string sponsoredEvent;
    double amount;
    
    public:
    Sponsor(string name, string email, string event, double amt) : User(name, email),
    sponsoredEvent(event), amount(amt) {}

    void display()
    {
        cout << "Sponsor: ";
        User::display();
        cout << ", Event: " << sponsoredEvent << ", Amount: ₹" << amount;
    }
    
};

int main() {
    string name, email, event;
    double amount;
    
    cout << "Enter sponsor's name: ";
    getline(cin, name);
    
    cout << "Enter sponsor's email: ";
    getline(cin, email);
    
    cout << "Enter sponsored event: ";
    getline(cin, event);
    
    cout << "Enter sponsorship amount: ";
    cin >> amount;

    Sponsor sponsor1(name, email, event, amount);
    sponsor1.display();
    
    cout << endl;

    return 0;
    
}