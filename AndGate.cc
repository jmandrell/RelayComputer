#include "AndGate.h"

AndGate::AndGate(const std::string& initName) : name(initName), relay1(name + " relay1"), relay2(name + " relay2") {
	relay2.GetCommon()->AttachInput(relay1.GetNo());
}

