#include <unistd.h>
#include "Processor.h"

Processor::Processor() :
	addressBus("AddressBus"),
	dataBus("DataBus"),
	sequencer("sequencer"),
	alu("ALU"),
	pc("PC"),
	r0("R0"),
	r1("R1"),
	r2("R2"),
	r3("R3"),
	r4("R4"),
	r5("R5"),
	r6("R6"),
	r7("R7"),
	inst("inst"),
	increment16("increment16"),
	nextPc("Next PC"),
	interal16("internal16"),
	sequencerBus("sequencerBus"),
	memory("Memory") {
	sequencer.AttachOutputBus(&sequencerBus);
	
	pc.AttachInputBus(&interal16);
	pc.AttachOutputBus(&addressBus);
	
	memory.AttachAddressBus(&addressBus);
	memory.AttachDataBus(&dataBus);
	
	increment16.AttachInputBus(&addressBus);
	increment16.AttachOutputBus(&interal16);
	
	nextPc.AttachInputBus(&interal16);
	nextPc.AttachOutputBus(&interal16);
	
	inst.AttachInputBus(&dataBus);

	// set up the sequencing for instruction fetch
	// cycle 0, put the PC address on the bus
	pc.AttachEnable(&sequencerBus.bits[0]);
	// cycle 1, read memory and keep PC address on bus
	pc.AttachEnable(&sequencerBus.bits[1]);
	memory.AttachEnable(&sequencerBus.bits[1]);
	inst.AttachCapture(&sequencerBus.bits[1]);
	increment16.AttachEnable(&sequencerBus.bits[1]);
	nextPc.AttachCapture(&sequencerBus.bits[1]);
	
	// cycle 2, continue memory read, latch into instruction register, increment PC
	pc.AttachEnable(&sequencerBus.bits[2]);
	memory.AttachEnable(&sequencerBus.bits[2]);
	increment16.AttachEnable(&sequencerBus.bits[2]);
	nextPc.AttachEnable(&sequencerBus.bits[2]);
	
	// cycle 3, keep next pc on bus
	nextPc.AttachEnable(&sequencerBus.bits[3]);
	pc.AttachCapture(&sequencerBus.bits[3]);
	
	// temporary shortcut!
	//cycle 4: reset to cycle 0
	sequencer.AttachClear(&sequencerBus.bits[4]);
}
