#include "Processor.h"

Processor::Processor() :
	addressBus("AddressBus"),
	dataBus("DataBus"),
	sequencer("sequencer"),
	alu("ALU"),
	pc("PC") {
	// test code: set PC to some arbitrary value
	Io one;
	one.Force(true);
	pc.AttachInputBus(&addressBus);
	pc.AttachOutputBus(&addressBus);
	pc.AttachEnable(sequencer.Get0());
}
