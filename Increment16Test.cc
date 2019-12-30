#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Increment16.h"


int main() {
	TestHarness harness;
	Increment16 adder("adder");
	Bus16 input("Input");
	Bus16 output("Output");
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
