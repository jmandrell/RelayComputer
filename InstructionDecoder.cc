#include <unistd.h>
#include "InstructionDecoder.h"
#include "Registers.h"
#include "Buses.h"
#include "Components.h"
#include "ALU.h"


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


InstructionDecoder::InstructionDecoder(const std::string& initName) :
	name(initName),
	inst("inst"),
	increment16("increment16"),
	arg16("arg16"),
	interal16("internal16"),
	decoderBus("decoderBus", false),
	top2Bits("top2Bits"),
	test0("test0"),
	dec01("dec01", decoderBus) {
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
	// testing only!
	test0.bits[0].AttachInput(top2Bits.GetRightSignal0());
	test0.bits[1].AttachInput(top2Bits.GetRightSignal1());
	test0.bits[2].AttachInput(top2Bits.GetRightSignal2());
	test0.bits[3].AttachInput(top2Bits.GetRightSignal3());
	test0.bits[4].AttachInput(top2Bits.GetRightSignal4());
	test0.bits[5].AttachInput(top2Bits.GetRightSignal5());
	test0.bits[6].AttachInput(top2Bits.GetRightSignal6());
	test0.bits[7].AttachInput(top2Bits.GetRightSignal7());
		
	//=========================================================
	// set up the sequencing for instruction fetch
	//=========================================================
	unsigned int nextCycle = 0;
	nextCycle = PCReadAndIncrement(inst, nextCycle);
	
	// at this point we have the instruction read into the 'inst' register
	// so we can decode that to see what we need to do
	
	// TODO: process instructions that start with 00 (register moves)
	
	// process instructions that start with 01 (ALU operations)
	dec01.AttachEnable(top2Bits.GetRightSignal1());
	
	// TODO: process instructions that start with 10
	
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
