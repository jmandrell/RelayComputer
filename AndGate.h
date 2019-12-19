#ifndef ANDGATE_H
#define ANDGATE_H

#include "Relay.h"

/// Implement an AND gate using relays.
/// The output is only enabled if the enable pin is
/// driven.
class AndGate {
public:
	AndGate(const std::string& initName);
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
		return relay2.GetNo();
	}
	
private:
	const std::string name;
	Relay relay1;
	Relay relay2;
};

#endif

