#include "Increment8.h"

Increment8::Increment8(const std::string& initName) :
	name(initName), faddr0(name + " addr0"),
	faddr1(name + " addr1"), faddr2(name + " addr2"),
	faddr3(name + " addr3"), faddr4(name + " addr4"),
	faddr5(name + " addr5"), faddr6(name + " addr6"),
	faddr7(name + " addr7") {
	power.Force(true);
	faddr1.AttachCarryIn(faddr0.GetCarryOut());
	faddr2.AttachCarryIn(faddr1.GetCarryOut());
	faddr3.AttachCarryIn(faddr2.GetCarryOut());
	faddr4.AttachCarryIn(faddr3.GetCarryOut());
	faddr5.AttachCarryIn(faddr4.GetCarryOut());
	faddr6.AttachCarryIn(faddr5.GetCarryOut());
	faddr7.AttachCarryIn(faddr6.GetCarryOut());
	// force the 2nd input to be a '1'
	faddr0.AttachInput2(&power);
}

void Increment8::AttachEnable(Io* io) {
	faddr0.AttachEnable(io);
	faddr1.AttachEnable(io);
	faddr2.AttachEnable(io);
	faddr3.AttachEnable(io);
	faddr4.AttachEnable(io);
	faddr5.AttachEnable(io);
	faddr6.AttachEnable(io);
	faddr7.AttachEnable(io);
}


void Increment8::AttachInputBus(Bus8* bus) {
	faddr0.AttachInput1(&bus->bits[0]);
	faddr1.AttachInput1(&bus->bits[1]);
	faddr2.AttachInput1(&bus->bits[2]);
	faddr3.AttachInput1(&bus->bits[3]);
	faddr4.AttachInput1(&bus->bits[4]);
	faddr5.AttachInput1(&bus->bits[5]);
	faddr6.AttachInput1(&bus->bits[6]);
	faddr7.AttachInput1(&bus->bits[7]);
}


void Increment8::AttachOutputBus(Bus8* bus) {
	bus->bits[0].AttachInput(faddr0.GetSum());
	bus->bits[1].AttachInput(faddr1.GetSum());
	bus->bits[2].AttachInput(faddr2.GetSum());
	bus->bits[3].AttachInput(faddr3.GetSum());
	bus->bits[4].AttachInput(faddr4.GetSum());
	bus->bits[5].AttachInput(faddr5.GetSum());
	bus->bits[6].AttachInput(faddr6.GetSum());
	bus->bits[7].AttachInput(faddr7.GetSum());
}

