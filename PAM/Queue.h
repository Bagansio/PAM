#pragma once
#include <iostream>
#include <vector>
#include "Scheduler.h"
#include "Event.h"
#include "Person.h"
#include "State.h"

using namespace std;

class Queue {
	int entitatsArribades;
	Scheduler* scheduler;
	Person personaActiva;
	bool schedullerStepIn;
	string numerocaixa;
	bool veuretraza;
	int pasdeVehicles;
	vector<Person> cua;
	States state;

	void inicialitza(Scheduler* scheduler, string numerocaixa, StateType state, int pasdeVehicles, bool veuretraza);

	/** No he hecho _repr_ ni stateStr */

	void setState(States state);

	void setQueue(vector<Person> cua);

	void tractarEsdeveniment(Event event);

	void simulationStart();

	void tractarEsdevenimentLOCK(Event event);

	void tractarEsdevenimentUNLOCK(Event event);

	void programarTransfer(Event event, Person person);

	void programarProperStepin(Event event);

	void summary();
};
