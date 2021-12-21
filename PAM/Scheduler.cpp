#include "Scheduler.h"

Scheduler::Scheduler() {
	currentTime = 0;
	simulationTime = 100;
	arrivalTimeMean = 2;
	arrivalTimeDev = 0.1;
}

void Scheduler::configure() {
	cout << "Pidiendo parametros del simulador de una caja del McDonals" << endl;

	bool error = true;

	while (error) {
		cout << "Tiempo de Simulacion:" << endl;
		cin >> simulationTime;
		cout << "Tiempo medio entre llegadas:" << endl;
		cin >> arrivalTimeMean;
		cout << "Desviacion entre llegadas:" << endl;
		cin >> arrivalTimeDev;

		if (arrivalTimeDev < 0 || simulationTime < 0 || arrivalTimeMean < 0) {
			cout << "ERROR: LOS TIEMPOS Y DESVIACIÓN DEBEN SER POSITIVOS" << endl;
		}
		else {
			error = false;
		}
	}
}


void Scheduler::createModel() {
	//create source
	//create queue
	//create List/array procesors
	//create sink
	eventList = queue<Event>();
	Event startEvent = Event(0, STARTSIM, NULL,SCHEDULER, NULL);
	eventList.push(startEvent);

}

void Scheduler::run() {
	configure();
	createModel();

	currentTime = 0;

	while (currentTime < simulationTime) { //simulate
		
		Event event = eventList.front();
		eventList.pop();

		currentTime = event.currentTime;

		switch (event.father) {
			case SCHEDULER:
				treateEvent(event);
				break;
			case QUEUE:
				//calls to queue.treateEvent(event)
				break;

			case SINK:
				break;

			case SOURCE:
				break;

			default:
				break;
		}

		//trace

		//event.father.tractaEsdeveniment(event);

	}

	getStadistics();
}

void Scheduler::getStadistics() {
	cout << "ESTADISTICOS:" << endl;

	//por cada cosa un estadistico, por ello el array de procesors el ultimo
}


void Scheduler::treateEvent(Event event) {
	if (event.type == STARTSIM){
		currentTime = simulationTime;
		//calls to simulationStart function of each member
	}
}
