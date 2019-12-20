#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Register16.h"


int main() {
	TestHarness harness;
	Register16 reg16("reg16");
	Bus16 input("Input");
	Bus16 output("Output");
	Io enable;
	Io capture;
	
	reg16.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	reg16.AttachCapture(&capture);
	harness.AddInput("Capture", &capture);
	reg16.AttachInputBus(&input);
	harness.AddInputBus16("Input", &input);

	reg16.AttachOutputBus(&output);
	harness.AddOutputBus16("Output", &output);
	
	harness.Run();
	return 0;
}
