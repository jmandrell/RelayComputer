#ifndef INSTRUCTIONDECODER_H
#define INSTRUCTIONDECODER_H

#include "Sequencer.h"
#include "ALU.h"
#include "Register16.h"
#include "Bus16.h"
#include "Bus8.h"
#include "Memory.h"
#include "Register8.h"
#include "Increment16.h"
#include "Mux.h"


class InstructionDecoder {
public:
	InstructionDecoder(Memory& memory);
	
private:
	// connect up a 4-cycle memory read and increment from the PC
	unsigned int PCReadAndIncrement(Register8& data, unsigned int startCycle);
	Memory& memory;
	Io power;
	Sequencer sequencer;
	Register8 inst;
	Increment16 increment16;
	Register16 arg16;
	Bus16 interal16;
	Bus16 sequencerBus;
	Bus8 decoderBus;
	Mux top2Bits;
	Mux middle3Bits;
	Mux bottom3Bits;
	Bus8 test0;
	Bus8 test1;
	Bus8 test2;
};

#endif
