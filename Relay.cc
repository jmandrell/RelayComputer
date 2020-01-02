#include <iostream>
#include "Relay.h"


Relay::Relay(const std::string& initName) : name(initName) {
}

void Relay::Update() {
	if (coil.GetOutput()) {
#ifdef DEBUG
		std::cerr << "NO "
				  << common.GetOutput() << " "
				  << no.GetOutput() << std::endl;
#endif
		// NO is activated
		bool state = common.GetOutput(false) || no.GetOutput(false);
		common.Force(state);
		no.Force(state);
		nc.Force(false);
	} else {
#ifdef DEBUG
		std::cerr << "NC "
				  << coil.GetOutput() << " "
				  << nc.GetOutput() << std::endl;
#endif
		// NC is activated
		bool state = common.GetOutput(false) || nc.GetOutput(false);
		common.Force(state);
		nc.Force(state);
		no.Force(false);
	}
}
