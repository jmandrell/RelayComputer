#include <unistd.h>
#include "Processor.h"
#include "Registers.h"
#include "Buses.h"
#include "Components.h"


Processor::Processor() {
	
	Registers::pc.AttachOutputBus(&addressBus);
	
	Components::memory.AttachAddressBus(&addressBus);
	Components::memory.AttachDataBus(&dataBus);
}
