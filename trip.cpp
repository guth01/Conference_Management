#include <iostream>

class Trip
{
    // Class for generating a trip

    // properties

    Transport transport
        // the following could be just part of this as well
        
        // Seat Details could be a method
        // and func could be implemented for finding out
        // the availability of a seat

        DateTime datetime;
        // Should include subclasses for Date and Time
        // this is related to Transport class because each transport
        // has its own time of reaching a destination
        // (there is list of destinations in an instance of a 
        // child Transpost class for example the train ABC has
        // 10 diff destinations with different times)

        String destination;
        // destination should only be one and should be available
        // in an instance of the child of a transport class


    Transc bill;
    // transaction should include details about the bill,
    // vouchers used, and should include functions finding fetching
    // price, time of transaction, successful transaction or not,
    // if package is used use the data from that into transc class

    User user;
    // should have initailly propmpted for a sign in which uses
    // encapsulated data from a the instances of the User
    // should check for appropriate age

    Passenger passengers[n];
    // Passenger list should contain name and age



    Trip(/*Trip Intialisers*/);

    void getTripDetails(){};
    void editPassengerList(){};
    void changeTrain(){};
    void changeDestination(){};
    void changeTime(){};
};