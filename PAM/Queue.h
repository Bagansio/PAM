#pragma once
#include <iostream>
#include <vector>
#include "Scheduler.h"
#include "Event.h"
#include "Person.h"
#include "States.h"
#include <queue>

using namespace std;

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
