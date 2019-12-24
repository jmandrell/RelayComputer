#include "ALU.h"

ALU::ALU(const std::string& initName) :
	name(initName),
	inputA(name + " inputA"),
	inputABus(name + " inputABus"),
	inputB(name + " inputB"),
	inputBBus(name + " inputBBus"),
	and8(name + " and8"),
	or8(name + " or8"),
	not8(name + " not8"),
	xor8(name + " xor8"),
	increment8(name + " increment8"),
	adder8(name + " adder8"),
	sub8(name + " sub8"),
	mux(name + " mux"),
	internalBus(name + " bus"),
	outputRegister(name + " outReg") {
	power.Force(true);
	mux.GetLeftSignal()->AttachInput(&power);
	increment8.AttachEnable(mux.GetRightSignal0());
	not8.AttachEnable(mux.GetRightSignal1());
	and8.AttachEnable(mux.GetRightSignal2());
	or8.AttachEnable(mux.GetRightSignal3());
	xor8.AttachEnable(mux.GetRightSignal4());
	// compare operation needs to be here
	adder8.AttachEnable(mux.GetRightSignal6());
	sub8.AttachEnable(mux.GetRightSignal7());
	and8.AttachOutputBus(&internalBus);
	or8.AttachOutputBus(&internalBus);
	not8.AttachOutputBus(&internalBus);
	xor8.AttachOutputBus(&internalBus);
	increment8.AttachOutputBus(&internalBus);
	adder8.AttachOutputBus(&internalBus);
	sub8.AttachOutputBus(&internalBus);
	outputRegister.AttachInputBus(&internalBus);
	inputA.AttachOutputBus(&inputABus);
	inputA.AttachEnable(&power);
	and8.AttachInputBusA(&inputABus);
	or8.AttachInputBusA(&inputABus);
	not8.AttachInputBus(&inputABus);
	xor8.AttachInputBusA(&inputABus);
	increment8.AttachInputBus(&inputABus);
	adder8.AttachInputBusA(&inputABus);
	sub8.AttachInputBusA(&inputABus);
	inputB.AttachOutputBus(&inputBBus);
	inputB.AttachEnable(&power);
	and8.AttachInputBusB(&inputBBus);
	or8.AttachInputBusB(&inputBBus);
	xor8.AttachInputBusB(&inputBBus);
	adder8.AttachInputBusB(&inputBBus);
	sub8.AttachInputBusB(&inputBBus);
}


void ALU::AttachInputBus(Bus8* bus) {
	inputA.AttachInputBus(bus);
	inputB.AttachInputBus(bus);
}


void ALU::AttachOutputBus(Bus8* bus) {
	outputRegister.AttachOutputBus(bus);
}
