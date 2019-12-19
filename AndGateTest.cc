#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "AndGate.h"


int main() {
	TestHarness harness;
	AndGate andGate("and");
	Io enable;
	Io input1;
	Io input2;
	
	andGate.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	andGate.AttachInput1(&input1);
	harness.AddInput("input 1", &input1);
	andGate.AttachInput2(&input2);
	harness.AddInput("input 2", &input2);
	harness.AddOutput("output", andGate.GetOutput());
	
	harness.Run();
	return 0;
}
