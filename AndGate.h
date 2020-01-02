#ifndef ANDGATE_H
#define ANDGATE_H

#include "Relay.h"
#include "Enablable.h"


/// Implement an AND gate using relays.
/// The output is only enabled if the enable pin is
/// driven.
class AndGate : public Enablable {
public:
	AndGate(const std::string& initName);
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
		return relay2.GetNo();
	}
	
private:
	const std::string name;
	Relay relay1;
	Relay relay2;
};

#endif

