#ifndef CLOCK_H
#define CLOCK_H

#include <pthread.h>

class Clock {
public:
	Clock();
	virtual void Tick() = 0;
	
private:
	static void* ClockThread(void*);
	static Clock* clocks[16];
	static unsigned int clockCount;
	static pthread_t thread;
};
#endif
