#include "Scheduler.h"
#include "Processor.h"



void Processor::simulationStart(Scheduler* scheduler, int pos) {
	this->pos = pos;
	this->scheduler = scheduler;
	this->state = IDLE;
	(*scheduler).eventList.push(Event(0, GET_CLIENT, NULL, QUEUE, pos));
	this->distribution = normal_distribution<double>(5.0, 2);
	this->clientsProcessed = 0;
}

void Processor::treateEvent(Event event) {
	switch (event.type) {
	case GET_CLIENT:
		if (this->state == IDLE) {
			(*scheduler).eventList.push(Event(event.currentTime, NEXT_ARRIVAL, NULL, QUEUE, pos));
		}
		break;
	case PROCESS:
		if (this->state == IDLE) {
			state = WORK;
			double plusTime = abs(distribution(generator));
			(*scheduler).eventList.push(Event(event.currentTime + plusTime, PROCESSED, event.person, PROCESSOR, this->pos));
		}
		break;
	case PROCESSED:
		this->state = IDLE;
		++clientsProcessed;
		(*scheduler).eventList.push(Event(event.currentTime, NEXT_ARRIVAL, NULL, QUEUE, pos));
		(*scheduler).eventList.push(Event(event.currentTime, TRANSFER, event.person, SINK, NULL));
		break;

	default:
		break;
	}
}



void Processor::summary() {
	cout << "CAJA: ";
	cout << pos << endl;
	cout << "Numero de clientes procesados en la caja ";
	cout << clientsProcessed << endl;
}