#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Sequencer.h"
#include "ALU.h"
#include "Register16.h"
#include "Bus16.h"
#include "Bus8.h"
#include "Memory.h"
#include "Register8.h"
#include "Increment16.h"

class Processor {
public:
	Processor();
	
//private:
	Bus16 addressBus;
	Bus8 dataBus;
	Sequencer sequencer;
	ALU alu;
	Register16 pc;
	Register8 r0;
	Register8 r1;
	Register8 r2;
	Register8 r3;
	Register8 r4;
	Register8 r5;
	Register8 r6;
	Register8 r7;
	Register8 inst;
	Increment16 increment16;
	Register16 nextPc;
	Bus16 interal16;
	Bus16 sequencerBus;
	Memory memory;
};

#endif
