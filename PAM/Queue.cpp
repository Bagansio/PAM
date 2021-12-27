#include "Scheduler.h"
#include "Queue.h"



Queue::Queue() {

}

void Queue::simulationStart(Scheduler* scheduler) {
	this->totalClients = 0;
	this->scheduler = scheduler;
	this->schedulerStepIn = false;
	this->state = SERVICE;
}

void Queue::treateEvent(Event event) {
	switch (event.type) {
		case TRANSFER:
			queue.push(event.person);
			++totalClients;
			break;
		case NEXT_ARRIVAL:
			if (! queue.empty()) {
				(*scheduler).eventList.push(Event(event.currentTime, PROCESS, queue.front(), PROCESSOR, event.fatherPos));
				queue.pop();
			}
			else {
				(*scheduler).eventList.push(Event(event.currentTime + 1, GET_CLIENT, NULL, PROCESSOR, event.fatherPos));
			}
			break;
		default:
			break;
	}
}



void Queue::summary() {
	cout << "QUEUE:" << endl;
	cout << "Clientes que han salido de la cola: " << this->totalClients  - this->queue.size() << endl << "Clientes en cola: " << this->queue.size() << endl;
	cout << "---------------------------" << endl;
}