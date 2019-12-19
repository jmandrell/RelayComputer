#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Register8.h"


int main() {
	TestHarness harness;
	Register8 reg8("reg8");
	Io input[8];
	Io enable;
	Io capture;
	
	reg8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	reg8.AttachCapture(&capture);
	harness.AddInput("Capture", &capture);
	reg8.AttachIn0(input+0);
	reg8.AttachIn1(input+1);
	reg8.AttachIn2(input+2);
	reg8.AttachIn3(input+3);
	reg8.AttachIn4(input+4);
	reg8.AttachIn5(input+5);
	reg8.AttachIn6(input+6);
	reg8.AttachIn7(input+7);
	harness.AddInput("Input 0", input + 0);
	harness.AddInput("Input 1", input + 1);
	harness.AddInput("Input 2", input + 2);
	harness.AddInput("Input 3", input + 3);
	harness.AddInput("Input 4", input + 4);
	harness.AddInput("Input 5", input + 5);
	harness.AddInput("Input 6", input + 6);
	harness.AddInput("Input 7", input + 7);
	
	harness.AddOutput("Out 0", reg8.GetOut0());
	harness.AddOutput("Out 1", reg8.GetOut1());
	harness.AddOutput("Out 2", reg8.GetOut2());
	harness.AddOutput("Out 3", reg8.GetOut3());
	harness.AddOutput("Out 4", reg8.GetOut4());
	harness.AddOutput("Out 5", reg8.GetOut5());
	harness.AddOutput("Out 6", reg8.GetOut6());
	harness.AddOutput("Out 7", reg8.GetOut7());
	
	harness.Run();
	return 0;
}
