#include "Latch.h"

Latch::Latch(const std::string& initName) :
	name(initName),
	relay1(name + " relay1"), 
	relay2(name + " relay2"),
	relay3(name + " relay3"),
	relay4(name + " relay4") {
	power.Force(true);
	relay2.GetArmature()->AttachInput(&power);
	relay2.AttachActivate(relay1.GetNo());
	relay3.GetArmature()->AttachInput(relay2.GetNo());
	relay3.AttachActivate(relay1.GetNc());
	relay2.AttachActivate(relay3.GetNc());
	relay4.GetArmature()->AttachInput(relay3.GetNc());
}

