#include "TestHarness.h"
#include "Sub8.h"

int main() {
	TestHarness harness;
	Sub8 sub8("sub8");
	Io carryIn;
	Io enable;
	Io carryOut;
	Bus8 inputA("Input A");
	Bus8 inputB("Input B");
	Bus8 output("Output");
	
	sub8.AttachCarryIn(&carryIn);
	harness.AddInput("Carry In", &carryIn);
	sub8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	sub8.AttachInputBusA(&inputA);
	harness.AddInputBus8("Input A", &inputA);
	sub8.AttachInputBusB(&inputB);
	harness.AddInputBus8("Input B", &inputB);
	
	harness.AddOutput("Carry Out", sub8.GetCarryOut());
	sub8.AttachOutputBus(&output);
	harness.AddOutputBus8("Output", &output);
	
	harness.Run();
	
	return 0;
}
