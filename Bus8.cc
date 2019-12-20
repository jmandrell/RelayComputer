#include "Bus8.h"

Bus8::Bus8(const std::string& initName) :
	Display8Bit(initName), name(initName) {
}


void Bus8::GetValues(bool* bitValues) {
	for (unsigned int i = 0; i < 8; ++i) {
		bitValues[i] = bits[i].GetOutput();
	}
}


unsigned int Bus8::GetValue() {
	unsigned int value = 0;
	for (int i = 7; i >= 0; --i) {
		value <<= 1;
		if (bits[i].GetOutput()) {
			value += 1;
		}
	}
	return value;
}
