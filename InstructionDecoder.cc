#include <unistd.h>
#include "InstructionDecoder.h"
#include "Registers.h"
#include "Buses.h"
#include "Components.h"
#include "ALU.h"


Decoder00::Decoder00(
	const std::string& initName,
	Bus8& decoderBus) :
	name(initName),
	readRegister("readRegister"),
	writeRegister("writeRegister"),
	seqBuffer(name + " seqBuffer"),
	seqOutBus(name + " seqOutBus") {
	seqBuffer.AttachInputBus(&Buses::sequencerBus);
	seqBuffer.AttachOutputBus(&seqOutBus);

	// the bottom 3 bits determine which register is the source
	readRegister.AttachChannel0(&decoderBus.bits[0]);
	readRegister.AttachChannel1(&decoderBus.bits[1]);
	readRegister.AttachChannel2(&decoderBus.bits[2]);

	// the middle 3 bits determine which register is the destination
	writeRegister.AttachChannel0(&decoderBus.bits[3]);
	writeRegister.AttachChannel1(&decoderBus.bits[4]);
	writeRegister.AttachChannel2(&decoderBus.bits[5]);

	// enable register reads based on which register is requested
	Registers::r0.AttachEnable(readRegister.GetRightSignal0());
	Registers::r1.AttachEnable(readRegister.GetRightSignal1());
	Registers::r2.AttachEnable(readRegister.GetRightSignal2());
	Registers::r3.AttachEnable(readRegister.GetRightSignal3());
	Registers::r4.AttachEnable(readRegister.GetRightSignal4());
	Registers::r5.AttachEnable(readRegister.GetRightSignal5());
	Registers::r6.AttachEnable(readRegister.GetRightSignal6());
	Registers::r7.AttachEnable(readRegister.GetRightSignal7());

	// enable register writes based on which register is requested
	Registers::r0.AttachCapture(writeRegister.GetRightSignal0());
	Registers::r1.AttachCapture(writeRegister.GetRightSignal1());
	Registers::r2.AttachCapture(writeRegister.GetRightSignal2());
	Registers::r3.AttachCapture(writeRegister.GetRightSignal3());
	Registers::r4.AttachCapture(writeRegister.GetRightSignal4());
	Registers::r5.AttachCapture(writeRegister.GetRightSignal5());
	Registers::r6.AttachCapture(writeRegister.GetRightSignal6());
	Registers::r7.AttachCapture(writeRegister.GetRightSignal7());

	// cycle 4: put the requested source register on the bus,
	// and capture to the destination register
	readRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[4]);
	writeRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[4]);

	// cycle 5: keep read register on the databus just to keep things stable while we latch it
	readRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[5]);
	Components::sequencer.AttachClear(&seqOutBus.bits[5]);
}


void Decoder00::AttachEnable(Io* io) {
	seqBuffer.AttachEnable(io);
}


