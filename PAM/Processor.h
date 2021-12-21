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
	States state;
	Scheduler* scheduler;
	int tempsCicle;
	int ciclesTotals;
	vector<Person> cua;

	void inicialitza(Scheduler* scheduler, int parameter);

	void tractarEsdeveniment(Event event);

	void simulationStart();

	void summary();
};