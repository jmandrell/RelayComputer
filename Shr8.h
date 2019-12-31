#ifndef SHR8_H
#define SHR8_H

#include <string>

#include "Relay.h"
#include "Bus8.h"


/// A class that supports an 8-bit shift right operation.
/// Since we're shifting right, there is no need for a relay
/// on bit 0.
class Shr8 {
public:
	Shr8(const std::string& initName);
	void AttachInputBus(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Relay bit1;
	Relay bit2;
	Relay bit3;
	Relay bit4;
	Relay bit5;
	Relay bit6;
	Relay bit7;
};

#endif
