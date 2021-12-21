#ifndef SOURCE_HH
#define SOURCE_HH

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "States.h"
#include "Event.h"
#include <cmath>


using namespace std;

class Scheduler;
class Queue;

class Source
{
public:
	long clientsCreated;
	default_random_engine generator;
	normal_distribution<double> distribution;
	States state;
	Scheduler* scheduler;


	void treateEvent(Event e);

	void simulationStart(Scheduler* scheduler, double arrivalTimeMean, double arrivalTimeDev);

	void processNextArrival(Event e);

	void nextArrival(double temps);

	void summary();
};

#endif