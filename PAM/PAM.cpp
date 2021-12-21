// PAM.cpp: define el punto de entrada de la aplicación.
//

#include "PAM.h"
#include "Scheduler.h"
#include "Event.h"

using namespace std;

int main()
{
	Scheduler scheduler;
	scheduler.run();
	return 0;
}
