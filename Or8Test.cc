#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Or8.h"


int main() {
	TestHarness harness;
	Or8 or8("or8");
	Io enable;
	Bus8 inputA("Input A");
	Bus8 inputB("Input B");
	Bus8 output("Output");
	
	or8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	
	or8.AttachInputBusA(&inputA);
	harness.AddInputBus8("Input A", &inputA);

	or8.AttachInputBusB(&inputB);
	harness.AddInputBus8("Input B", &inputB);
	
	or8.AttachOutputBus(&output);
	harness.AddOutputBus8("Output", &output);

	harness.Run();
	return 0;
}
