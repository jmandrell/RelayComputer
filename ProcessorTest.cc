#include "Processor.h"
#include "TestHarness.h"

int main() {
	TestHarness harness;
	Processor processor;
	Io enable;
	
	harness.AddOutput("Sequence 0", processor.sequencer.Get0());
	harness.AddOutput("Sequence 1", processor.sequencer.Get1());
	harness.AddOutput("Sequence 2", processor.sequencer.Get2());
	harness.AddOutput("Sequence 3", processor.sequencer.Get3());
	harness.AddOutput("Sequence 4", processor.sequencer.Get4());
	harness.AddOutput("Sequence 5", processor.sequencer.Get5());
	harness.AddOutput("Sequence 6", processor.sequencer.Get6());
	harness.AddOutput("Sequence 7", processor.sequencer.Get7());
	
	processor.pc.AttachEnable(&enable);
	// a dummy input just to allow this to work
	harness.AddInput("Enable", &enable);
	
	harness.Run();
	return 0;
}
