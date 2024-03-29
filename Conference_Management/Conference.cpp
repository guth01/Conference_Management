#include <iostream>
#include <string>
#include "DateTime.h"
#include "Venue.h"


using namespace std;

class Conference
{
    DateTime datetime;
    Venue venue;
    Organiser organisers[n];
    Participant participants[m];
    Sponser sponsers[l];
    double generated_amt;
    string conferenceID;
    static int no_of_conferences;
};

