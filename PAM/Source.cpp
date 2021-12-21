#include "Source.h"

void Source::inicialitza(Scheduler* scheduler, int parameter) {
	this->EntitatsCreades = 0;
	this->state = Enumeration.SERVICE;
	this->scheduler = scheduler;
	this->parameter = parameter;
	this->caixes = vector<Queue>;
}

void Source::actualitzaCaixes(vector<Queue> caixes) {
	this->caixes = caixes;
}

void Source::tractarEsdeveniment(Event e) {
	if (e.type == EventType.NextArrival) 
		this->processNextArrival(e);
}

void Source::simulationStart() {
	EntitatsCreades = 0;
	this->properaArribada(0);
}

void Source::processNextArrival(Event e) {
	this->properaArribada(e.tid);
	this->EntitatsCreades++;
	Person person(e.tid);
	this->scheduler->afegirEsdeveniment(Event(this->caixes[person.fila], e.tid, EventType.Transfer, person));
}

void Source::properaArribada(int temps) {
	this->scheduler.afegirEsdeveniment(Event(temps+this->parameter, EventType.NextArrival, NULL))
}

void Source::summary() {
	cout << "Entitats generades en el sistema: " << this->EntitatsCreades << endl;
}