Decoder01::Decoder01(
	const std::string& initName,
	Bus8& decoderBus) :
	name(initName),
	readRegister(name + " readRegister"),
	writeRegister(name + " writeRegister"),
	alu(name + " ALU"),
	seqBuffer(name + " seqBuffer"),
	seqOutBus(name + " seqOutBus") {
	seqBuffer.AttachInputBus(&Buses::sequencerBus);
	seqBuffer.AttachOutputBus(&seqOutBus);

	// the bottom 3 bits determine which register we are going to read or write
	readRegister.AttachChannel0(&decoderBus.bits[0]);
	readRegister.AttachChannel1(&decoderBus.bits[1]);
	readRegister.AttachChannel2(&decoderBus.bits[2]);

	writeRegister.AttachChannel0(&decoderBus.bits[0]);
	writeRegister.AttachChannel1(&decoderBus.bits[1]);
	writeRegister.AttachChannel2(&decoderBus.bits[2]);

	// the middle 3 bits determine which operation in the ALU is being performed
	alu.AttachChannel0(&decoderBus.bits[3]);
	alu.AttachChannel1(&decoderBus.bits[4]);
	alu.AttachChannel2(&decoderBus.bits[5]);

	// connect the ALU to the data bus for both input and output
	alu.AttachInputBus(&Buses::dataBus);
	alu.AttachOutputBus(&Buses::dataBus);

	// enable register reads based on which register is requested
	Registers::r0.AttachEnable(readRegister.GetRightSignal0());
	Registers::r1.AttachEnable(readRegister.GetRightSignal1());
	Registers::r2.AttachEnable(readRegister.GetRightSignal2());
	Registers::r3.AttachEnable(readRegister.GetRightSignal3());
	Registers::r4.AttachEnable(readRegister.GetRightSignal4());
	Registers::r5.AttachEnable(readRegister.GetRightSignal5());
	Registers::r6.AttachEnable(readRegister.GetRightSignal6());
	Registers::r7.AttachEnable(readRegister.GetRightSignal7());

	// enable register writes based on which register is requested
	Registers::r0.AttachCapture(writeRegister.GetRightSignal0());
	Registers::r1.AttachCapture(writeRegister.GetRightSignal1());
	Registers::r2.AttachCapture(writeRegister.GetRightSignal2());
	Registers::r3.AttachCapture(writeRegister.GetRightSignal3());
	Registers::r4.AttachCapture(writeRegister.GetRightSignal4());
	Registers::r5.AttachCapture(writeRegister.GetRightSignal5());
	Registers::r6.AttachCapture(writeRegister.GetRightSignal6());
	Registers::r7.AttachCapture(writeRegister.GetRightSignal7());

	// cycle 4: set up to put r0 on the data bus and capture into the B latch
	Registers::r0.AttachEnable(&seqOutBus.bits[4]);
	alu.AttachCaptureB(&seqOutBus.bits[4]);

	// cycle 5: keep r0 on the databus just to keep things stable while we latch it
	Registers::r0.AttachEnable(&seqOutBus.bits[5]);

	// cycle 6: put the requested register on the data bus and capture it into the A latch
	// also capture the results of the ALU calculation
	readRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[6]);
	alu.AttachCaptureA(&seqOutBus.bits[6]);
	alu.AttachCaptureOut(&seqOutBus.bits[6]);

	// cycle 7: keep the register on the data bus while we latch it
	readRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[7]);

	// cycle 8: put the ALU output back on the data bus
	alu.AttachEnable(&seqOutBus.bits[8]);
	writeRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[8]);

	// cycle 9: keep the ALU output there for an extra cycle and reset back to start of cycle
	alu.AttachEnable(&seqOutBus.bits[9]);
	Components::sequencer.AttachClear(&seqOutBus.bits[9]);
}


void Decoder01::AttachEnable(Io* io) {
	seqBuffer.AttachEnable(io);
}


Decoder10000::Decoder10000(
	const std::string& initName,
	Bus8& decoderBus,
	Increment16& increment16,
	Register16& arg16) :
	name(initName),
	whichRegister(name + " whichReg"),
	seqBuffer(name + " seqBuffer"),
	seqOutBus(name + " seqOutBus"),
	arg8(name + " arg8") {

	seqBuffer.AttachInputBus(&Buses::sequencerBus);
	seqBuffer.AttachOutputBus(&seqOutBus);
	arg8.AttachInputBus(&Buses::dataBus);

	// the bottom 3 bits determine which register we are going to read or write
	whichRegister.AttachChannel0(&decoderBus.bits[0]);
	whichRegister.AttachChannel1(&decoderBus.bits[1]);
	whichRegister.AttachChannel2(&decoderBus.bits[2]);

	// enable register writes based on which register is requested
	Registers::r0.AttachCapture(whichRegister.GetRightSignal0());
	Registers::r1.AttachCapture(whichRegister.GetRightSignal1());
	Registers::r2.AttachCapture(whichRegister.GetRightSignal2());
	Registers::r3.AttachCapture(whichRegister.GetRightSignal3());
	Registers::r4.AttachCapture(whichRegister.GetRightSignal4());
	Registers::r5.AttachCapture(whichRegister.GetRightSignal5());
	Registers::r6.AttachCapture(whichRegister.GetRightSignal6());
	Registers::r7.AttachCapture(whichRegister.GetRightSignal7());

	// read the next byte
	// cycle 4, put the PC on the address bus
	Registers::pc.AttachEnable(&seqOutBus.bits[4]);

	// cycle 5, read memory and keep PC address on bus
	Registers::pc.AttachEnable(&seqOutBus.bits[5]);
	Components::memory.AttachEnable(&seqOutBus.bits[5]);
	whichRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[5]);
	increment16.AttachEnable(&seqOutBus.bits[5]);
	arg16.AttachCapture(&seqOutBus.bits[5]);

	// cycle 6, continue memory read, latch into instruction register, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[6]);
	Components::memory.AttachEnable(&seqOutBus.bits[6]);

	// cycle 7, move the next PC to the PC
	arg16.AttachEnable(&seqOutBus.bits[7]);
	Registers::pc.AttachCapture(&seqOutBus.bits[7]);

	// cycle 8, keep next pc on bus
	arg16.AttachEnable(&seqOutBus.bits[8]);
	Components::sequencer.AttachClear(&seqOutBus.bits[8]);
}


