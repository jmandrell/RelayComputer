#include "Buffer16.h"

Buffer16::Buffer16(const std::string& initName) :
	name(initName),
	bit0(name + " bit0"),
	bit1(name + " bit1"),
	bit2(name + " bit2"),
	bit3(name + " bit3"),
	bit4(name + " bit4"),
	bit5(name + " bit5"),
	bit6(name + " bit6"),
	bit7(name + " bit7"),
	bit8(name + " bit8"),
	bit9(name + " bit9"),
	bit10(name + " bit10"),
	bit11(name + " bit11"),
	bit12(name + " bit12"),
	bit13(name + " bit13"),
	bit14(name + " bit14"),
	bit15(name + " bit15") {
}


void Buffer16::AttachInputBus(Bus16* bus) {
	bit0.AttachActivate(&bus->bits[0]);
	bit1.AttachActivate(&bus->bits[1]);
	bit2.AttachActivate(&bus->bits[2]);
	bit3.AttachActivate(&bus->bits[3]);
	bit4.AttachActivate(&bus->bits[4]);
	bit5.AttachActivate(&bus->bits[5]);
	bit6.AttachActivate(&bus->bits[6]);
	bit7.AttachActivate(&bus->bits[7]);
	bit8.AttachActivate(&bus->bits[8]);
	bit9.AttachActivate(&bus->bits[9]);
	bit10.AttachActivate(&bus->bits[10]);
	bit11.AttachActivate(&bus->bits[11]);
	bit12.AttachActivate(&bus->bits[12]);
	bit13.AttachActivate(&bus->bits[13]);
	bit14.AttachActivate(&bus->bits[14]);
	bit15.AttachActivate(&bus->bits[15]);
}


void Buffer16::AttachOutputBus(Bus16* bus) {
	bus->bits[0].AttachInput(bit0.GetNo());
	bus->bits[1].AttachInput(bit1.GetNo());
	bus->bits[2].AttachInput(bit2.GetNo());
	bus->bits[3].AttachInput(bit3.GetNo());
	bus->bits[4].AttachInput(bit4.GetNo());
	bus->bits[5].AttachInput(bit5.GetNo());
	bus->bits[6].AttachInput(bit6.GetNo());
	bus->bits[7].AttachInput(bit7.GetNo());
	bus->bits[8].AttachInput(bit8.GetNo());
	bus->bits[9].AttachInput(bit9.GetNo());
	bus->bits[10].AttachInput(bit10.GetNo());
	bus->bits[11].AttachInput(bit11.GetNo());
	bus->bits[12].AttachInput(bit12.GetNo());
	bus->bits[13].AttachInput(bit13.GetNo());
	bus->bits[14].AttachInput(bit14.GetNo());
	bus->bits[15].AttachInput(bit15.GetNo());
}


void Buffer16::AttachEnable(Io* io) {
	bit0.GetCommon()->AttachInput(io);
	bit1.GetCommon()->AttachInput(io);
	bit2.GetCommon()->AttachInput(io);
	bit3.GetCommon()->AttachInput(io);
	bit4.GetCommon()->AttachInput(io);
	bit5.GetCommon()->AttachInput(io);
	bit6.GetCommon()->AttachInput(io);
	bit7.GetCommon()->AttachInput(io);
	bit8.GetCommon()->AttachInput(io);
	bit9.GetCommon()->AttachInput(io);
	bit10.GetCommon()->AttachInput(io);
	bit11.GetCommon()->AttachInput(io);
	bit12.GetCommon()->AttachInput(io);
	bit13.GetCommon()->AttachInput(io);
	bit14.GetCommon()->AttachInput(io);
	bit15.GetCommon()->AttachInput(io);
}
