#include "ALU.h"

ALU::ALU(const std::string& initName) :
	name(initName),
	inputA(name + " inputA", false),
	inputABus(name + " inputABus", false),
	inputB(name + " inputB", false),
	inputBBus(name + " inputBBus", false),
	and8(name + " and8"),
	or8(name + " or8"),
	not8(name + " not8"),
	xor8(name + " xor8"),
	increment8(name + " increment8"),
	adder8(name + " adder8"),
	sub8(name + " sub8"),
	mux(name + " mux"),
	internalBus(name + " bus"),
	flagsBus(name + " flagsBus"),
	inverter(name + " signInverter"),
	outputRegister(name + " outReg"),
	flagsRegister(name + " flagsReg") {
	power.Force(true);
	mux.GetLeftSignal()->AttachInput(&power);
	
	// set up the registure to capture flags
	flagsRegister.AttachInputBus(&flagsBus);
	// the zero flag
	inverter.AttachEnable(&power);
	inverter.AttachInput(&internalBus.bits[0]);
	inverter.AttachInput(&internalBus.bits[1]);
	inverter.AttachInput(&internalBus.bits[2]);
	inverter.AttachInput(&internalBus.bits[3]);
	inverter.AttachInput(&internalBus.bits[4]);
	inverter.AttachInput(&internalBus.bits[5]);
	inverter.AttachInput(&internalBus.bits[6]);
	inverter.AttachInput(&internalBus.bits[7]);
	flagsBus.bits[0].AttachInput(inverter.GetOutput());
	// the carry flag
	flagsBus.bits[1].AttachInput(increment8.GetCarryOut());
	flagsBus.bits[1].AttachInput(adder8.GetCarryOut());
	flagsBus.bits[1].AttachInput(sub8.GetCarryOut());
	// the sign flag
	flagsBus.bits[2].AttachInput(&internalBus.bits[7]);

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
