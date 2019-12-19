#ifndef ADDER8_H
#define ADDER8_H

#include "FullAdder.h"
#include "Bus8.h"

/// an 8-bit wide adder, including carry in and out.
/// The results are only output when the enable line is
/// driven.
class Adder8 {
public:
	Adder8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachCarryIn(Io* io) {
		faddr0.AttachCarryIn(io);
	}
	void AttachInputBusA(Bus8* bus);
	void AttachInputBusB(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	Io* GetCarryOut() {
		return faddr7.GetCarryOut();
	}
	
private:
	const std::string name;
	FullAdder faddr0;
	FullAdder faddr1;
	FullAdder faddr2;
	FullAdder faddr3;
	FullAdder faddr4;
	FullAdder faddr5;
	FullAdder faddr6;
	FullAdder faddr7;
};

#endif
