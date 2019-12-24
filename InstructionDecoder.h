#ifndef INSTRUCTIONDECODER_H
#define INSTRUCTIONDECODER_H

#include <string>

#include "Sequencer.h"
#include "ALU.h"
#include "Register16.h"
#include "Bus16.h"
#include "Bus8.h"
#include "Memory.h"
#include "Register8.h"
#include "Increment16.h"
#include "Mux.h"


/// This class handles operaions that start with '01', which involve
/// ALU-based operations.
class DecoderAluOperations : public Enablable {
public:
	DecoderAluOperations(Io* channel0, Io* channel1, Io* channel2);
	void AttachEnable(Io* io);

private:
	ALU alu;
};


class InstructionDecoder {
public:
	InstructionDecoder(const std::string& initName);
	
private:
	// connect up a 4-cycle memory read and increment from the PC
	unsigned int PCReadAndIncrement(Register8& data, unsigned int startCycle);
	
	const std::string name;
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
	DecoderAluOperations decAluOp;
};

#endif
