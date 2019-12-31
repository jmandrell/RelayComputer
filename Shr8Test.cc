#include "TestHarness.h"
#include "Shr8.h"

int main() {
	TestHarness harness;
	Shr8 shr8("shr8");
	Bus8 input("input");
	Bus8 output("output");
	Io enable;
	
	shr8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	shr8.AttachInputBus(&input);
	harness.AddInput("Input", &input);
	
	shr8.AttachOutputBus(&output);
	harness.AddOutput("Output", &output);
	
	harness.Run();
	return 0;
}
