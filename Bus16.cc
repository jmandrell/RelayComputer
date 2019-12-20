#include "Bus16.h"

Bus16::Bus16(const std::string& initName) :
	Display16Bit(initName), name(initName) {
}


void Bus16::GetValue(bool* bitValues) {
	for (unsigned int i = 0; i < 16; ++i) {
		bitValues[i] = bits[i].GetOutput();
	}
}
