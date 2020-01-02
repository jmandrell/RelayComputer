#ifndef LATCH_H
#define LATCH_H

#include "Relay.h"
#include "Enablable.h"


/// Implement a single-bit data latch using relays.
/// The data comes in the data line, and is captured when the
/// captuire line is driven. The data is driven out when the
/// enable line is active.
class Latch : public Enablable {
public:
	Latch(const std::string& initName);
	void AttachEnable(Io* io) {
		relay4.AttachCoil(io);
	}
	void AttachCapture(Io* io) {
		relay1.GetCommon()->AttachInput(io);
	}
	void AttachData(Io* io) {
		relay1.AttachCoil(io);
	}
	Io* GetOutput() {
		return relay4.GetNo();
	}
	// this is used to query the internal state of the latch
	bool GetInternalState() {
		return relay3.GetNc()->GetOutput();
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

