#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Latch.h"


int main() {
	TestHarness harness;
	Latch latch("latch");
	Io enable;
	Io data;
	
	latch.AttachEnable(&enable);
	latch.AttachData(&data);
	harness.AddInput("Enable", &enable);
	harness.AddInput("Data", &data);
	
	harness.AddOutput("output", latch.GetOutput());
	
	harness.Run();
	return 0;
}
