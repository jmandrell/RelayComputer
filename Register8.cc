#include "Register8.h"

Register8::Register8(const std::string& initName) :
	Display8Bit(initName),
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


void Register8::AttachInputBus(Bus8* bus) {
	latch0.AttachData(&bus->bits[0]);
	latch1.AttachData(&bus->bits[1]);
	latch2.AttachData(&bus->bits[2]);
	latch3.AttachData(&bus->bits[3]);
	latch4.AttachData(&bus->bits[4]);
	latch5.AttachData(&bus->bits[5]);
	latch6.AttachData(&bus->bits[6]);
	latch7.AttachData(&bus->bits[7]);
}


void Register8::AttachOutputBus(Bus8* bus) {
	bus->bits[0].AttachInput(latch0.GetOutput());
	bus->bits[1].AttachInput(latch1.GetOutput());
	bus->bits[2].AttachInput(latch2.GetOutput());
	bus->bits[3].AttachInput(latch3.GetOutput());
	bus->bits[4].AttachInput(latch4.GetOutput());
	bus->bits[5].AttachInput(latch5.GetOutput());
	bus->bits[6].AttachInput(latch6.GetOutput());
	bus->bits[7].AttachInput(latch7.GetOutput());
}


void Register8::GetValues(bool* bitValues) {
	bitValues[0] = latch0.GetInternalState();
	bitValues[1] = latch1.GetInternalState();
	bitValues[2] = latch2.GetInternalState();
	bitValues[3] = latch3.GetInternalState();
	bitValues[4] = latch4.GetInternalState();
	bitValues[5] = latch5.GetInternalState();
	bitValues[6] = latch6.GetInternalState();
	bitValues[7] = latch7.GetInternalState();
}
