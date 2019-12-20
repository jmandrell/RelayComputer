#include <unistd.h>

#include "Clock.h"

Clock* Clock::clocks[16];
unsigned int Clock::clockCount = 0;
pthread_t Clock::thread;
static bool started = false;

Clock::Clock() {
	clocks[clockCount++] = this;
	if (!started) {
		started = true;
		pthread_create(&thread, 0, ClockThread, 0);
	}
}

void* Clock::ClockThread(void*) {
	bool tick = false;
	for (;;) {
		usleep(1000000);
		for (unsigned int i = 0; i < clockCount; ++i) {
			if (tick) {
				clocks[i]->Tock();
				tick = false;
			} else {
				clocks[i]->Tick();
				tick = true;
			}
		}
	}
}
