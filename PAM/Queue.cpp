#include "Queue.h"

void Queue::inicialitza(Scheduler* scheduler, string numerocaixa, StateType state, int pasdeVehicles, bool veuretraza) {
	this->entitatsArribades = 0;
	this->scheduler = scheduler;
	this->schedullerStepIn = false;
	this->numerocaixa = numerocaixa;
	this->veuretraza = veuretraza;
	this->pasdeVehicles = pasdeVehicles;
	this->cua = vector<Person>();
	this->state = state;
}

void Queue::setState(States state) { this->state = state; }

void Queue::setQueue(vector<Person> cua) { this->cua = cua; }

void Queue::tractarEsdeveniment(Event event) {
	if (this->state == States.LOCK) {
		this->tractarEsdevenimentLOCK(event);
	}
	else {
		this->tractarEsdevenimentUNLOCK(event);
	}
}

void Queue::simulationStart() {
	this->entitatsArribades = 0;
}

void Queue::tractarEsdevenimentLOCK(Event event) {
	if (event == Events.Access) {
		if (!this->schedullerStepIn) {
			this->programarProperStepIn(event);
		}
		this->setState(States.UNLOCK);
	}

	if (event == Events.Tranfer) {
		this->cua.push_back(event.person);
		this->entitatsArribades++;
	}
}

void Queue::tractarEsdevenimentUNLOCK(Event event) {
	if (event.type == Events.Access) this->setState(States.LOCK);

	if (event.type == Events.Tranfer) {
		if (!this->schedullerStepIn) this->programarProperStepin(event);
		this->cua.push_back(event.person);
		this->entitatsArribades++;
	}
	if (event.type == Events.StepIn) {
		if (this->cua.size() > 0) {
			this->personaActiva = this->cua.back();
			this->programarTransfer(event, this->personaActiva);
			this->programarProperStepin(event);
		}
		else {
			this->schedullerStepIn = false;
		}
	}
}

void Queue::programarTransfer(Event event, Person person) {
	event = Event(event.tid, Events.Tranfer, person);
	this->scheduler.afegirEsdeveniment(event);
}

void Queue::programarProperStepin(Event event) {
	this->schedullerStepIn = true;
	event = Event(event.tid + this->pasdeVehicles, Events.StepIn, NULL);
}

void Queue::summary() {
	cout << "Entitats arribades: " << this->entitatsArribades << endl << "Entitats encuades: " << this->cua.size() << endl;
}