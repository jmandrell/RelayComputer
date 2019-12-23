#include <unistd.h>
#include "Processor.h"
#include "Registers.h"
#include "Buses.h"


Processor::Processor() :
	alu("ALU"),
	memory("Memory"),
	decoder(memory) {
	
	pc.AttachOutputBus(&addressBus);
	
	memory.AttachAddressBus(&addressBus);
	memory.AttachDataBus(&dataBus);
}
