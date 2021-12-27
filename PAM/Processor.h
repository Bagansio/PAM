#ifndef PROCESSOR_HH
#define PROCESSOR_HH
#include "States.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include "Event.h"
#include "Person.h"



using namespace std;

class Scheduler;

class Processor {
public:
	int pos;
	double proccessingTime;
	double plusTime;
	States state;
	Scheduler* scheduler;
	default_random_engine generator;
	normal_distribution<double> distribution;
	long clientsProcessed;

	void treateEvent(Event event);

	void simulationStart(Scheduler* scheduler,int pos);

	void summary();
};
#endif