void Decoder10000::AttachEnable(Io* io) {
	seqBuffer.AttachEnable(io);
}


Decoder10001::Decoder10001(
	const std::string& initName,
	Bus8& decoderBus,
	Increment16& increment16,
	Register16& arg16) :
	name(initName),
	whichRegister(name + " whichReg"),
	seqBuffer(name + " seqBuffer"),
	seqOutBus(name + " seqOutBus"),
	arg8_1(name + " arg8_1"),
	arg8_2(name + " arg8_2") {
	seqBuffer.AttachInputBus(&Buses::sequencerBus);
	seqBuffer.AttachOutputBus(&seqOutBus);

	arg8_1.AttachInputBus(&Buses::dataBus);
	arg8_1.AttachOutputBus(&Buses::addressBus, false);
	arg8_2.AttachInputBus(&Buses::dataBus);
	arg8_2.AttachOutputBus(&Buses::addressBus, true);
	
	// the bottom 3 bits determine which register we are going to access
	whichRegister.AttachChannel0(&decoderBus.bits[0]);
	whichRegister.AttachChannel1(&decoderBus.bits[1]);
	whichRegister.AttachChannel2(&decoderBus.bits[2]);

	// enable register writes based on which register is requested
	Registers::r0.AttachCapture(whichRegister.GetRightSignal0());
	Registers::r1.AttachCapture(whichRegister.GetRightSignal1());
	Registers::r2.AttachCapture(whichRegister.GetRightSignal2());
	Registers::r3.AttachCapture(whichRegister.GetRightSignal3());
	Registers::r4.AttachCapture(whichRegister.GetRightSignal4());
	Registers::r5.AttachCapture(whichRegister.GetRightSignal5());
	Registers::r6.AttachCapture(whichRegister.GetRightSignal6());
	Registers::r7.AttachCapture(whichRegister.GetRightSignal7());

	// read the next byte (LSB of address)
	// cycle 4, put the PC on the address bus
	Registers::pc.AttachEnable(&seqOutBus.bits[4]);
	Components::memory.AttachEnable(&seqOutBus.bits[4]);
	arg8_1.AttachCapture(&seqOutBus.bits[4]);
	increment16.AttachEnable(&seqOutBus.bits[4]);
	arg16.AttachCapture(&seqOutBus.bits[4]);
	
	// cycle 5, continue memory read, latch into instruction register, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[5]);
	increment16.AttachEnable(&seqOutBus.bits[5]);

	// cycle 6, put new PC on bus and capture it
	arg16.AttachEnable(&seqOutBus.bits[6]);
	Registers::pc.AttachCapture(&seqOutBus.bits[6]);
	Components::memory.AttachEnable(&seqOutBus.bits[6]);

	// cycle 7, keep next pc on bus
	arg16.AttachEnable(&seqOutBus.bits[7]);
	Registers::pc.AttachEnable(&seqOutBus.bits[7]);
	Components::memory.AttachEnable(&seqOutBus.bits[7]);
	arg8_2.AttachCapture(&seqOutBus.bits[7]);

	// cycle 8, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[8]);
	increment16.AttachEnable(&seqOutBus.bits[8]);
	arg16.AttachCapture(&seqOutBus.bits[8]);

	// cycle 9, store the incremented PC
	arg16.AttachEnable(&seqOutBus.bits[9]);
	Registers::pc.AttachCapture(&seqOutBus.bits[9]);
	
	// cycle 10, keep the PC there
	arg16.AttachEnable(&seqOutBus.bits[10]);

	// now we need to perform the memory read as requested
	// cycle 11, put out the address and read the data
	arg8_1.AttachEnable(&seqOutBus.bits[11]);
	arg8_2.AttachEnable(&seqOutBus.bits[11]);
	Components::memory.AttachEnable(&seqOutBus.bits[11]);
	whichRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[11]);
	
	// cycle 12, keep address and stop capture
	arg8_1.AttachEnable(&seqOutBus.bits[12]);
	arg8_2.AttachEnable(&seqOutBus.bits[12]);
	Components::memory.AttachEnable(&seqOutBus.bits[12]);
	Components::sequencer.AttachClear(&seqOutBus.bits[12]);
}


