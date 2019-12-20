#include "Register16.h"

Register16::Register16(const std::string& initName) :
	Display16Bit(initName),
	name(initName),
	latch0(name + " latch0"),
	latch1(name + " latch1"),
	latch2(name + " latch2"),
	latch3(name + " latch3"),
	latch4(name + " latch4"),
	latch5(name + " latch5"),
	latch6(name + " latch6"),
	latch7(name + " latch7"),
	latch8(name + " latch8"),
	latch9(name + " latch9"),
	latch10(name + " latch10"),
	latch11(name + " latch11"),
	latch12(name + " latch12"),
	latch13(name + " latch13"),
	latch14(name + " latch14"),
	latch15(name + " latch15") {
}


void Register16::AttachEnable(Io* io) {
	latch0.AttachEnable(io);
	latch1.AttachEnable(io);
	latch2.AttachEnable(io);
	latch3.AttachEnable(io);
	latch4.AttachEnable(io);
	latch5.AttachEnable(io);
	latch6.AttachEnable(io);
	latch7.AttachEnable(io);
	latch8.AttachEnable(io);
	latch9.AttachEnable(io);
	latch10.AttachEnable(io);
	latch11.AttachEnable(io);
	latch12.AttachEnable(io);
	latch13.AttachEnable(io);
	latch14.AttachEnable(io);
	latch15.AttachEnable(io);
}


void Register16::AttachCapture(Io* io) {
	latch0.AttachCapture(io);
	latch1.AttachCapture(io);
	latch2.AttachCapture(io);
	latch3.AttachCapture(io);
	latch4.AttachCapture(io);
	latch5.AttachCapture(io);
	latch6.AttachCapture(io);
	latch7.AttachCapture(io);
	latch8.AttachCapture(io);
	latch9.AttachCapture(io);
	latch10.AttachCapture(io);
	latch11.AttachCapture(io);
	latch12.AttachCapture(io);
	latch13.AttachCapture(io);
	latch14.AttachCapture(io);
	latch15.AttachCapture(io);
}


void Register16::AttachInputBus(Bus16* bus) {
	latch0.AttachData(&bus->bits[0]);
	latch1.AttachData(&bus->bits[1]);
	latch2.AttachData(&bus->bits[2]);
	latch3.AttachData(&bus->bits[3]);
	latch4.AttachData(&bus->bits[4]);
	latch5.AttachData(&bus->bits[5]);
	latch6.AttachData(&bus->bits[6]);
	latch7.AttachData(&bus->bits[7]);
	latch8.AttachData(&bus->bits[8]);
	latch9.AttachData(&bus->bits[9]);
	latch10.AttachData(&bus->bits[10]);
	latch11.AttachData(&bus->bits[11]);
	latch12.AttachData(&bus->bits[12]);
	latch13.AttachData(&bus->bits[13]);
	latch14.AttachData(&bus->bits[14]);
	latch15.AttachData(&bus->bits[15]);
}


void Register16::AttachOutputBus(Bus16* bus) {
	bus->bits[0].AttachInput(latch0.GetOutput());
	bus->bits[1].AttachInput(latch1.GetOutput());
	bus->bits[2].AttachInput(latch2.GetOutput());
	bus->bits[3].AttachInput(latch3.GetOutput());
	bus->bits[4].AttachInput(latch4.GetOutput());
	bus->bits[5].AttachInput(latch5.GetOutput());
	bus->bits[6].AttachInput(latch6.GetOutput());
	bus->bits[7].AttachInput(latch7.GetOutput());
	bus->bits[8].AttachInput(latch8.GetOutput());
	bus->bits[9].AttachInput(latch9.GetOutput());
	bus->bits[10].AttachInput(latch10.GetOutput());
	bus->bits[11].AttachInput(latch11.GetOutput());
	bus->bits[12].AttachInput(latch12.GetOutput());
	bus->bits[13].AttachInput(latch13.GetOutput());
	bus->bits[14].AttachInput(latch14.GetOutput());
	bus->bits[15].AttachInput(latch15.GetOutput());
}


void Register16::GetValues(bool* bitValues) {
	bitValues[0] = latch0.GetInternalState();
	bitValues[1] = latch1.GetInternalState();
	bitValues[2] = latch2.GetInternalState();
	bitValues[3] = latch3.GetInternalState();
	bitValues[4] = latch4.GetInternalState();
	bitValues[5] = latch5.GetInternalState();
	bitValues[6] = latch6.GetInternalState();
	bitValues[7] = latch7.GetInternalState();
	bitValues[8] = latch8.GetInternalState();
	bitValues[9] = latch9.GetInternalState();
	bitValues[10] = latch10.GetInternalState();
	bitValues[11] = latch11.GetInternalState();
	bitValues[12] = latch12.GetInternalState();
	bitValues[13] = latch13.GetInternalState();
	bitValues[14] = latch14.GetInternalState();
	bitValues[15] = latch15.GetInternalState();
}
