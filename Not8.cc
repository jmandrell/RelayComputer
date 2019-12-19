#include "Not8.h"

Not8::Not8(const std::string& initName) :
	name(initName),
	gate0(name + " gate0"),
	gate1(name + " gate1"),
	gate2(name + " gate2"),
	gate3(name + " gate3"),
	gate4(name + " gate4"),
	gate5(name + " gate5"),
	gate6(name + " gate6"),
	gate7(name + " gate7") {
}


void Not8::AttachEnable(Io* io) {
	gate0.AttachEnable(io);
	gate1.AttachEnable(io);
	gate2.AttachEnable(io);
	gate3.AttachEnable(io);
	gate4.AttachEnable(io);
	gate5.AttachEnable(io);
	gate6.AttachEnable(io);
	gate7.AttachEnable(io);
}


void Not8::AttachInputBus(Bus8* bus) {
	gate0.AttachInput(&bus->bits[0]);
	gate1.AttachInput(&bus->bits[1]);
	gate2.AttachInput(&bus->bits[2]);
	gate3.AttachInput(&bus->bits[3]);
	gate4.AttachInput(&bus->bits[4]);
	gate5.AttachInput(&bus->bits[5]);
	gate6.AttachInput(&bus->bits[6]);
	gate7.AttachInput(&bus->bits[7]);
}


void Not8::AttachOutputBus(Bus8* bus) {
	bus->bits[0].AttachInput(gate0.GetOutput());
	bus->bits[1].AttachInput(gate1.GetOutput());
	bus->bits[2].AttachInput(gate2.GetOutput());
	bus->bits[3].AttachInput(gate3.GetOutput());
	bus->bits[4].AttachInput(gate4.GetOutput());
	bus->bits[5].AttachInput(gate5.GetOutput());
	bus->bits[6].AttachInput(gate6.GetOutput());
	bus->bits[7].AttachInput(gate7.GetOutput());
}

