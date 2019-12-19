#include "XorGate.h"

XorGate::XorGate(const std::string& initName) : name(initName), relay1(name + " relay1"), relay2(name + " relay2") {
	relay2.GetNo()->AttachInput(relay1.GetNc());
	relay2.GetNc()->AttachInput(relay1.GetNo());
}

