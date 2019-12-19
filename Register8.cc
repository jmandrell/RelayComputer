#include "Register8.h"

Register8::Register8(const std::string& initName) :
	name(initName),
	latch0(name + " latch0"),
	latch1(name + " latch1"),
	latch2(name + " latch2"),
	latch3(name + " latch3"),
	latch4(name + " latch4"),
	latch5(name + " latch5"),
	latch6(name + " latch6"),
	latch7(name + " latch7") {
}


void Register8::AttachEnable(Io* io) {
	latch0.AttachEnable(io);
	latch1.AttachEnable(io);
	latch2.AttachEnable(io);
	latch3.AttachEnable(io);
	latch4.AttachEnable(io);
	latch5.AttachEnable(io);
	latch6.AttachEnable(io);
	latch7.AttachEnable(io);
}


void Register8::AttachCapture(Io* io) {
	latch0.AttachCapture(io);
	latch1.AttachCapture(io);
	latch2.AttachCapture(io);
	latch3.AttachCapture(io);
	latch4.AttachCapture(io);
	latch5.AttachCapture(io);
	latch6.AttachCapture(io);
	latch7.AttachCapture(io);
}
