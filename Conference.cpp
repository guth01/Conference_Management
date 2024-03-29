#include <iostream>
#include <string>
#include "DateTime.h"
#include "Venue.h"
#include "Sponsor.h"
#include "Participant.h"
#include "Organiser.h"


using namespace std;

class Conference
{
    DateTime datetime;
    Venue venue;
    Organiser organisers[30];
    Participant participants[500];
    Sponsor sponsors[20];
    double generated_amt;
    string conferenceID;
    static int no_of_conferences;
};

