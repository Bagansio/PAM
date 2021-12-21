#include "Person.h"

Person::Person() {
	startTime = liveTime = -1;


}

Person::Person(double currentTime) {
	startTime = currentTime;
	liveTime = -1;
}


void Person::setStayTime(double time) {
	liveTime = time - startTime;
}

