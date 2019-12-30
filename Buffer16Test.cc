#include "TestHarness.h"
#include "Buffer16.h"

int main() {
	TestHarness harness;
	Buffer16 buf16("buf16");
	Bus16 input("input");
	Bus16 output("output");
	Io enable;
	
	buf16.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	buf16.AttachInputBus(&input);
	harness.AddInput("Input", &input);
	
	buf16.AttachOutputBus(&output);
	harness.AddOutput("Output", &output);
	
	harness.Run();
	return 0;
}
