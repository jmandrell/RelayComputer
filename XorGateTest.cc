#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "XorGate.h"


int main() {
	TestHarness harness;
	XorGate xorGate("xor");
	Io enable;
	Io input1;
	Io input2;
	
	xorGate.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	xorGate.AttachInput1(&input1);
	harness.AddInput("input 1", &input1);
	xorGate.AttachInput2(&input2);
	harness.AddInput("input 2", &input2);
	harness.AddOutput("output", xorGate.GetOutput());
	
	harness.Run();
	return 0;
}
