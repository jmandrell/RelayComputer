#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Relay.h"


int main() {
	TestHarness harness;
	Relay relay1("relay 1");
	Io activate1;
	Io armature1;
	Relay relay2("relay 2");
	Io activate2;
	Io no2;
	Io nc2;
	
	relay1.AttachActivate(&activate1);
	harness.AddInput("Relay 1 Activate", &activate1);
	relay1.GetArmature()->AttachInput(&armature1);
	harness.AddInput("Relay 1 Armature", &armature1);
	
	relay2.AttachActivate(&activate2);
	harness.AddInput("Relay 2 Activate", &activate2);
	relay2.GetNo()->AttachInput(&no2);
	harness.AddInput("Relay 2 NO", &no2);
	relay2.GetNc()->AttachInput(&nc2);
	harness.AddInput("Relay 2 NC", &nc2);
	
	harness.AddOutput("Relay 1 NO", relay1.GetNo());
	harness.AddOutput("Relay 1 NC", relay1.GetNc());
	harness.AddOutput("Relay 2 Armature", relay2.GetArmature());
	
	harness.Run();
	return 0;
}
