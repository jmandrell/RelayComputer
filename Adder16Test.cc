#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Adder16.h"


int main() {
	TestHarness harness;
	Adder16 adder("adder");
	Bus16 inputA("Input A");
	Bus16 inputB("Input B");
	Bus16 output("Output");
	Io carryIn;
	Io enable;
	
	adder.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	adder.AttachCarryIn(&carryIn);
	harness.AddInput("Carry In", &carryIn);
	adder.AttachInputBusA(&inputA);
	harness.AddInputBus16("Input A", &inputA);
	adder.AttachInputBusB(&inputB);
	harness.AddInputBus16("Input B", &inputB);

	adder.AttachOutputBus(&output);
	harness.AddOutputBus16("Sum", &output);
	harness.AddOutput("Carry out", adder.GetCarryOut());
	
	harness.Run();
	return 0;
}
