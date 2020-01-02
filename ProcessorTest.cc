#include "Processor.h"
#include "TestHarness.h"
#include "Clock.h"
#include "Components.h"
#include <time.h>

class MemoryReader : public  TestHarness::Callback {
public:
	MemoryReader() {
		std::cerr << "Constructing MemoryReader" << std::endl;
	}
	unsigned char Read(unsigned int address) {
		return Components::memory.ReadMem(address);
	}
};


int main() {
	TestHarness harness;
	Processor processor;
	MemoryReader memoryReader;

	harness.AddInput("Run", &Clock::runInput);
	harness.AddInput("Step", &Clock::stepInput);
	harness.AddInput("Reset", &Clock::resetInput);
	harness.AddInt("Delay between clock cycles", &Clock::clockDelay);

	for (unsigned int i = 0xfff0; i <= 0xffff; ++i) {
		harness.Add7SegmentDisplay(i, &memoryReader);
	}

	harness.Run();
	return 0;
}
