#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Increment8.h"


int main() {
	TestHarness harness;
	Increment8 adder("adder");
	Bus8 input("Input");
	Bus8 output("Output");
	Io enable;
	
	adder.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	adder.AttachInputBus(&input);
	harness.AddInput("Input", &input);

	adder.AttachOutputBus(&output);
	harness.AddOutput("Sum", &output);
	harness.AddOutput("Carry out", adder.GetCarryOut());
	
	harness.Run();
	return 0;
}
