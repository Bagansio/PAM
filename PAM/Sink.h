#ifndef SINK_HH
#define SINK_HH

#include "Event.h"
#include "States.h"

class Sink {
public:
	long peopleOut;
	States state;

	double timeAv;

	void treateEvent(Event event);

	Sink();

	void simulationStart();

	void getStadistics();
};

#endif