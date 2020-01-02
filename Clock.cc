#include <unistd.h>

#include "Clock.h"
#include "Updatable.h"
#include "Sequencer.h"


Clock* Clock::clocks[16];
unsigned int Clock::clockCount = 0;
pthread_t Clock::thread;
Io Clock::runInput;
Io Clock::stepInput;
Io Clock::resetInput;
Io Clock::haltInput;
int Clock::clockDelay = 1000000;

static bool started = false;

Clock::Clock() {
	clocks[clockCount++] = this;
	if (!started) {
		started = true;
		pthread_create(&thread, 0, ClockThread, 0);
	}
}

void* Clock::ClockThread(void*) {
	int localDelay = clockDelay;
	for (;;) {
		usleep(localDelay);
		// check if we're forcing all outputs to 0
		if (resetInput.GetOutput()) {
			Io::ForceReset(true);
			Updatable::DoUpdate();
			Io::ForceReset(false);
			Sequencer::Reset();
		} else if (haltInput.GetOutput()) {
			continue;
		} else if (runInput.GetOutput()) {
			// make sure we have an update across all relays
			Updatable::DoUpdate();
			Updatable::DoUpdate();
			DoTick();
			localDelay = clockDelay;
		} else {
			// not running, check for Single step
			static bool lastStepState = false;
			bool currentState = stepInput.GetOutput();
			if (currentState != lastStepState) {
				if (currentState) {
					DoTick();
				}
				lastStepState = currentState;
			}
			localDelay = 5000;
		}
	}
}

void Clock::DoTick() {
	for (unsigned int i = 0; i < clockCount; ++i) {
		clocks[i]->Tick();
	}
}
