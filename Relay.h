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
	void AttachActivate(Io* io) {
		activate.AttachInput(io);
	}
	Io* GetArmature() {
		return &armature;
	}
	Io* GetNo() {
		return &no;
	}
	Io* GetNc() {
		return &nc;
	}
	
private:	
	const std::string name;
	Io activate;
	Io armature;
	Io nc;
	Io no;
};

#endif