void Decoder10001::AttachEnable(Io* io) {
	seqBuffer.AttachEnable(io);
}


Decoder10010::Decoder10010(
	const std::string& initName,
	Bus8& decoderBus,
	Increment16& increment16,
	Register16& arg16) :
	name(initName),
	whichRegister(name + " whichReg"),
	seqBuffer(name + " seqBuffer"),
	seqOutBus(name + " seqOutBus"),
	arg8_1(name + " arg8_1"),
	arg8_2(name + " arg8_2") {
	seqBuffer.AttachInputBus(&Buses::sequencerBus);
	seqBuffer.AttachOutputBus(&seqOutBus);

	arg8_1.AttachInputBus(&Buses::dataBus);
	arg8_1.AttachOutputBus(&Buses::addressBus, false);
	arg8_2.AttachInputBus(&Buses::dataBus);
	arg8_2.AttachOutputBus(&Buses::addressBus, true);
	
	// the bottom 3 bits determine which register we are going to access
	whichRegister.AttachChannel0(&decoderBus.bits[0]);
	whichRegister.AttachChannel1(&decoderBus.bits[1]);
	whichRegister.AttachChannel2(&decoderBus.bits[2]);

	// enable register reads based on which register is requested
	Registers::r0.AttachEnable(whichRegister.GetRightSignal0());
	Registers::r1.AttachEnable(whichRegister.GetRightSignal1());
	Registers::r2.AttachEnable(whichRegister.GetRightSignal2());
	Registers::r3.AttachEnable(whichRegister.GetRightSignal3());
	Registers::r4.AttachEnable(whichRegister.GetRightSignal4());
	Registers::r5.AttachEnable(whichRegister.GetRightSignal5());
	Registers::r6.AttachEnable(whichRegister.GetRightSignal6());
	Registers::r7.AttachEnable(whichRegister.GetRightSignal7());

	// read the next byte (LSB of address)
	// cycle 4, put the PC on the address bus
	Registers::pc.AttachEnable(&seqOutBus.bits[4]);
	Components::memory.AttachEnable(&seqOutBus.bits[4]);
	arg8_1.AttachCapture(&seqOutBus.bits[4]);
	increment16.AttachEnable(&seqOutBus.bits[4]);
	arg16.AttachCapture(&seqOutBus.bits[4]);
	
	// cycle 5, continue memory read, latch into instruction register, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[5]);
	increment16.AttachEnable(&seqOutBus.bits[5]);

	// cycle 6, put new PC on bus and capture it
	arg16.AttachEnable(&seqOutBus.bits[6]);
	Registers::pc.AttachCapture(&seqOutBus.bits[6]);
	Components::memory.AttachEnable(&seqOutBus.bits[6]);

	// cycle 7, keep next pc on bus
	arg16.AttachEnable(&seqOutBus.bits[7]);
	Registers::pc.AttachEnable(&seqOutBus.bits[7]);
	Components::memory.AttachEnable(&seqOutBus.bits[7]);
	arg8_2.AttachCapture(&seqOutBus.bits[7]);

	// cycle 8, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[8]);
	increment16.AttachEnable(&seqOutBus.bits[8]);
	arg16.AttachCapture(&seqOutBus.bits[8]);

	// cycle 9, store the incremented PC
	arg16.AttachEnable(&seqOutBus.bits[9]);
	Registers::pc.AttachCapture(&seqOutBus.bits[9]);
	
	// cycle 10, keep the PC there
	arg16.AttachEnable(&seqOutBus.bits[10]);

	// now we need to perform the memory write as requested
	// cycle 11, put out the address and write the data
	arg8_1.AttachEnable(&seqOutBus.bits[11]);
	arg8_2.AttachEnable(&seqOutBus.bits[11]);
	Components::memory.AttachWrite(&seqOutBus.bits[11]);
	whichRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[11]);
	
	// cycle 12, keep address and stop capture
	arg8_1.AttachEnable(&seqOutBus.bits[12]);
	arg8_2.AttachEnable(&seqOutBus.bits[12]);
	whichRegister.GetLeftSignal()->AttachInput(&seqOutBus.bits[12]);
	Components::sequencer.AttachClear(&seqOutBus.bits[12]);
}


