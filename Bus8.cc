#include "Bus8.h"

Bus8::Bus8(const std::string& initName) :
	Display8Bit(initName), name(initName) {
}


void Bus8::GetValue(bool* bitValues) {
	for (unsigned int i = 0; i < 8; ++i) {
		bitValues[i] = bits[i].GetOutput();
	}
}
