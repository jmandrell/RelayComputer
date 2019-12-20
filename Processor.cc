#include <unistd.h>
#include "Processor.h"

Processor::Processor() :
	addressBus("AddressBus"),
	dataBus("DataBus"),
	sequencer("sequencer"),
	alu("ALU"),
	pc("PC"),
	inst("inst"),
	increment16("increment16"),
	nextPc("Next PC"),
	interal16("internal16"),
	memory("Memory") {
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
	pc.AttachEnable(sequencer.Get0());
	// cycle 1, read memory and keep PC address on bus
	pc.AttachEnable(sequencer.Get1());
	memory.AttachEnable(sequencer.Get1());
	inst.AttachCapture(sequencer.Get1());
	increment16.AttachEnable(sequencer.Get1());
	nextPc.AttachCapture(sequencer.Get1());
	
	// cycle 2, continue memory read, latch into instruction register, increment PC
	pc.AttachEnable(sequencer.Get2());
	memory.AttachEnable(sequencer.Get2());
	increment16.AttachEnable(sequencer.Get2());
	nextPc.AttachEnable(sequencer.Get2());
	
	// cycle 3, keep next pc on bus
	nextPc.AttachEnable(sequencer.Get3());
	pc.AttachCapture(sequencer.Get3());
	
	// temporary shortcut!
	//cycle 4: reset to cycle 0
	sequencer.AttachClear(sequencer.Get4());
}

