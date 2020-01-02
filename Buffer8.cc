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
	bit0.AttachCoil(&bus->bits[0]);
	bit1.AttachCoil(&bus->bits[1]);
	bit2.AttachCoil(&bus->bits[2]);
	bit3.AttachCoil(&bus->bits[3]);
	bit4.AttachCoil(&bus->bits[4]);
	bit5.AttachCoil(&bus->bits[5]);
	bit6.AttachCoil(&bus->bits[6]);
	bit7.AttachCoil(&bus->bits[7]);
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
	bit0.GetCommon()->AttachInput(io);
	bit1.GetCommon()->AttachInput(io);
	bit2.GetCommon()->AttachInput(io);
	bit3.GetCommon()->AttachInput(io);
	bit4.GetCommon()->AttachInput(io);
	bit5.GetCommon()->AttachInput(io);
	bit6.GetCommon()->AttachInput(io);
	bit7.GetCommon()->AttachInput(io);
}
