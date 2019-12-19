#include "OrGate.h"

OrGate::OrGate(const std::string& initName) : name(initName), relay1(name + " relay1"), relay2(name + " relay2") {
	output.AttachInput(relay1.GetNo());
	output.AttachInput(relay2.GetNo());
}

