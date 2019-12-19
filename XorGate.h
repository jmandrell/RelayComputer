#ifndef XORGATE_H
#define XORGATE_H

#include "Relay.h"

/// Implement an XOR gate using relays.
/// The output is only enabled if the enable pin is
/// driven.
class XorGate {
public:
	XorGate(const std::string& initName);
	void AttachEnable(Io* io) {
		relay1.GetArmature()->AttachInput(io);
	}
	void AttachInput1(Io* io) {
		relay1.GetActivate()->AttachInput(io);
	}
	void AttachInput2(Io* io) {
		relay2.GetActivate()->AttachInput(io);
	}
	Io* GetOutput() {
		return relay2.GetArmature();
	}
	
private:
	const std::string name;
	Relay relay1;
	Relay relay2;
};

#endif

