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
	harness.AddInput("Input 8", &bus16.bits[8]);
	harness.AddInput("Input 9", &bus16.bits[9]);
	harness.AddInput("Input 10", &bus16.bits[10]);
	harness.AddInput("Input 11", &bus16.bits[11]);
	harness.AddInput("Input 12", &bus16.bits[12]);
	harness.AddInput("Input 13", &bus16.bits[13]);
	harness.AddInput("Input 14", &bus16.bits[14]);
	harness.AddInput("Input 15", &bus16.bits[15]);
	
	harness.Run();
	return 0;
}
