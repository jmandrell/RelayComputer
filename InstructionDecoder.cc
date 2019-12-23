#include <unistd.h>
#include "InstructionDecoder.h"
#include "Registers.h"
#include "Buses.h"


InstructionDecoder::InstructionDecoder(Memory& initMemory) :
	memory(initMemory),
	sequencer("sequencer"),
	inst("inst"),
	increment16("increment16"),
	arg16("arg16"),
	interal16("internal16"),
	sequencerBus("sequencerBus"),
	decoderBus("decoderBus"),
	top2Bits("top2Bits"),
	middle3Bits("middle3Bits"),
	bottom3Bits("bottom3Bits"),
	test0("test0"),
	test1("test1"),
	test2("test2") {
	// set up the instruction muxers
	power.Force(true);
	top2Bits.GetLeftSignal()->AttachInput(&power);
	middle3Bits.GetLeftSignal()->AttachInput(&power);
	bottom3Bits.GetLeftSignal()->AttachInput(&power);
	
	sequencer.AttachOutputBus(&sequencerBus);
	
	pc.AttachInputBus(&interal16);
	
	increment16.AttachInputBus(&addressBus);
	increment16.AttachOutputBus(&interal16);
	
	arg16.AttachInputBus(&interal16);
	arg16.AttachOutputBus(&interal16);
	
	inst.AttachInputBus(&dataBus);
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
	
	middle3Bits.AttachChannel2(&decoderBus.bits[5]);
	middle3Bits.AttachChannel1(&decoderBus.bits[4]);
	middle3Bits.AttachChannel0(&decoderBus.bits[3]);
	// testing only!
	test1.bits[0].AttachInput(middle3Bits.GetRightSignal0());
	test1.bits[1].AttachInput(middle3Bits.GetRightSignal1());
	test1.bits[2].AttachInput(middle3Bits.GetRightSignal2());
	test1.bits[3].AttachInput(middle3Bits.GetRightSignal3());
	test1.bits[4].AttachInput(middle3Bits.GetRightSignal4());
	test1.bits[5].AttachInput(middle3Bits.GetRightSignal5());
	test1.bits[6].AttachInput(middle3Bits.GetRightSignal6());
	test1.bits[7].AttachInput(middle3Bits.GetRightSignal7());
	
	bottom3Bits.AttachChannel2(&decoderBus.bits[2]);
	bottom3Bits.AttachChannel1(&decoderBus.bits[1]);
	bottom3Bits.AttachChannel0(&decoderBus.bits[0]);
	// testing only!
	test2.bits[0].AttachInput(bottom3Bits.GetRightSignal0());
	test2.bits[1].AttachInput(bottom3Bits.GetRightSignal1());
	test2.bits[2].AttachInput(bottom3Bits.GetRightSignal2());
	test2.bits[3].AttachInput(bottom3Bits.GetRightSignal3());
	test2.bits[4].AttachInput(bottom3Bits.GetRightSignal4());
	test2.bits[5].AttachInput(bottom3Bits.GetRightSignal5());
	test2.bits[6].AttachInput(bottom3Bits.GetRightSignal6());
	test2.bits[7].AttachInput(bottom3Bits.GetRightSignal7());

	//=========================================================
	// set up the sequencing for instruction fetch
	//=========================================================
	unsigned int nextCycle = 0;
	nextCycle = PCReadAndIncrement(inst, nextCycle);
	
	// at this point we have the instruction read into the 'inst' register
	// so we can decode that to see what we need to do
	
	// temporary shortcut!
	//cycle 4: reset to cycle 0
	sequencer.AttachClear(&sequencerBus.bits[nextCycle]);
}

unsigned int InstructionDecoder::PCReadAndIncrement(Register8& data, unsigned int startCycle) {
	// cycle 0, put the PC on the address bus
	pc.AttachEnable(&sequencerBus.bits[startCycle]);
	// cycle 1, read memory and keep PC address on bus
	pc.AttachEnable(&sequencerBus.bits[startCycle + 1]);
	memory.AttachEnable(&sequencerBus.bits[startCycle + 1]);
	data.AttachCapture(&sequencerBus.bits[startCycle + 1]);
	increment16.AttachEnable(&sequencerBus.bits[startCycle + 1]);
	arg16.AttachCapture(&sequencerBus.bits[startCycle + 1]);
	
	// cycle 2, continue memory read, latch into instruction register, increment PC
	pc.AttachEnable(&sequencerBus.bits[startCycle + 2]);
	memory.AttachEnable(&sequencerBus.bits[startCycle + 2]);
	increment16.AttachEnable(&sequencerBus.bits[startCycle + 2]);
	arg16.AttachEnable(&sequencerBus.bits[startCycle + 2]);
	
	// cycle 3, keep next pc on bus
	arg16.AttachEnable(&sequencerBus.bits[startCycle + 3]);
	pc.AttachCapture(&sequencerBus.bits[startCycle + 3]);
	return 4;
	
}
