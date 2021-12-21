#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "States.h"
#include "Event.h"
#include "Scheduler.h"
#include "Queue.h"

using namespace std;

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
