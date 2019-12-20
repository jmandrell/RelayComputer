#ifndef INCREMENT16_H
#define INCREMENT16_H

#include "FullAdder.h"
#include "Bus16.h"

/// an 16-bit wide incrementer.
/// The results are only output when the enable line is
/// driven.
class Increment16 {
public:
	Increment16(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachInputBus(Bus16* bus);
	void AttachOutputBus(Bus16* bus);
	Io* GetCarryOut() {
		return faddr15.GetCarryOut();
	}
	
private:
	const std::string name;
	Io power;
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
