#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include "Event.h"
#include "Person.h"
#include "States.h"
#include "Scheduler.h"
using namespace std;

class Processor {
public:
	int pos;
	States state;
	Scheduler* scheduler;
	double processorTime;
	long clientsProcessed;

	void treateEvent(Event event);

	void simulationStart(Scheduler* scheduler,int pos);

	void summary();
};