void Decoder10010::AttachEnable(Io* io) {
	seqBuffer.AttachEnable(io);
}


Decoder1110::Decoder1110(
	const std::string& initName,
	Bus8& decoderBus,
	Bus16& internalBus,
	Increment16& increment16,
	Register16& arg16) :
	name(initName),
	seqBuffer(name + " seqBuffer"),
	seqOutBus(name + " seqOutBus"),
	flagsBus(name + " flagsBus"),
	flagsGate_1(name + " flagsGate_1"),
	flagsGate_2(name + " flagsGate_2"),
	flagsGate_3(name + " flagsGate_3"),
	xor1(name + " xorGate"),
	arg8_1(name + " arg8_1"),
	arg8_2(name + " arg8_2") {
	seqBuffer.AttachInputBus(&Buses::sequencerBus);
	seqBuffer.AttachOutputBus(&seqOutBus);

	Registers::flags.AttachOutputBus(&flagsBus);
	flagsGate_1.AttachActivate(&decoderBus.bits[0]);
	flagsGate_1.GetNc()->AttachInput(&flagsBus.bits[0]);
	flagsGate_1.GetNo()->AttachInput(&flagsBus.bits[1]);
	flagsGate_2.AttachActivate(&decoderBus.bits[0]);
	flagsGate_2.GetNc()->AttachInput(&flagsBus.bits[2]);
	// note that No() is left purposely disconnected for non-conditional branches
	flagsGate_3.AttachActivate(&decoderBus.bits[1]);
	flagsGate_3.GetNc()->AttachInput(flagsGate_1.GetArmature());
	flagsGate_3.GetNo()->AttachInput(flagsGate_2.GetArmature());
	xor1.AttachInput1(flagsGate_3.GetArmature());
	xor1.AttachInput2(&decoderBus.bits[2]);

	arg8_1.AttachInputBus(&Buses::dataBus);
	arg8_1.AttachOutputBus(&internalBus, false);
	arg8_2.AttachInputBus(&Buses::dataBus);
	arg8_2.AttachOutputBus(&internalBus, true);
	
	// read the next byte (LSB of address)
	// cycle 4, put the PC on the address bus
	Registers::pc.AttachEnable(&seqOutBus.bits[4]);
	Components::memory.AttachEnable(&seqOutBus.bits[4]);
	arg8_1.AttachCapture(&seqOutBus.bits[4]);
	increment16.AttachEnable(&seqOutBus.bits[4]);
	arg16.AttachCapture(&seqOutBus.bits[4]);
	
	// cycle 5, continue memory read, latch into instruction register, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[5]);
	increment16.AttachEnable(&seqOutBus.bits[5]);

	// cycle 6, put new PC on bus and capture it
	arg16.AttachEnable(&seqOutBus.bits[6]);
	Registers::pc.AttachCapture(&seqOutBus.bits[6]);
	Components::memory.AttachEnable(&seqOutBus.bits[6]);

	// cycle 7, keep next pc on bus
	arg16.AttachEnable(&seqOutBus.bits[7]);
	Registers::pc.AttachEnable(&seqOutBus.bits[7]);
	Components::memory.AttachEnable(&seqOutBus.bits[7]);
	arg8_2.AttachCapture(&seqOutBus.bits[7]);

	// cycle 8, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[8]);
	increment16.AttachEnable(&seqOutBus.bits[8]);
	arg16.AttachCapture(&seqOutBus.bits[8]);

	// cycle 9, store the incremented PC
	arg16.AttachEnable(&seqOutBus.bits[9]);
	Registers::pc.AttachCapture(&seqOutBus.bits[9]);

	// cycle 10, keep the PC there
	arg16.AttachEnable(&seqOutBus.bits[10]);
	
	// cycle 11, put the jump address on the bus
	arg8_1.AttachEnable(&seqOutBus.bits[11]);
	arg8_2.AttachEnable(&seqOutBus.bits[11]);
	Registers::flags.AttachEnable(&seqOutBus.bits[11]);

	// cycle 12: capture the address if we are supposed to jump
	arg8_1.AttachEnable(&seqOutBus.bits[12]);
	arg8_2.AttachEnable(&seqOutBus.bits[12]);
	Registers::flags.AttachEnable(&seqOutBus.bits[12]);
	xor1.AttachEnable(&seqOutBus.bits[12]);
	Registers::pc.AttachCapture(xor1.GetOutput());

// TODO: save PC off if requested	
	// cycle 13: keep the address on the internal bus
	xor1.AttachEnable(&seqOutBus.bits[13]);
	arg8_1.AttachEnable(xor1.GetOutput());
	arg8_2.AttachEnable(xor1.GetOutput());
	Registers::flags.AttachEnable(&seqOutBus.bits[13]);
	Components::sequencer.AttachClear(&seqOutBus.bits[13]);
}


