#ifndef FULLADDER_H
#define FULLADDER_H

#include "XorGate.h"
#include "OrGate.h"
#include "AndGate.h"
#include "Enablable.h"


/// a single bit-wide adder, including a carry in and out.
/// The outputs are only enabled when the enable line is
/// driven.
class FullAdder : public Enablable {
public:
	FullAdder(const std::string& initName);
	void AttachEnable(Io* io) {
		orGate.AttachEnable(io);
		xor2.AttachEnable(io);
	}
	void AttachInput1(Io* io) {
		xor1.AttachInput1(io);
		and2.AttachInput1(io);
	}
	void AttachInput2(Io* io) {
		xor0.AttachInput1(io);
	}
	void AttachCarryIn(Io* io) {
		xor2.AttachInput2(io);
		and1.AttachInput1(io);
	}
	void AttachInputComplement(Io* io) {
		xor0.AttachInput2(io);
	}
	Io* GetSum() {
		return xor2.GetOutput();
	}
	Io* GetCarryOut() {
		return orGate.GetOutput();
	}

private:
	const std::string name;
	Io power;	
	XorGate xor0;	// used to complement one of the inputs to
					// support subtraction
	XorGate xor1;
	XorGate xor2;
	AndGate and1;
	AndGate and2;
	OrGate orGate;
};

#endif
