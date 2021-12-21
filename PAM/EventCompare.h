#include "Event.h"

struct EventCompare {
    bool operator()(Event const& e1, Event const& e2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        //cout << e1.currentTime << " " << e2.currentTime << " " << (e1.currentTime < e2.currentTime) << endl;
        return e1.currentTime > e2.currentTime;
    }
};