#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Sequencer.h"
#include "ALU.h"
#include "Register16.h"
#include "Bus16.h"
#include "Bus8.h"
#include "Memory.h"
#include "Register8.h"

class Processor {
public:
	Processor();
	
//private:
	Bus16 addressBus;
	Bus8 dataBus;
	Sequencer sequencer;
	ALU alu;
	Register16 pc;
	Register8 inst;
	Memory memory;
};

#endif
