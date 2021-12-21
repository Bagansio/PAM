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
		cout << "Numero de cajeros:" << endl;
		cin >> processorsSize;

		if (arrivalTimeDev < 0 || simulationTime < 0 || arrivalTimeMean < 0 || processorsSize < 0) {
			cout << "ERROR: LOS TIEMPOS, DESVIACIÓN  Y NUMERO DE CAJEROS DEBEN SER MAYOR QUE CERO" << endl;
		}
		else {
			error = false;
		}
	}
}


bool compare(Event a, Event b) {
	return a.currentTime < b.currentTime;
}

void Scheduler::createModel() {


	source.simulationStart(this, arrivalTimeMean, arrivalTimeDev);
	sink.simulationStart(this);
	clientsQueue.simulationStart(this);

	processors = vector<Processor>(processorsSize);

	for (int i = 0; i < processorsSize; ++i) {
		processors[i].simulationStart(this, i);
	}

	eventList = priority_queue<Event, vector<Event>, EventCompare>();
	Event startEvent = Event(0, STARTSIM, NULL,SCHEDULER, NULL);
	eventList.push(startEvent);

}

void Scheduler::run() {
	configure();
	createModel();

	currentTime = 0;

	while (currentTime < simulationTime) { //simulate
		
		Event event = eventList.top();
		eventList.pop();

		currentTime = event.currentTime;

		switch (event.father) {
			case SCHEDULER:
				treateEvent(event);
				break;

			case QUEUE:
				clientsQueue.treateEvent(event);
				break;

			case SINK:
				sink.treateEvent(event);
				break;

			case SOURCE:
				source.treateEvent(event);
				break;

			case PROCESSOR:
				processors[event.fatherPos].treateEvent(event);
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
		eventList.push(Event(0, NEXT_ARRIVAL, NULL, SOURCE, NULL));
	}
}
