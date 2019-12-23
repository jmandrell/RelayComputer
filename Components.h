#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "ALU.h"
#include "Memory.h"
#include "InstructionDecoder.h"


namespace Components {
	extern ALU alu;
	extern Memory memory;
	extern InstructionDecoder decoder;
}

#endif
