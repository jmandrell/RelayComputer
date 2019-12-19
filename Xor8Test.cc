#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Xor8.h"


int main() {
	TestHarness harness;
	Xor8 xor8("xor8");
	Io enable;
	Bus8 inputA("Input A");
	Bus8 inputB("Input B");
	Bus8 output("Output");
	
	xor8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);

	xor8.AttachInputBusA(&inputA);
	harness.AddInputBus8("Input A", &inputA);

	xor8.AttachInputBusB(&inputB);
	harness.AddInputBus8("Input B", &inputB);

	xor8.AttachOutputBus(&output);
	harness.AddOutputBus8("Ouput", &output);
	
	harness.Run();
	return 0;
}
