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


/// This class handles operaions that start with '00', which involve
/// moves between registers
class Decoder00 {
public:
	Decoder00(const std::string& initName,
		Bus8& decoderBus);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Mux readRegister;
	Mux writeRegister;
	Register16 seqBuffer;
	Bus16 seqOutBus;
};


/// This class handles operaions that start with '01', which involve
/// ALU-based operations.
class Decoder01 {
public:
	Decoder01(const std::string& initName,
		Bus8& decoderBus);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Mux readRegister;
	Mux writeRegister;
	ALU alu;
	Register16 seqBuffer;
	Bus16 seqOutBus;
};


class InstructionDecoder {
public:
	InstructionDecoder(const std::string& initName);
	
private:
	// connect up a 4-cycle memory read and increment from the PC
	unsigned int PCReadAndIncrement(Register8& data, unsigned int startCycle);
	
	const std::string name;
	Io power;
	Register8 inst;
	Increment16 increment16;
	Register16 arg16;
	Bus16 interal16;
	Bus8 decoderBus;
	Mux top2Bits;
	Decoder00 dec00;
	Decoder01 dec01;
};

#endif
