#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Inverter.h"


int main() {
	TestHarness harness;
	Inverter inverter("inverter");
	Io enable;
	Io input1;
	
	inverter.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	inverter.AttachInput(&input1);
	harness.AddInput("input 1", &input1);
	harness.AddOutput("output", inverter.GetOutput());
	
	harness.Run();
	return 0;
}
