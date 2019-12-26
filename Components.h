#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "Memory.h"
#include "InstructionDecoder.h"
#include "Sequencer.h"


namespace Components {
	extern Memory memory;
	extern InstructionDecoder decoder;
	extern Sequencer sequencer;
}

#endif
