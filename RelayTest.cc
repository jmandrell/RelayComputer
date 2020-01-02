#include <iostream>
#include <unistd.h>

#include "TestHarness.h"
#include "Relay.h"


int main() {
	TestHarness harness;
	Relay relay1("relay 1");
	Io coil1;
	Io common1;
	Relay relay2("relay 2");
	Io coil2;
	Io no2;
	Io nc2;

	relay1.AttachCoil(&coil1);
	harness.AddInput("Relay 1 Coil", &coil1);
	relay1.GetCommon()->AttachInput(&common1);
	harness.AddInput("Relay 1 Common", &common1);
	
	relay2.AttachCoil(&coil2);
	harness.AddInput("Relay 2 Coil", &coil2);
	relay2.GetNo()->AttachInput(&no2);
	harness.AddInput("Relay 2 NO", &no2);
	relay2.GetNc()->AttachInput(&nc2);
	harness.AddInput("Relay 2 NC", &nc2);

	harness.AddOutput("Relay 1 NO", relay1.GetNo());
	harness.AddOutput("Relay 1 NC", relay1.GetNc());
	harness.AddOutput("Relay 2 Common", relay2.GetCommon());

	harness.Run();
	return 0;
}