void Decoder1110::AttachEnable(Io* io) {
	seqBuffer.AttachEnable(io);
}


InstructionDecoder::InstructionDecoder(const std::string& initName) :
	name(initName),
	inst(name + " inst"),
	increment16(name + " increment16"),
	arg16(name + " arg16"),
	internal16(name + " internal16"),
	decoderBus(name + " decoderBus", true),
	bit7Relay(name + " bit7Relay"),
	bit6Relay_0(name + " bit6Relay_0"),
	bit6Relay_1(name + " bit6Relay_1"),
	bit5Relay_10(name + " bit5Relay_10"),
	bit5Relay_11(name + " bit5Relay_11"),
	bit4Relay_100(name + " bit4Relay_100"),
	bit4Relay_111(name + " bit4Relay_111"),
	bit3Relay_1000(name + " bit3Relay_1000"),
	bit3Relay_1001(name + " bit3Relay_1001"),
	dec00(name + " dec00", decoderBus),
	dec01(name + " dec01", decoderBus),
	dec10000(name + " dec10000", decoderBus, increment16, arg16),
	dec10001(name + " dec10001", decoderBus, increment16, arg16),
	dec10010(name + " dec10010", decoderBus, increment16, arg16),
	dec1110(name + " dec1110", decoderBus, internal16, increment16, arg16) {
	Registers::pc.AttachInputBus(&internal16);

	increment16.AttachInputBus(&Buses::addressBus);
	increment16.AttachOutputBus(&internal16);

	arg16.AttachInputBus(&internal16);
	arg16.AttachOutputBus(&internal16);

	inst.AttachInputBus(&Buses::dataBus);
	inst.AttachEnable(&power);
	inst.AttachOutputBus(&decoderBus);

	//=========================================================
	// set up the sequencing for instruction fetch
	//=========================================================
	unsigned int nextCycle = 0;
	nextCycle = PCReadAndIncrement(inst, nextCycle);

	// at this point we have the instruction read into the 'inst' register
	// so we can decode that to see what we need to do

	// set up the instruction muxers
	power.Force(true);
	bit7Relay.GetArmature()->AttachInput(&power);
	bit7Relay.AttachActivate(&decoderBus.bits[7]);
	bit6Relay_0.AttachActivate(&decoderBus.bits[6]);
	bit6Relay_0.GetArmature()->AttachInput(bit7Relay.GetNc());
	bit6Relay_1.AttachActivate(&decoderBus.bits[6]);
	bit6Relay_1.GetArmature()->AttachInput(bit7Relay.GetNo());
	bit5Relay_10.AttachActivate(&decoderBus.bits[5]);
	bit5Relay_10.GetArmature()->AttachInput(bit6Relay_1.GetNc());
	bit5Relay_11.AttachActivate(&decoderBus.bits[5]);
	bit5Relay_11.GetArmature()->AttachInput(bit6Relay_1.GetNo());
	bit4Relay_100.AttachActivate(&decoderBus.bits[4]);
	bit4Relay_100.GetArmature()->AttachInput(bit5Relay_10.GetNc());
	bit4Relay_111.AttachActivate(&decoderBus.bits[4]);
	bit4Relay_111.GetArmature()->AttachInput(bit5Relay_11.GetNo());
	bit3Relay_1000.AttachActivate(&decoderBus.bits[3]);
	bit3Relay_1000.GetArmature()->AttachInput(bit4Relay_100.GetNc());
	bit3Relay_1001.AttachActivate(&decoderBus.bits[3]);
	bit3Relay_1001.GetArmature()->AttachInput(bit4Relay_100.GetNo());

	// process instructions that start with 00 (register moves)
	dec00.AttachEnable(bit6Relay_0.GetNc());

	// process instructions that start with 01 (ALU operations)
	dec01.AttachEnable(bit6Relay_0.GetNo());

	// process instructions that start with 10000
	dec10000.AttachEnable(bit3Relay_1000.GetNc());
	// process instructions that start with 10001
	dec10001.AttachEnable(bit3Relay_1000.GetNo());
	// process instructions that start with 10010
	dec10010.AttachEnable(bit3Relay_1001.GetNc());

	// process instructions that start with 1110 (branches and calls)
	dec1110.AttachEnable(bit4Relay_111.GetNc());
}

