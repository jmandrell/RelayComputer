#include <iostream>
#include <stdlib.h>

#include "Memory.h"

Memory::Memory(const std::string& initName) :
	name(initName),
	outputData(name + " databus") {
	memory[0] = 0xff;
	memory[1] = 0xcc;
	memory[2] = 0x55;
}


void Memory::AttachDataBus(Bus8* bus) {
	dataBus = bus;
	for (unsigned int i = 0; i < 8; ++i) {
		bus->bits[i].AttachInput(&outputData.bits[i]);
	}
}


void Memory::Update() {
	if (enable.GetOutput()) {
		// they are reading memory, get the address from the address bus
		unsigned int address = addressBus->GetValue();
		unsigned char value = memory[address];
		for (unsigned int i = 0; i < 8; ++i) {
			outputData.bits[i].Force((value & 1) != 0);
			value >>= 1;
		}
	} else {
		// turn off the outputs
		for (unsigned int i = 0; i < 8; ++i) {
			outputData.bits[i].Force(false);
		}
	}
	if (write.GetOutput()) {
		// they are writing memory, get the address from the address bus
		unsigned int address = addressBus->GetValue();
		// get the data from the data bus
		unsigned char value = dataBus->GetValue();
		std::cerr << address << " " << (unsigned int)value << std::endl;
		memory[address] = value;
	}
}
