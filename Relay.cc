#include <iostream>
#include "Relay.h"


Relay::Relay(const std::string& initName) : name(initName) {
	std::cerr << "Creating relay " << name << std::endl;
}

void Relay::Update() {
	if (activate.GetOutput()) {
#ifdef DEBUG
		std::cerr << "NO "
				  << armature.GetOutput() << " "
				  << no.GetOutput() << std::endl;
#endif
		// NO is activated
		bool state = armature.GetOutput(false) || no.GetOutput(false);
		armature.Force(state);
		no.Force(state);
		nc.Force(false);
	} else {
#ifdef DEBUG
		std::cerr << "NC "
				  << armature.GetOutput() << " "
				  << nc.GetOutput() << std::endl;
#endif
		// NC is activated
		bool state = armature.GetOutput(false) || nc.GetOutput(false);
		armature.Force(state);
		nc.Force(state);
		no.Force(false);
	}
}
