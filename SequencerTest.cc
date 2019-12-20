#include "Sequencer.h"
#include "TestHarness.h"

int main() {
	TestHarness harness;
	Sequencer sequencer("sequencer");
	Io clear;
	
	sequencer.AttachClear(&clear);
	harness.AddInput("Clear", &clear);
	harness.AddOutput("Select 0", sequencer.Get0());
	harness.AddOutput("Select 1", sequencer.Get1());
	harness.AddOutput("Select 2", sequencer.Get2());
	harness.AddOutput("Select 3", sequencer.Get3());
	harness.AddOutput("Select 4", sequencer.Get4());
	harness.AddOutput("Select 5", sequencer.Get5());
	harness.AddOutput("Select 6", sequencer.Get6());
	harness.AddOutput("Select 7", sequencer.Get7());
	
	harness.Run();
	return 0;
}
