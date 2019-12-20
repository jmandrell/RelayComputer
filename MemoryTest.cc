#include "TestHarness.h"
#include "Memory.h"

int main() {
	TestHarness harness;
	Memory memory("memory");
	Bus8 dataBus("dataBus");
	Bus16 addressBus("addressBus");
	Io enable;
	Io write;
	
	memory.AttachEnable(&enable);
	harness.AddInput("Enable", &enable);
	memory.AttachWrite(&write);
	harness.AddInput("Write", &write);
	
	memory.AttachDataBus(&dataBus);
	harness.AddInputBus8("Data in", &dataBus);
	memory.AttachAddressBus(&addressBus);
	harness.AddInputBus16("Address", &addressBus);
	harness.AddOutputBus8("Data out", &dataBus);
	
	harness.Run();
	return 0;
}
