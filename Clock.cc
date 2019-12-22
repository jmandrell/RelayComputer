#include <unistd.h>

#include "Clock.h"

Clock* Clock::clocks[16];
unsigned int Clock::clockCount = 0;
pthread_t Clock::thread;
Io Clock::runInput;
Io Clock::stepInput;

static bool started = false;

Clock::Clock() {
	clocks[clockCount++] = this;
	if (!started) {
		started = true;
		pthread_create(&thread, 0, ClockThread, 0);
	}
}

void* Clock::ClockThread(void*) {
	for (;;) {
		while (runInput.GetOutput()) {
			usleep(1000000);
			DoTick();
		}
		while (!runInput.GetOutput()) {
			// not running, check for Single step
			static bool lastStepState = false;
			bool currentState = stepInput.GetOutput();
			if (currentState != lastStepState) {
				if (currentState) {
					DoTick();
				}
				lastStepState = currentState;
			}
			usleep(50000);
		}
	}
}

void Clock::DoTick() {
	for (unsigned int i = 0; i < clockCount; ++i) {
		clocks[i]->Tick();
	}
}
