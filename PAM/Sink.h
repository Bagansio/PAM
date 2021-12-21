
#pragma once
#include "Event.h"
#include "States.h"
#include "Scheduler.h"

class Sink {
public:
	long peopleOut;
	States state;
	Scheduler* scheduler;

	double timeAv;

	void treateEvent(Event event);

	Sink();

	void simulationStart(Scheduler* scheduler);

	void getStadistics();
};

