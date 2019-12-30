#ifndef BUFFER8_H
#define BUFFER8_H

#include <string>

#include "Relay.h"
#include "Bus8.h"


class Buffer8 {
public:
	Buffer8(const std::string& initName);
	void AttachInputBus(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
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
};

#endif
