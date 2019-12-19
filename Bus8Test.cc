#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Bus8.h"


int main() {
	TestHarness harness;
	Bus8 bus8("bus8");
	
	harness.AddInput("Input 0", &bus8.bits[0]);
	harness.AddInput("Input 1", &bus8.bits[1]);
	harness.AddInput("Input 2", &bus8.bits[2]);
	harness.AddInput("Input 3", &bus8.bits[3]);
	harness.AddInput("Input 4", &bus8.bits[4]);
	harness.AddInput("Input 5", &bus8.bits[5]);
	harness.AddInput("Input 6", &bus8.bits[6]);
	harness.AddInput("Input 7", &bus8.bits[7]);
	
	harness.Run();
	return 0;
}
