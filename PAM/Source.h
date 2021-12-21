#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Enumeration.h"
#include "Event.h"
#include "Scheduler.h"
#include "Queue.h"

using namespace std;

class Source
{
	int EntitatsCreades, parameter;
	Enumeration state;
	Scheduler* scheduler;
	vector<Queue> caixes;

	void inicialitza(Scheduler* scheduler, int parameter);

	void actualitzaCaixes(vector <Queue> caixes);

	void tractarEsdeveniment(Event e);

	void simulationStart();

	void processNextArrival(Event e);

	void properaArribada(int temps);

	void summary();
};
