#ifndef LATCH_H
#define LATCH_H

#include "Relay.h"

/// Implement a single-bit data latch using relays.
/// The data comes in the data line, and is captured when the
/// captuire line is driven. The data is driven out when the
/// enable line is active.
class Latch {
public:
	Latch(const std::string& initName);
	void AttachEnable(Io* io) {
		relay4.AttachActivate(io);
	}
	void AttachCapture(Io* io) {
		relay1.GetArmature()->AttachInput(io);
	}
	void AttachData(Io* io) {
		relay1.AttachActivate(io);
	}
	Io* GetOutput() {
		return relay4.GetNo();
	}
	
private:
	const std::string name;
	Io power;
	Relay relay1;
	Relay relay2;
	Relay relay3;
	Relay relay4;
};
#endif

