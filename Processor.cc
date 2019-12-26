#include <unistd.h>
#include "Processor.h"
#include "Registers.h"
#include "Buses.h"
#include "Components.h"


Processor::Processor() {	
	Registers::pc.AttachOutputBus(&Buses::addressBus);
	Registers::r0.AttachInputBus(&Buses::dataBus);
	Registers::r0.AttachOutputBus(&Buses::dataBus);
	Registers::r1.AttachInputBus(&Buses::dataBus);
	Registers::r1.AttachOutputBus(&Buses::dataBus);
	Registers::r2.AttachInputBus(&Buses::dataBus);
	Registers::r2.AttachOutputBus(&Buses::dataBus);
	Registers::r3.AttachInputBus(&Buses::dataBus);
	Registers::r3.AttachOutputBus(&Buses::dataBus);
	Registers::r4.AttachInputBus(&Buses::dataBus);
	Registers::r4.AttachOutputBus(&Buses::dataBus);
	Registers::r5.AttachInputBus(&Buses::dataBus);
	Registers::r5.AttachOutputBus(&Buses::dataBus);
	Registers::r6.AttachInputBus(&Buses::dataBus);
	Registers::r6.AttachOutputBus(&Buses::dataBus);
	Registers::r7.AttachInputBus(&Buses::dataBus);
	Registers::r7.AttachOutputBus(&Buses::dataBus);

	Components::memory.AttachAddressBus(&Buses::addressBus);
	Components::memory.AttachDataBus(&Buses::dataBus);
	Components::sequencer.AttachOutputBus(&Buses::sequencerBus);
}
