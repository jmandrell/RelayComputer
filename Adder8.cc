#include "Adder8.h"

Adder8::Adder8(const std::string& initName) :
	name(initName), faddr0(name + " addr0"),
	faddr1(name + " addr1"), faddr2(name + " addr2"),
	faddr3(name + " addr3"), faddr4(name + " addr4"),
	faddr5(name + " addr5"), faddr6(name + " addr6"),
	faddr7(name + " addr7") {
	faddr1.AttachCarryIn(faddr0.GetCarryOut());
	faddr2.AttachCarryIn(faddr1.GetCarryOut());
	faddr3.AttachCarryIn(faddr2.GetCarryOut());
	faddr4.AttachCarryIn(faddr3.GetCarryOut());
	faddr5.AttachCarryIn(faddr4.GetCarryOut());
	faddr6.AttachCarryIn(faddr5.GetCarryOut());
	faddr7.AttachCarryIn(faddr6.GetCarryOut());
}

void Adder8::AttachEnable(Io* io) {
	faddr0.AttachEnable(io);
	faddr1.AttachEnable(io);
	faddr2.AttachEnable(io);
	faddr3.AttachEnable(io);
	faddr4.AttachEnable(io);
	faddr5.AttachEnable(io);
	faddr6.AttachEnable(io);
	faddr7.AttachEnable(io);
}
