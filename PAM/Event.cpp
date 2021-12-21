#include "Event.h"

Event::Event(double currentTime, EventType type, Person person, EventFather father, int fatherPos) {
	this->currentTime = currentTime;
	this->type = type;
	this->person = person;
	this->father = father;
	this->fatherPos = fatherPos;
	treatedEntities = 0;
}

string Event::toString() {
	return  to_string(currentTime) + " " ;
}