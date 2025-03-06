#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
bool operator()(Event* E1, Event* E2) const {
    if (E1 == nullptr) return false;
    else if (E2 == nullptr) return true;
    else if (E1->time < E2->time) return false;
    else return true;
}
} EventLess;
	
#endif
