#include "Sink.h"

Sink::Sink() {
	peopleOut = 0;
	state = SERVICE;
	timeAv = 0;
}

void Sink::treateEvent(Event event) {
	if (event.type == TRANSFER) {
		//double avg = timeAv * peopleOut;
		++peopleOut;
		event.person.setStayTime(event.currentTime);
		timeAv = (timeAv + event.person.liveTime) / peopleOut;
	}
}

void Sink::simulationStart(Scheduler* scheduler) {
	peopleOut = 0;
	state = SERVICE;
	timeAv = 0;
	this->scheduler = scheduler;
}




