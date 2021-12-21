#ifndef SINK_HH
#define SINK_HH


#include "Event.h"
#include "States.h"

using namespace std;

class Scheduler;

class Sink {
public:
	long peopleOut;
	States state;

	Scheduler* scheduler;

	double timeAv;

	void treateEvent(Event event);

	Sink();

	void simulationStart(Scheduler* scheduler);

	void summary();
};

#endif