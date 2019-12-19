#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "And8.h"


int main() {
	TestHarness harness;
	And8 and8("and8");
	Io enable;
	Io inputA[8];
	Io inputB[8];
	
	and8.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	and8.AttachInputA0(inputA+0);
	and8.AttachInputA1(inputA+1);
	and8.AttachInputA2(inputA+2);
	and8.AttachInputA3(inputA+3);
	and8.AttachInputA4(inputA+4);
	and8.AttachInputA5(inputA+5);
	and8.AttachInputA6(inputA+6);
	and8.AttachInputA7(inputA+7);
	harness.AddInput("Input A 0", inputA + 0);
	harness.AddInput("Input A 1", inputA + 1);
	harness.AddInput("Input A 2", inputA + 2);
	harness.AddInput("Input A 3", inputA + 3);
	harness.AddInput("Input A 4", inputA + 4);
	harness.AddInput("Input A 5", inputA + 5);
	harness.AddInput("Input A 6", inputA + 6);
	harness.AddInput("Input A 7", inputA + 7);

	and8.AttachInputB0(inputB+0);
	and8.AttachInputB1(inputB+1);
	and8.AttachInputB2(inputB+2);
	and8.AttachInputB3(inputB+3);
	and8.AttachInputB4(inputB+4);
	and8.AttachInputB5(inputB+5);
	and8.AttachInputB6(inputB+6);
	and8.AttachInputB7(inputB+7);
	harness.AddInput("Input B 0", inputB + 0);
	harness.AddInput("Input B 1", inputB + 1);
	harness.AddInput("Input B 2", inputB + 2);
	harness.AddInput("Input B 3", inputB + 3);
	harness.AddInput("Input B 4", inputB + 4);
	harness.AddInput("Input B 5", inputB + 5);
	harness.AddInput("Input B 6", inputB + 6);
	harness.AddInput("Input B 7", inputB + 7);
	
	harness.AddOutput("Output 0", and8.GetOutput0());
	harness.AddOutput("Output 1", and8.GetOutput1());
	harness.AddOutput("Output 2", and8.GetOutput2());
	harness.AddOutput("Output 3", and8.GetOutput3());
	harness.AddOutput("Output 4", and8.GetOutput4());
	harness.AddOutput("Output 5", and8.GetOutput5());
	harness.AddOutput("Output 6", and8.GetOutput6());
	harness.AddOutput("Output 7", and8.GetOutput7());
	
	harness.Run();
	return 0;
}