unsigned int InstructionDecoder::PCReadAndIncrement(Register8& data, unsigned int startCycle) {
	// cycle 0, put the PC on the address bus
	Registers::pc.AttachEnable(&Buses::sequencerBus.bits[startCycle]);
	// cycle 1, read memory and keep PC address on bus
	Registers::pc.AttachEnable(&Buses::sequencerBus.bits[startCycle + 1]);
	Components::memory.AttachEnable(&Buses::sequencerBus.bits[startCycle + 1]);
	data.AttachCapture(&Buses::sequencerBus.bits[startCycle + 1]);
	increment16.AttachEnable(&Buses::sequencerBus.bits[startCycle + 1]);
	arg16.AttachCapture(&Buses::sequencerBus.bits[startCycle + 1]);
	
	// cycle 2, continue memory read, latch into instruction register, increment PC
	Registers::pc.AttachEnable(&Buses::sequencerBus.bits[startCycle + 2]);
	Components::memory.AttachEnable(&Buses::sequencerBus.bits[startCycle + 2]);
	increment16.AttachEnable(&Buses::sequencerBus.bits[startCycle + 2]);
	arg16.AttachEnable(&Buses::sequencerBus.bits[startCycle + 2]);
	
	// cycle 3, keep next pc on bus
	arg16.AttachEnable(&Buses::sequencerBus.bits[startCycle + 3]);
	Registers::pc.AttachCapture(&Buses::sequencerBus.bits[startCycle + 3]);

	return 4;
}
