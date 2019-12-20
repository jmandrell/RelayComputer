#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Bus16.h"


int main() {
	TestHarness harness;
	Bus16 bus16("bus16");
	
	harness.AddInput("Input 0", &bus16.bits[0]);
	harness.AddInput("Input 1", &bus16.bits[1]);
	harness.AddInput("Input 2", &bus16.bits[2]);
	harness.AddInput("Input 3", &bus16.bits[3]);
	harness.AddInput("Input 4", &bus16.bits[4]);
	harness.AddInput("Input 5", &bus16.bits[5]);
	harness.AddInput("Input 6", &bus16.bits[6]);
	harness.AddInput("Input 7", &bus16.bits[7]);
	
	harness.Run();
	return 0;
}
