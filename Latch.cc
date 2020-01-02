#include "Latch.h"

Latch::Latch(const std::string& initName) :
	name(initName),
	relay1(name + " relay1"), 
	relay2(name + " relay2"),
	relay3(name + " relay3"),
	relay4(name + " relay4") {
	power.Force(true);
	relay2.GetCommon()->AttachInput(&power);
	relay2.AttachActivate(relay1.GetNo());
	relay3.GetCommon()->AttachInput(relay2.GetNo());
	relay3.AttachActivate(relay1.GetNc());
	relay2.AttachActivate(relay3.GetNc());
	relay4.GetCommon()->AttachInput(relay3.GetNc());
}

