#ifndef ORGATE_H
#define ORGATE_H

#include "Relay.h"

/// Implement an OR gate using relays.
/// The output is only enabled if the enable pin is
/// driven.
class OrGate {
public:
	OrGate(const std::string& initName);
	void AttachEnable(Io* io) {
		relay1.GetArmature()->AttachInput(io);
		relay2.GetArmature()->AttachInput(io);
	}
	void AttachInput1(Io* io) {
		relay1.AttachActivate(io);
	}
	void AttachInput2(Io* io) {
		relay2.AttachActivate(io);
	}
	Io* GetOutput() {
		return &output;
	}
	
private:
	const std::string name;
	Io output;
	Relay relay1;
	Relay relay2;
};

#endif

