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
#include "Buffer16.h"


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
	Buffer16 seqBuffer;
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
	Buffer16 seqBuffer;
	Bus16 seqOutBus;
};


/// This class handles operations that start with '10000' (8-bit immediate register loads)
class Decoder10000 {
public:
	Decoder10000(const std::string& initName,
		Bus8& decoderBus,
		Increment16& increment16,
		Register16& arg16);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Mux whichRegister;
	Buffer16 seqBuffer;
	Bus16 seqOutBus;
	Register8 arg8;
};


/// This class handles operations that start with '10001' (8-bit register load from memory)
class Decoder10001 {
public:
	Decoder10001(const std::string& initName,
		Bus8& decoderBus,
		Increment16& increment16,
		Register16& arg16);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Mux whichRegister;
	Buffer16 seqBuffer;
	Bus16 seqOutBus;
	Register8 arg8_1;		// the LSB of the address
	Register8 arg8_2;		// the MSB of the address
};


/// This class handles operations that start with '10010' (8-bit register write to memory)
class Decoder10010 {
public:
	Decoder10010(const std::string& initName,
		Bus8& decoderBus,
		Increment16& increment16,
		Register16& arg16);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Mux whichRegister;
	Buffer16 seqBuffer;
	Bus16 seqOutBus;
	Register8 arg8_1;		// the LSB of the address
	Register8 arg8_2;		// the MSB of the address
};


/// This class handles operations that start with '10011' (8-bit R0 read/write indirect)
class Decoder10011 {
public:
	Decoder10011(const std::string& initName,
		Bus8& decoderBus,
		Increment16& increment16,
		Register16& arg16);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Mux readRegister;
	Buffer16 seqBuffer;
	Bus16 seqOutBus;
	Register8 msb;
	Register8 lsb;
	Relay readWrite;
};


/// This class handles operations that start with '1110' (branching operations)
class Decoder1110 {
public:
	Decoder1110(const std::string& initName,
		Bus8& decoderBus,
		Bus16& internalBus,
		Increment16& increment16,
		Register16& arg16);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Buffer16 seqBuffer;
	Bus16 seqOutBus;
	Bus8 flagsBus;
	Relay flagsGate_1;
	Relay flagsGate_2;
	Relay flagsGate_3;
	XorGate xor1;
	Register8 arg8_1;		// the LSB of the address
	Register8 arg8_2;		// the MSB of the address
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
	Bus16 internal16;
	Bus8 decoderBus;
	Relay bit7Relay;
	Relay bit6Relay_0;
	Relay bit6Relay_1;
	Relay bit5Relay_10;
	Relay bit5Relay_11;
	Relay bit4Relay_100;
	Relay bit4Relay_111;
	Relay bit3Relay_1000;
	Relay bit3Relay_1001;
	Relay bit3Relay_1111;
	Relay bit2Relay_11111;
	Relay bit1Relay_111111;
	Relay bit0Relay_1111111;
	Decoder00 dec00;
	Decoder01 dec01;
	Decoder10000 dec10000;
	Decoder10001 dec10001;
	Decoder10010 dec10010;
	Decoder10011 dec10011;
	Decoder1110 dec1110;
};

#endif
