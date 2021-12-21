#ifndef EVENT_HH
#define EVENT_HH

#include "Person.h"
#include "Event.h"
#include <iostream>
#include <string>
#include "EventFather.h"
#include "EventType.h"

using namespace std;

class Event {
public:
	int treatedEntities;
	double currentTime;
	EventType type;
	Person person;
	EventFather father;
	int fatherPos;

	Event(double currentTime, EventType type, Person person, EventFather father, int fatherPos);


	string toString();

};

#endif