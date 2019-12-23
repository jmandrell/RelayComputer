#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "FullAdder.h"


int main() {
	TestHarness harness;
	FullAdder adder("adder");
	Io input1;
	Io input2;
	Io carryIn;
	Io enable;
	Io inputComplement;
	
	adder.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	adder.AttachInput1(&input1);
	harness.AddInput("input 1", &input1);
	adder.AttachInput2(&input2);
	harness.AddInput("input 2", &input2);
	adder.AttachCarryIn(&carryIn);
	harness.AddInput("Carry In", &carryIn);
	adder.AttachInputComplement(&inputComplement);
	harness.AddInput("Input complement", &inputComplement);
	
	harness.AddOutput("Sum", adder.GetSum());
	harness.AddOutput("Carry Out", adder.GetCarryOut());
	
	harness.Run();
	return 0;
}
