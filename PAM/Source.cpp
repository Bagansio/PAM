#include "Scheduler.h"
#include "Queue.h"
#include "Source.h"


void Source::treateEvent(Event e) {
	if (e.type == NEXT_ARRIVAL) 
		this->processNextArrival(e);
}

void Source::simulationStart(Scheduler* scheduler, double arrivalTimeMean, double arrivalTimeDev) {
	clientsCreated = 0;
	state = SERVICE;
	this->scheduler = scheduler;
	this->arrivalTimeMean = arrivalTimeMean;
	this->arrivalTimeDev = arrivalTimeDev;
	this->nextArrival(0);
}


void Source::processNextArrival(Event e) {
	this->nextArrival(e.currentTime);
	this->clientsCreated++;
	Person person(e.currentTime);
	(*scheduler).eventList.push(Event(e.currentTime, NEXT_ARRIVAL, person, QUEUE, NULL));
}

void Source::nextArrival(double time) {
	(*scheduler).eventList.push(Event(time + this->arrivalTimeMean, NEXT_ARRIVAL, NULL, SOURCE, NULL));
}

void Source::summary() {
	cout << "Clientes generados en el sistema: " << this->clientsCreated << endl;
}