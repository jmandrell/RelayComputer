#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Mux.h"


int main() {
	TestHarness harness;
	Mux mux1("mux1");
	Mux mux2("mux2");
	Io channel0;
	Io channel1;
	Io channel2;
	Io input1;

	mux1.AttachChannel0(&channel0);
	mux1.AttachChannel1(&channel1);
	mux1.AttachChannel2(&channel2);
	mux2.AttachChannel0(&channel0);
	mux2.AttachChannel1(&channel1);
	mux2.AttachChannel2(&channel2);
	harness.AddInput("Channel 0", &channel0);
	harness.AddInput("Channel 1", &channel1);
	harness.AddInput("Channel 2", &channel2);
	
	mux1.GetLeftSignal()->AttachInput(&input1);
	harness.AddInput("Input 1", &input1);
	harness.AddOutput("Output 0/mux1", mux1.GetRightSignal0());
	harness.AddOutput("Output 1/mux1", mux1.GetRightSignal1());
	harness.AddOutput("Output 2/mux1", mux1.GetRightSignal2());
	harness.AddOutput("Output 3/mux1", mux1.GetRightSignal3());
	harness.AddOutput("Output 4/mux1", mux1.GetRightSignal4());
	harness.AddOutput("Output 5/mux1", mux1.GetRightSignal5());
	harness.AddOutput("Output 6/mux1", mux1.GetRightSignal6());
	harness.AddOutput("Output 7/mux1", mux1.GetRightSignal7());
	
	harness.Run();
	return 0;
}
