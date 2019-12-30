#ifndef BUFFER16_H
#define BUFFER16_H

#include <string>

#include "Relay.h"
#include "Bus16.h"


class Buffer16 {
public:
	Buffer16(const std::string& initName);
	void AttachInputBus(Bus16* bus);
	void AttachOutputBus(Bus16* bus);
	void AttachEnable(Io* io);

private:
	const std::string name;
	Relay bit0;
	Relay bit1;
	Relay bit2;
	Relay bit3;
	Relay bit4;
	Relay bit5;
	Relay bit6;
	Relay bit7;
	Relay bit8;
	Relay bit9;
	Relay bit10;
	Relay bit11;
	Relay bit12;
	Relay bit13;
	Relay bit14;
	Relay bit15;
};

#endif
