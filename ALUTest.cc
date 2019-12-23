#include "TestHarness.h"
#include "ALU.h"


int
main() {
	TestHarness harness;
	ALU alu("alu");
	Io enable;
	Io compute;
	Io channel0;
	Io channel1;
	Io channel2;
	Bus8 inputA("Input A");
	Bus8 inputB("Input B");
	Bus8 output("Output");
	
	alu.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	alu.AttachCompute(&compute);
	harness.AddInput("Compute", &compute);
	
	alu.AttachChannel0(&channel0);
	harness.AddInput("Channel 0", &channel0);
	alu.AttachChannel1(&channel1);
	harness.AddInput("Channel 1", &channel1);
	alu.AttachChannel2(&channel2);
	harness.AddInput("Channel 2", &channel2);
	
	alu.AttachInputBusA(&inputA);
	harness.AddInputBus8("Input A", &inputA);
	alu.AttachInputBusB(&inputB);
	harness.AddInputBus8("Input B", &inputB);
	alu.AttachOutputBus(&output);
	harness.AddOutputBus8("Output", &output);
	
	harness.Run();
	return 0;
}
