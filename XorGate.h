#ifndef XORGATE_H
#define XORGATE_H

#include "Relay.h"
#include "Enablable.h"


/// Implement an XOR gate using relays.
/// The output is only enabled if the enable pin is
/// driven.
class XorGate : public Enablable {
public:
	XorGate(const std::string& initName);
	void AttachEnable(Io* io) {
		relay1.GetCommon()->AttachInput(io);
	}
	void AttachInput1(Io* io) {
		relay1.AttachCoil(io);
	}
	void AttachInput2(Io* io) {
		relay2.AttachCoil(io);
	}
	Io* GetOutput() {
		return relay2.GetCommon();
	}
	
private:
	const std::string name;
	Relay relay1;
	Relay relay2;
};

#endif

