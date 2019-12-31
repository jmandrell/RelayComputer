#include <unistd.h>
#include "Processor.h"
#include "Registers.h"
#include "Buses.h"
#include "Components.h"

namespace Registers {
	Register16 pc("PC");
	Register8 r0("R0");
	Register8 r1("R1");
	Register8 r2("R2");
	Register8 r3("R3");
	Register8 r4("R4");
	Register8 r5("R5");
	Register8 r6("R6");
	Register8 r7("R7");
	Register8 flags("flags");
}
namespace Buses {
	Bus16 addressBus("Address Bus");
	Bus8 dataBus("Data Bus");
	Bus16 sequencerBus("sequencerBus");
}
namespace Components {
	Memory memory("Memory");
	Sequencer sequencer("sequencer");
	InstructionDecoder decoder("Decoder");
}


Processor::Processor() {
	std::cerr << "Constructing processor" << std::endl;
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
