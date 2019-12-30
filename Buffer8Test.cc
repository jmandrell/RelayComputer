#include "TestHarness.h"
#include "Buffer8.h"

int main() {
	TestHarness harness;
	Buffer8 buf8("buf8");
	Bus8 input("input");
	Bus8 output("output");
	Io enable;
	
	buf8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	buf8.AttachInputBus(&input);
	harness.AddInput("Input", &input);
	
	buf8.AttachOutputBus(&output);
	harness.AddOutput("Output", &output);
	
	harness.Run();
	return 0;
}
