#include "Buffer8.h"

Buffer8::Buffer8(const std::string& initName) :
	name(initName),
	bit0(name + " bit0"),
	bit1(name + " bit1"),
	bit2(name + " bit2"),
	bit3(name + " bit3"),
	bit4(name + " bit4"),
	bit5(name + " bit5"),
	bit6(name + " bit6"),
	bit7(name + " bit7") {
}


void Buffer8::AttachInputBus(Bus8* bus) {
	bit0.AttachActivate(&bus->bits[0]);
	bit1.AttachActivate(&bus->bits[1]);
	bit2.AttachActivate(&bus->bits[2]);
	bit3.AttachActivate(&bus->bits[3]);
	bit4.AttachActivate(&bus->bits[4]);
	bit5.AttachActivate(&bus->bits[5]);
	bit6.AttachActivate(&bus->bits[6]);
	bit7.AttachActivate(&bus->bits[7]);
}


void Buffer8::AttachOutputBus(Bus8* bus) {
	bus->bits[0].AttachInput(bit0.GetNo());
	bus->bits[1].AttachInput(bit1.GetNo());
	bus->bits[2].AttachInput(bit2.GetNo());
	bus->bits[3].AttachInput(bit3.GetNo());
	bus->bits[4].AttachInput(bit4.GetNo());
	bus->bits[5].AttachInput(bit5.GetNo());
	bus->bits[6].AttachInput(bit6.GetNo());
	bus->bits[7].AttachInput(bit7.GetNo());
}


void Buffer8::AttachEnable(Io* io) {
	bit0.GetArmature()->AttachInput(io);
	bit1.GetArmature()->AttachInput(io);
	bit2.GetArmature()->AttachInput(io);
	bit3.GetArmature()->AttachInput(io);
	bit4.GetArmature()->AttachInput(io);
	bit5.GetArmature()->AttachInput(io);
	bit6.GetArmature()->AttachInput(io);
	bit7.GetArmature()->AttachInput(io);
}
