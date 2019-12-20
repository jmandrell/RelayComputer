#include "Bus16.h"

Bus16::Bus16(const std::string& initName) :
	Display16Bit(initName), name(initName) {
}


void Bus16::GetValues(bool* bitValues) {
	for (unsigned int i = 0; i < 16; ++i) {
		bitValues[i] = bits[i].GetOutput();
	}
}


unsigned int Bus16::GetValue() {
	unsigned int value = 0;
	for (int i = 15; i >= 0; --i) {
		value <<= 1;
		if (bits[i].GetOutput()) {
			value += 1;
		}
	}
	return value;
}
