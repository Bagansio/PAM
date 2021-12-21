#include "Processor.h"

void Processor::inicialitza(Scheduler* scheduler, int parameter) {
	this->state = States.ACCESS;
	this->scheduler = scheduler;
	this->tempsCicle = parameter;
	this->ciclesTotals = 0;
	this->cua = vector<Person>();
}

void Processor::tractarEsdeveniment(Event event) {
	if (event.type == Events.Access1) {
		if (this->state == States.ACCESS1) {
			this->state = States.ACCESS2; //ni idea//
			this->scheduler.afegirEsdeveniment(cua[2], event.tid, Events.ACCESS, NULL);
			this->scheduler.afegirEsdeveniment(cua[3], event.tid, Events.ACCESS, NULL);
		}
		else if (this->state == States.ACCESS2) {
			this->state = States.ACCESS2; //ni idea//
			this->scheduler.afegirEsdeveniment(cua[3], event.tid, Events.ACCESS, NULL);
			this->scheduler.afegirEsdeveniment(cua[4], event.tid, Events.ACCESS, NULL);
		}
		else if (this->state == States.ACCESS3) {
			this->state = States.ACCESS2; //ni idea//
			this->scheduler.afegirEsdeveniment(cua[4], event.tid, Events.ACCESS, NULL);
			this->scheduler.afegirEsdeveniment(cua[1], event.tid, Events.ACCESS, NULL);
		}
		else if (this->state == States.ACCESS4) {
			this->state = States.ACCESS2; //ni idea//
			this->scheduler.afegirEsdeveniment(cua[1], event.tid, Events.ACCESS, NULL);
			this->scheduler.afegirEsdeveniment(cua[2], event.tid, Events.ACCESS, NULL);
		}
		this->scheduler.afegirEsdeveniment(Event(event.tid + this->tempsCicle), Events.Access, NULL);
		this->ciclesTotals++;
	}
}

void Processor::simulationStart() {
	this->state = States.ACCESS1;
	this->scheduler.afegirEsdeveniment(Event(this->tempsCicle, Events.Access, true);
	this->ciclesTotals = 0;
}

void Processor::summary() {
	cout << "Nombre de cicles realitzats: " << this->ciclesTotals;
}