#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Bus8.h"


int main() {
	TestHarness harness;
	Bus8 bus8("bus8");
	
	harness.AddInput("Input", &bus8);
	
	harness.Run();
	return 0;
}
