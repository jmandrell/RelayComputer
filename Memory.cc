#include <iostream>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "Memory.h"

Memory::Memory(const std::string& initName) :
	name(initName),
	outputData(name + " databus") {
	memFd = open("memory.img", O_RDWR);
}


void Memory::AttachDataBus(Bus8* bus) {
	dataBus = bus;
	for (unsigned int i = 0; i < 8; ++i) {
		bus->bits[i].AttachInput(&outputData.bits[i]);
	}
}


unsigned char Memory::ReadMem(unsigned int address) {
	unsigned char c;
	lseek(memFd, address, SEEK_SET);
	read(memFd, &c, 1);
	return c;
}


void Memory::WriteMem(unsigned int address, unsigned char value) {
	lseek(memFd, address, SEEK_SET);
	write(memFd, &value, 1);
}


void Memory::Update() {
	if (enable.GetOutput()) {
		// they are reading memory, get the address from the address bus
		unsigned int address = addressBus->GetValue();
		unsigned char value = ReadMem(address);
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
	if (writeSignal.GetOutput()) {
		// they are writing memory, get the address from the address bus
		unsigned int address = addressBus->GetValue();
		// get the data from the data bus
		unsigned char value = dataBus->GetValue();
		std::cerr << address << " " << (unsigned int)value << std::endl;
		WriteMem(address, value);
	}
}
