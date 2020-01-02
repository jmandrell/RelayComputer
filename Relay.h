#ifndef RELAY_H
#define RELAY_H

#include <string>
#include "Io.h"
#include "Updatable.h"

//#define DEBUG

/// This class implements a simulation of a SPDT relay.
/// You can directly attach to the Activate line to switch the
/// relay, but the other lines need to be fetched and dealt with
/// directly as they can either be inputs or outputs.
class Relay : public Updatable {
public:
	Relay(const std::string& initName);
	void Update();
	void AttachCoil(Io* io) {
		coil.AttachInput(io);
	}
	Io* GetCommon() {
		return &common;
	}
	Io* GetNo() {
		return &no;
	}
	Io* GetNc() {
		return &nc;
	}
	
private:	
	const std::string name;
	Io coil;
	Io common;
	Io nc;
	Io no;
};

#endif
