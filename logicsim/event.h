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
    if (!E1) return false;
    else if (!E2) return true;

    return (E1->time < E2->time);
}
} EventLess;
	
#endif
