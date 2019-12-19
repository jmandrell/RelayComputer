#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "OrGate.h"


int main() {
	TestHarness harness;
	OrGate orGate("or");
	Io enable;
	Io input1;
	Io input2;
	
	orGate.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	orGate.AttachInput1(&input1);
	harness.AddInput("input 1", &input1);
	orGate.AttachInput2(&input2);
	harness.AddInput("input 2", &input2);
	harness.AddOutput("output", orGate.GetOutput());
	
	harness.Run();
	return 0;
}
