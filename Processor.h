#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "ALU.h"
#include "Register16.h"
#include "Memory.h"
#include "Register8.h"
#include "Increment16.h"
#include "InstructionDecoder.h"

class Processor {
public:
	Processor();
	
	ALU alu;
	Memory memory;
	InstructionDecoder decoder;
};

#endif
