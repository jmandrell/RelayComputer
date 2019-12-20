#ifndef INCREMENT8_H
#define INCREMENT8_H

#include "FullAdder.h"
#include "Bus8.h"

/// an 8-bit wide incrementer.
/// The results are only output when the enable line is
/// driven.
class Increment8 {
public:
	Increment8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachInputBus(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	Io* GetCarryOut() {
		return faddr7.GetCarryOut();
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
};

#endif
