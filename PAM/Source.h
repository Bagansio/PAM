#ifndef SOURCE_HH
#define SOURCE_HH

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "States.h"
#include "Event.h"



using namespace std;

class Scheduler;
class Queue;

class Source
{
public:
	long clientsCreated;
	double arrivalTimeMean;
	double arrivalTimeDev;
	States state;
	Scheduler* scheduler;


	void treateEvent(Event e);

	void simulationStart(Scheduler* scheduler, double arrivalTimeMean, double arrivalTimeDev);

	void processNextArrival(Event e);

	void nextArrival(double temps);

	void summary();
};

#endif