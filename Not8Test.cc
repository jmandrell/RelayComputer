#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Not8.h"


int main() {
	TestHarness harness;
	Not8 not8("not8");
	Io enable;
	Bus8 input("Input");
	Bus8 output("Output");
	
	not8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	
	not8.AttachInputBus(&input);
	harness.AddInput("Input", &input);

	not8.AttachOutputBus(&output);
	harness.AddOutput("Output", &output);

	harness.Run();
	return 0;
}
