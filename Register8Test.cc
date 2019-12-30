#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Register8.h"


int main() {
	TestHarness harness;
	Register8 reg8("reg8");
	Bus8 input("Input");
	Bus8 output("Output");
	Io enable;
	Io capture;
	
	reg8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	reg8.AttachCapture(&capture);
	harness.AddInput("Capture", &capture);
	reg8.AttachInputBus(&input);
	harness.AddInput("Input", &input);

	reg8.AttachOutputBus(&output);
	harness.AddOutput("Output", &output);
	
	harness.Run();
	return 0;
}
