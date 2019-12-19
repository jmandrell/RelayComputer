#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Adder8.h"


int main() {
	TestHarness harness;
	Adder8 adder("adder");
	Io inputA[8];
	Io inputB[8];
	Io carryIn;
	Io enable;
	
	adder.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	adder.AttachCarryIn(&carryIn);
	harness.AddInput("Carry In", &carryIn);
	adder.AttachA0(inputA+0);
	adder.AttachA1(inputA+1);
	adder.AttachA2(inputA+2);
	adder.AttachA3(inputA+3);
	adder.AttachA4(inputA+4);
	adder.AttachA5(inputA+5);
	adder.AttachA6(inputA+6);
	adder.AttachA7(inputA+7);
	harness.AddInput("Input A 0", inputA + 0);
	harness.AddInput("Input A 1", inputA + 1);
	harness.AddInput("Input A 2", inputA + 2);
	harness.AddInput("Input A 3", inputA + 3);
	harness.AddInput("Input A 4", inputA + 4);
	harness.AddInput("Input A 5", inputA + 5);
	harness.AddInput("Input A 6", inputA + 6);
	harness.AddInput("Input A 7", inputA + 7);

	adder.AttachB0(inputB+0);
	adder.AttachB1(inputB+1);
	adder.AttachB2(inputB+2);
	adder.AttachB3(inputB+3);
	adder.AttachB4(inputB+4);
	adder.AttachB5(inputB+5);
	adder.AttachB6(inputB+6);
	adder.AttachB7(inputB+7);
	harness.AddInput("Input B 0", inputB + 0);
	harness.AddInput("Input B 1", inputB + 1);
	harness.AddInput("Input B 2", inputB + 2);
	harness.AddInput("Input B 3", inputB + 3);
	harness.AddInput("Input B 4", inputB + 4);
	harness.AddInput("Input B 5", inputB + 5);
	harness.AddInput("Input B 6", inputB + 6);
	harness.AddInput("Input B 7", inputB + 7);
	
	harness.AddOutput("Sum 0", adder.GetSum0());
	harness.AddOutput("Sum 1", adder.GetSum1());
	harness.AddOutput("Sum 2", adder.GetSum2());
	harness.AddOutput("Sum 3", adder.GetSum3());
	harness.AddOutput("Sum 4", adder.GetSum4());
	harness.AddOutput("Sum 5", adder.GetSum5());
	harness.AddOutput("Sum 6", adder.GetSum6());
	harness.AddOutput("Sum 7", adder.GetSum7());
	harness.AddOutput("Carry out", adder.GetCarryOut());
	
	harness.Run();
	return 0;
}
