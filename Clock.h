#ifndef CLOCK_H
#define CLOCK_H

#include <pthread.h>

#include "Io.h"

class Clock {
public:
	Clock();
	virtual void Tick() = 0;
	static Io runInput;
	static Io stepInput;
	static Io resetInput;
	static Io haltInput;
	static int clockDelay;

private:
	static void DoTick();
	static void* ClockThread(void*);
	static Clock* clocks[16];
	static unsigned int clockCount;
	static pthread_t thread;
};
#endif
