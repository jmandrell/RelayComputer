#include "TestHarness.h"
#include "ALU.h"


int
main() {
	TestHarness harness;
	ALU alu("ALU");
	Io captureA;
	Io captureB;
	Io enable;
	Io compute;
	Io channel0;
	Io channel1;
	Io channel2;
	Bus8 input("Input");
	Bus8 output("Output");
	
	alu.AttachCaptureA(&captureA);
	harness.AddInput("Capture A", &captureA);
	alu.AttachCaptureB(&captureB);
	harness.AddInput("Capture B", &captureB);
	
	alu.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	alu.AttachCaptureOut(&compute);
	harness.AddInput("Compute", &compute);
	
	alu.AttachChannel0(&channel0);
	harness.AddInput("Channel 0", &channel0);
	alu.AttachChannel1(&channel1);
	harness.AddInput("Channel 1", &channel1);
	alu.AttachChannel2(&channel2);
	harness.AddInput("Channel 2", &channel2);
	
	alu.AttachInputBus(&input);
	harness.AddInputBus8("Input", &input);
	alu.AttachOutputBus(&output);
	harness.AddOutputBus8("Output", &output);
	
	harness.Run();
	return 0;
}
