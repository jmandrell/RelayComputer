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
	seqBuffer.AttachCapture(io);
}


Decoder01::Decoder01(
	const std::string& initName,
	Bus8& decoderBus) :
	name(initName),
	readRegister("readRegister"),
	writeRegister("writeRegister"),
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
	seqBuffer.AttachCapture(io);
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
	increment16.AttachEnable(&Buses::sequencerBus.bits[5]);
	arg16.AttachCapture(&Buses::sequencerBus.bits[5]);
	
	// cycle 6, continue memory read, latch into instruction register, increment PC
	Registers::pc.AttachEnable(&seqOutBus.bits[6]);
	Components::memory.AttachEnable(&seqOutBus.bits[6]);
	increment16.AttachEnable(&seqOutBus.bits[6]);
	arg16.AttachEnable(&seqOutBus.bits[6]);
	Registers::pc.AttachCapture(&seqOutBus.bits[7]);
	
	// cycle 7, keep next pc on bus
	arg16.AttachEnable(&seqOutBus.bits[7]);
	Components::sequencer.AttachClear(&seqOutBus.bits[7]);
}


void Decoder10000::AttachEnable(Io* io) {
	seqBuffer.AttachEnable(io);
	seqBuffer.AttachCapture(io);
}


Decoder10::Decoder10(
        const std::string& initName,
        Bus8& decoderBus,
        Increment16& increment16,
        Register16& arg16) :
        name(initName),
        operation(name + " operation"),
        dec10000("dec10000", decoderBus, increment16, arg16) {
        // the middle 3 bits determine which family of operations we are performing
        operation.AttachChannel0(&decoderBus.bits[3]);
        operation.AttachChannel1(&decoderBus.bits[4]);
        operation.AttachChannel2(&decoderBus.bits[5]);

        dec10000.AttachEnable(operation.GetRightSignal0());
}


void Decoder10::AttachEnable(Io* io) {
        operation.GetLeftSignal()->AttachInput(io);
}


InstructionDecoder::InstructionDecoder(const std::string& initName) :
	name(initName),
	inst("inst"),
	increment16("increment16"),
	arg16("arg16"),
	interal16("internal16"),
	decoderBus("decoderBus", false),
	top2Bits("top2Bits"),
	dec00("dec00", decoderBus),
	dec01("dec01", decoderBus),
	dec10("dec10", decoderBus, increment16, arg16) {
	// set up the instruction muxers
	power.Force(true);
	top2Bits.GetLeftSignal()->AttachInput(&power);
		
	Registers::pc.AttachInputBus(&interal16);
	
	increment16.AttachInputBus(&Buses::addressBus);
	increment16.AttachOutputBus(&interal16);
	
	arg16.AttachInputBus(&interal16);
	arg16.AttachOutputBus(&interal16);
	
	inst.AttachInputBus(&Buses::dataBus);
	inst.AttachEnable(&power);
	inst.AttachOutputBus(&decoderBus);
	
	top2Bits.AttachChannel1(&decoderBus.bits[7]);
	top2Bits.AttachChannel0(&decoderBus.bits[6]);
		
	//=========================================================
	// set up the sequencing for instruction fetch
	//=========================================================
	unsigned int nextCycle = 0;
	nextCycle = PCReadAndIncrement(inst, nextCycle);
	
	// at this point we have the instruction read into the 'inst' register
	// so we can decode that to see what we need to do
	
	// TODO: process instructions that start with 00 (register moves)
	dec00.AttachEnable(top2Bits.GetRightSignal0());

	// process instructions that start with 01 (ALU operations)
	dec01.AttachEnable(top2Bits.GetRightSignal1());
	
	// TODO: process instructions that start with 10
	dec10.AttachEnable(top2Bits.GetRightSignal2());

	// TODO: process instructions that start with 11
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
