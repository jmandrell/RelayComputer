#include <unistd.h>
#include "Processor.h"

Processor::Processor() :
	addressBus("AddressBus"),
	dataBus("DataBus"),
	sequencer("sequencer"),
	alu("ALU"),
	pc("PC"),
	inst("inst"),
	memory("Memory") {
	pc.AttachInputBus(&addressBus);
	pc.AttachOutputBus(&addressBus);
	
	memory.AttachAddressBus(&addressBus);
	memory.AttachDataBus(&dataBus);
	
	inst.AttachInputBus(&dataBus);

	// set up the sequencing for instruction fetch
	// cycle 0, put the PC address on the bus
	pc.AttachEnable(sequencer.Get0());
	// cycle 1, read memory and keep PC address on bus
	pc.AttachEnable(sequencer.Get1());
	memory.AttachEnable(sequencer.Get1());
	// cycle 2, continue memory read, latch into instruction register
	memory.AttachEnable(sequencer.Get2());
	inst.AttachCapture(sequencer.Get2());
}
