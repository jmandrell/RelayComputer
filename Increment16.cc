#include "Increment16.h"

Increment16::Increment16(const std::string& initName) :
	name(initName),
	faddr0(name + " addr0"),
	faddr1(name + " addr1"),
	faddr2(name + " addr2"),
	faddr3(name + " addr3"),
	faddr4(name + " addr4"),
	faddr5(name + " addr5"),
	faddr6(name + " addr6"),
	faddr7(name + " addr7"),
	faddr8(name + " addr8"),
	faddr9(name + " addr9"),
	faddr10(name + " addr10"),
	faddr11(name + " addr11"),
	faddr12(name + " addr12"),
	faddr13(name + " addr13"),
	faddr14(name + " addr14"),
	faddr15(name + " addr15") {
	power.Force(true);
	faddr1.AttachCarryIn(faddr0.GetCarryOut());
	faddr2.AttachCarryIn(faddr1.GetCarryOut());
	faddr3.AttachCarryIn(faddr2.GetCarryOut());
	faddr4.AttachCarryIn(faddr3.GetCarryOut());
	faddr5.AttachCarryIn(faddr4.GetCarryOut());
	faddr6.AttachCarryIn(faddr5.GetCarryOut());
	faddr7.AttachCarryIn(faddr6.GetCarryOut());
	faddr8.AttachCarryIn(faddr7.GetCarryOut());
	faddr9.AttachCarryIn(faddr8.GetCarryOut());
	faddr10.AttachCarryIn(faddr9.GetCarryOut());
	faddr11.AttachCarryIn(faddr10.GetCarryOut());
	faddr12.AttachCarryIn(faddr11.GetCarryOut());
	faddr13.AttachCarryIn(faddr12.GetCarryOut());
	faddr14.AttachCarryIn(faddr13.GetCarryOut());
	faddr15.AttachCarryIn(faddr14.GetCarryOut());
	// force the 2nd input to be a '1'
	faddr0.AttachInput2(&power);
}

void Increment16::AttachEnable(Io* io) {
	faddr0.AttachEnable(io);
	faddr1.AttachEnable(io);
	faddr2.AttachEnable(io);
	faddr3.AttachEnable(io);
	faddr4.AttachEnable(io);
	faddr5.AttachEnable(io);
	faddr6.AttachEnable(io);
	faddr7.AttachEnable(io);
	faddr8.AttachEnable(io);
	faddr9.AttachEnable(io);
	faddr10.AttachEnable(io);
	faddr11.AttachEnable(io);
	faddr12.AttachEnable(io);
	faddr13.AttachEnable(io);
	faddr14.AttachEnable(io);
	faddr15.AttachEnable(io);
}


void Increment16::AttachInputBus(Bus16* bus) {
	faddr0.AttachInput1(&bus->bits[0]);
	faddr1.AttachInput1(&bus->bits[1]);
	faddr2.AttachInput1(&bus->bits[2]);
	faddr3.AttachInput1(&bus->bits[3]);
	faddr4.AttachInput1(&bus->bits[4]);
	faddr5.AttachInput1(&bus->bits[5]);
	faddr6.AttachInput1(&bus->bits[6]);
	faddr7.AttachInput1(&bus->bits[7]);
	faddr8.AttachInput1(&bus->bits[8]);
	faddr9.AttachInput1(&bus->bits[9]);
	faddr10.AttachInput1(&bus->bits[10]);
	faddr11.AttachInput1(&bus->bits[11]);
	faddr12.AttachInput1(&bus->bits[12]);
	faddr13.AttachInput1(&bus->bits[13]);
	faddr14.AttachInput1(&bus->bits[14]);
	faddr15.AttachInput1(&bus->bits[15]);
}


void Increment16::AttachOutputBus(Bus16* bus) {
	bus->bits[0].AttachInput(faddr0.GetSum());
	bus->bits[1].AttachInput(faddr1.GetSum());
	bus->bits[2].AttachInput(faddr2.GetSum());
	bus->bits[3].AttachInput(faddr3.GetSum());
	bus->bits[4].AttachInput(faddr4.GetSum());
	bus->bits[5].AttachInput(faddr5.GetSum());
	bus->bits[6].AttachInput(faddr6.GetSum());
	bus->bits[7].AttachInput(faddr7.GetSum());
	bus->bits[8].AttachInput(faddr8.GetSum());
	bus->bits[9].AttachInput(faddr9.GetSum());
	bus->bits[10].AttachInput(faddr10.GetSum());
	bus->bits[11].AttachInput(faddr11.GetSum());
	bus->bits[12].AttachInput(faddr12.GetSum());
	bus->bits[13].AttachInput(faddr13.GetSum());
	bus->bits[14].AttachInput(faddr14.GetSum());
	bus->bits[15].AttachInput(faddr15.GetSum());
}

