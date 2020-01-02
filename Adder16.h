#ifndef ADDER16_H
#define ADDER16_H

#include "FullAdder.h"
#include "Bus16.h"


/// a 16-bit wide adder, including carry in and out.
/// The results are only output when the enable line is
/// driven.
class Adder16 {
public:
	Adder16(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachCarryIn(Io* io) {
		faddr0.AttachCarryIn(io);
	}
	void AttachInputBusA(Bus16* bus);
	void AttachInputBusB(Bus16* bus);
	void AttachOutputBus(Bus16* bus);
	Io* GetCarryOut() {
		return faddr15.GetCarryOut();
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
	FullAdder faddr8;
	FullAdder faddr9;
	FullAdder faddr10;
	FullAdder faddr11;
	FullAdder faddr12;
	FullAdder faddr13;
	FullAdder faddr14;
	FullAdder faddr15;
};

#endif
