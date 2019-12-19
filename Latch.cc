#include "Latch.h"

Latch::Latch(const std::string& initName) :
	name(initName),
	relay1(name + " relay1"), 
	relay2(name + " relay2"),
	relay3(name + " relay3") {
	power.Force(true);
	relay2.GetActivate()->AttachInput(relay1.GetNo());
	relay2.GetArmature()->AttachInput(&power);
	relay3.GetArmature()->AttachInput(relay2.GetNo());
	relay3.GetActivate()->AttachInput(relay1.GetNc());
	relay2.GetActivate()->AttachInput(relay3.GetNc());
}

