// PAM.cpp: define el punto de entrada de la aplicación.
//

#include "PAM.h"
#include "Scheduler.h"

using namespace std;

int main()
{
	Scheduler scheduler;
	scheduler.run();
	return 0;
}
