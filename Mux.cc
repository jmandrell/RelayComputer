#include "Mux.h"

Mux::Mux(const std::string& initName) :
	name(initName),
	relay1(name + " relay1"),
	relay2(name + " relay2"),
	relay3(name + " relay3"),
	relay4(name + " relay4"),
	relay5(name + " relay5"),
	relay6(name + " relay6"),
	relay7(name + " relay7") {
	relay2.GetCommon()->AttachInput(relay1.GetNc());
	relay3.GetCommon()->AttachInput(relay1.GetNo());
	relay4.GetCommon()->AttachInput(relay2.GetNc());
	relay5.GetCommon()->AttachInput(relay2.GetNo());
	relay6.GetCommon()->AttachInput(relay3.GetNc());
	relay7.GetCommon()->AttachInput(relay3.GetNo());
}
