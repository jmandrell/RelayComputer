#include "Processor.h"
#include "TestHarness.h"
#include "Clock.h"


int main() {
	TestHarness harness;
	Processor processor;
		
	harness.AddInput("Run", &Clock::runInput);
	harness.AddInput("Step", &Clock::stepInput);
	harness.AddInt("Delay between clock cycles", &Clock::clockDelay);
	harness.Run();
	return 0;
}
