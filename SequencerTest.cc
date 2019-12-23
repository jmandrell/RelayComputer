#include "Sequencer.h"
#include "TestHarness.h"

int main() {
	TestHarness harness;
	Sequencer sequencer("sequencer");
	Io clear;
	Bus16 sequencerBus("sequencerBus");
	
	sequencer.AttachOutputBus(&sequencerBus);
	
	sequencer.AttachClear(&clear);
	harness.AddInput("Clear", &clear);
	harness.AddInput("Run", &Clock::runInput);
	harness.AddInput("Step", &Clock::stepInput);
	
	harness.Run();
	return 0;
}
