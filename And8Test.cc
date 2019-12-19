#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "And8.h"
#include "Bus8.h"


int main() {
	TestHarness harness;
	And8 and8("and8");
	Io enable;
	Bus8 inputA("Input A");
	Bus8 inputB("Input B");
	Bus8 output("Output");
	
	and8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	and8.AttachInputBusA(&inputA);
	harness.AddInputBus8("Input A", &inputA);

	and8.AttachInputBusB(&inputB);
	harness.AddInputBus8("Input B", &inputB);
	
	and8.AttachOutputBus(&output);
	harness.AddOutputBus8("Output", &output);
	
	harness.Run();
	return 0;
}
