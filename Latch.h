#ifndef LATCH_H
#define LATCH_H

#include "Relay.h"

/// Implement a single-bit data latch using relays.
/// The data comes in the data line, and is captured when the
/// enable line is driven.
class Latch {
public:
	Latch(const std::string& initName);
	void AttachEnable(Io* io) {
		relay1.GetArmature()->AttachInput(io);
	}
	void AttachData(Io* io) {
		relay1.GetActivate()->AttachInput(io);
	}
	Io* GetOutput() {
		relay3.GetNc();
	}
	
private:
	const std::string name;
	Io power;
	Relay relay1;
	Relay relay2;
	Relay relay3;
};
#endif

