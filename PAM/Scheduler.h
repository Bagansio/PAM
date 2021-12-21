#ifndef SCHEDULER_HH
#define SCHEDULER_HH

#include <iostream>
#include <queue>
#include "Event.h"
#include "EventCompare.h"
#include "Source.h"
#include "Queue.h"
#include "Processor.h"
#include "Scheduler.h"
#include "Sink.h"



using namespace std;

class Scheduler {
public:
	double currentTime;
	priority_queue<Event, vector<Event>, EventCompare> eventList;
	double simulationTime;
	double arrivalTimeMean;
	double arrivalTimeDev;
	int processorsSize;


	
	Source source;
	Queue clientsQueue;
	vector<Processor> processors;
	Sink sink;

	Scheduler();

	void configure();
	void createModel();
	void getStadistics();


	void run();
	//void addEvent(Event event);
	void treateEvent(Event event);
	

};

#endif
