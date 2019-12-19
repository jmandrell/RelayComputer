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
	harness.AddInput("Input A 0", inputA.bits + 0);
	harness.AddInput("Input A 1", inputA.bits + 1);
	harness.AddInput("Input A 2", inputA.bits + 2);
	harness.AddInput("Input A 3", inputA.bits + 3);
	harness.AddInput("Input A 4", inputA.bits + 4);
	harness.AddInput("Input A 5", inputA.bits + 5);
	harness.AddInput("Input A 6", inputA.bits + 6);
	harness.AddInput("Input A 7", inputA.bits + 7);

	and8.AttachInputBusB(&inputB);
	harness.AddInput("Input B 0", inputB.bits + 0);
	harness.AddInput("Input B 1", inputB.bits + 1);
	harness.AddInput("Input B 2", inputB.bits + 2);
	harness.AddInput("Input B 3", inputB.bits + 3);
	harness.AddInput("Input B 4", inputB.bits + 4);
	harness.AddInput("Input B 5", inputB.bits + 5);
	harness.AddInput("Input B 6", inputB.bits + 6);
	harness.AddInput("Input B 7", inputB.bits + 7);
	
	and8.AttachOutputBus(&output);
	harness.AddOutputBus8("Output", &output);
	
	harness.Run();
	return 0;
}
