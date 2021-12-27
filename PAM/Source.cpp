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
	this->distribution = normal_distribution<double>(arrivalTimeMean, arrivalTimeDev);
	this->scheduler = scheduler;
	this->nextArrival(0);
}


void Source::processNextArrival(Event e) {
	
	this->clientsCreated++;
	Person person(e.currentTime);
	(*scheduler).eventList.push(Event(e.currentTime, TRANSFER, person, QUEUE, NULL));
	this->nextArrival(e.currentTime);
}

void Source::nextArrival(double time) {
	double plusTime = abs(distribution(generator));
	(*scheduler).eventList.push(Event(time + plusTime, NEXT_ARRIVAL, NULL, SOURCE, NULL));
}

void Source::summary() {
	cout << "SOURCE:" << endl;
	cout << "Clientes generados en el sistema: " << this->clientsCreated << endl;
	cout << "---------------------------" << endl;
}