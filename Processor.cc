#include <unistd.h>
#include "Processor.h"

Processor::Processor() :
	addressBus("AddressBus"),
	dataBus("DataBus"),
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
	memory("Memory"),
	decoder(pc, addressBus, dataBus, memory) {
	
	pc.AttachOutputBus(&addressBus);
	
	memory.AttachAddressBus(&addressBus);
	memory.AttachDataBus(&dataBus);
}
