#include "Processor.h"
#include "TestHarness.h"

int main() {
	TestHarness harness;
	Processor processor;
		
	harness.AddInput("Run", &Clock::runInput);
	harness.AddInput("Step", &Clock::stepInput);
	
	harness.Run();
	return 0;
}
