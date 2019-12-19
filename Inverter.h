#ifndef INVERTER_H
#define INVERTER_H

#include "Relay.h"

/// Implement an inverter (NOT gate) using a relay.
/// This gate outputs a 1 if the input is 0 and the output is enabled.
class Inverter {
public:
	Inverter(const std::string& initName);
	void AttachEnable(Io* io) {
		relay.GetArmature()->AttachInput(io);
	}
	void AttachInput(Io* io) {
		relay.GetActivate()->AttachInput(io);
	}	
	Io* GetOutput() {
		return relay.GetNc();
	}
	
private:
	const std::string name;
	Relay relay;
};

#endif

