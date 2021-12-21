#ifndef PERSON_HH
#define PERSON_HH

class Person {
public:
	double liveTime;
	double startTime;

	void setStayTime(double time);

	Person();

	Person(double currentTime);
};

#endif