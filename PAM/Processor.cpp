#include "Scheduler.h"
#include "Processor.h"



void Processor::simulationStart(Scheduler* scheduler, int pos) {
	this->pos = pos;
	this->scheduler = scheduler;
	this->state = IDLE;
	(*scheduler).eventList.push(Event(0, GET_CLIENT, NULL, QUEUE, pos));
	this->processorTime = 5;
	this->clientsProcessed = 0;
}

void Processor::treateEvent(Event event) {
	switch (event.type) {
	case PROCESS:
		if (this->state == IDLE) {
			state = WORK;
			(*scheduler).eventList.push(Event(event.currentTime + this->processorTime, PROCESSED, event.person, PROCESSOR, this->pos));
		}
		break;
	case PROCESSED:
		this->state = IDLE;
		(*scheduler).eventList.push(Event(event.currentTime, GET_CLIENT, NULL, QUEUE, pos));
		(*scheduler).eventList.push(Event(event.currentTime, NEXT_ARRIVAL, event.person, SINK, NULL));
		break;

	default:
		break;
	}
}



void Processor::summary() {
	cout << "CAJA " + pos << endl;
	cout << "Numero de clientes procesados en la caja "  + clientsProcessed << endl;
}