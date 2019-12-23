#include "ALU.h"

ALU::ALU(const std::string& initName) :
	name(initName),
	and8(name + " and8"),
	or8(name + " or8"),
	not8(name + " not8"),
	xor8(name + " xor8"),
	increment8(name + " increment8"),
	adder8(name + " adder8"),
	sub8(name + " sub8"),
	mux(name + " mux"),
	aluBus(name + " aluBus") {
	increment8.AttachEnable(mux.GetRightSignal0());
	not8.AttachEnable(mux.GetRightSignal1());
	and8.AttachEnable(mux.GetRightSignal2());
	or8.AttachEnable(mux.GetRightSignal3());
	xor8.AttachEnable(mux.GetRightSignal4());
	// compare operation needs to be here
	adder8.AttachEnable(mux.GetRightSignal6());
	sub8.AttachEnable(mux.GetRightSignal7());
	AttachOutputBus(&aluBus);
}


void ALU::AttachInputBusA(Bus8* bus) {
	and8.AttachInputBusA(bus);
	or8.AttachInputBusA(bus);
	not8.AttachInputBus(bus);
	xor8.AttachInputBusA(bus);
	increment8.AttachInputBus(bus);
	adder8.AttachInputBusA(bus);
	sub8.AttachInputBusA(bus);
}

void ALU::AttachInputBusB(Bus8* bus) {
	and8.AttachInputBusB(bus);
	or8.AttachInputBusB(bus);
	xor8.AttachInputBusB(bus);
	adder8.AttachInputBusB(bus);
	sub8.AttachInputBusB(bus);
}


void ALU::AttachOutputBus(Bus8* bus) {
	and8.AttachOutputBus(bus);
	or8.AttachOutputBus(bus);
	not8.AttachOutputBus(bus);
	xor8.AttachOutputBus(bus);
	increment8.AttachOutputBus(bus);
	adder8.AttachOutputBus(bus);
	sub8.AttachOutputBus(bus);
}
