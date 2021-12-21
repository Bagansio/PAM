#include "Scheduler.h"
#include "Sink.h"


Sink::Sink() {
	peopleOut = 0;
	state = SERVICE;
	timeAv = 0;
}

void Sink::treateEvent(Event event) {
	if (event.type == TRANSFER) {
		++peopleOut;
		event.person.setStayTime(event.currentTime);
		timeAv = (timeAv + event.person.liveTime);
	}
}

void Sink::simulationStart(Scheduler* scheduler) {
	peopleOut = 0;
	state = SERVICE;
	timeAv = 0;
	this->scheduler = scheduler;
}

void Sink::summary() {
	cout << "Clientes salidos del sistema ";
	cout << peopleOut << endl;
	cout << "Tiempo medio en el sistema ";
	if (peopleOut == 0)
		cout << 0;
	else
		cout << timeAv / peopleOut;
	cout  << endl;
}



