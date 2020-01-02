#ifndef ALU_H
#define ALU_H

#include <string>

#include "Register8.h"
#include "Bus8.h"
#include "And8.h"
#include "Or8.h"
#include "Not8.h"
#include "Xor8.h"
#include "Adder8.h"
#include "Increment8.h"
#include "Sub8.h"
#include "Mux.h"
#include "Registers.h"
#include "Shr8.h"


class ALU {
public:
	ALU(const std::string& initName);
	void AttachCaptureA(Io* io) {
		inputA.AttachCapture(io);
	}
	void AttachCaptureB(Io* io) {
		inputB.AttachCapture(io);
	}
	void AttachEnable(Io* io) {
		outputRegister.AttachEnable(io);
	}
	void AttachInputBus(Bus8* bus);
	void AttachChannel0(Io* io) {
		mux.AttachChannel0(io);
	}
	void AttachChannel1(Io* io) {
		mux.AttachChannel1(io);
	}
	void AttachChannel2(Io* io) {
		mux.AttachChannel2(io);
	}
	void AttachCaptureOut(Io* io) {
		outputRegister.AttachCapture(io);
		Registers::flags.AttachCapture(io);
	}
	void AttachOutputBus(Bus8* bus);
	
private:
	const std::string name;
	Io power;
	Register8 inputA;
	Bus8 inputABus;
	Register8 inputB;
	Bus8 inputBBus;
	And8 and8;
	Or8 or8;
	Not8 not8;
	Shr8 shr8;
	Xor8 xor8;
	Increment8 increment8;
	Adder8 adder8;
	Sub8 sub8;
	Mux mux;
	Bus8 internalBus;
	Bus8 flagsBus;
	Inverter inverter;
	Register8 outputRegister;
};

#endif
