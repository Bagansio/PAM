
#ifndef QUEUE_HH
#define QUEUE_HH



#include <iostream>
#include <vector>
#include "Event.h"
#include "Person.h"
#include "States.h"
#include <queue>

using namespace std;
class Scheduler;
class Queue {

public:
	long totalClients;
	Scheduler* scheduler;
	bool schedulerStepIn;
	queue<Person> queue;
	States state;

	Queue();

	void treateEvent(Event event);

	void simulationStart(Scheduler* scheduler);

	void summary();
};

#endif