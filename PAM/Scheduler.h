#ifndef SCHEDULER_HH
#define SCHEDULER_HH

#include <iostream>
#include <queue>
#include "Event.h"
#include "Sink.h"

using namespace std;

class Scheduler {
public:
	double currentTime;
	queue<Event> eventList;
	double simulationTime;
	double arrivalTimeMean;
	double arrivalTimeDev;

	Scheduler();

	void configure();
	void createModel();
	void getStadistics();

	void run();
	//void addEvent(Event event);
	void treateEvent(Event event);
	

};

#endif