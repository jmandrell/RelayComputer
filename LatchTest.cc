#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Latch.h"


int main() {
	TestHarness harness;
	Latch latch("latch");
	Io enable;
	Io capture;
	Io data;
	
	latch.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	latch.AttachCapture(&capture);
	harness.AddInput("Capture", &capture);
	latch.AttachData(&data);
	harness.AddInput("Data", &data);
	
	harness.AddOutput("output", latch.GetOutput());
	
	harness.Run();
	return 0;
}
