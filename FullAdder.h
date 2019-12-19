#ifndef FULLADDER_H
#define FULLADDER_H

#include "XorGate.h"
#include "OrGate.h"
#include "AndGate.h"

/// a single bit-wide adder, including a carry in and out.
/// The outputs are only enabled when the enable line is
/// driven.
class FullAdder {
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
		xor1.AttachInput2(io);
		and2.AttachInput2(io);
	}
	void AttachCarryIn(Io* io) {
		xor2.AttachInput2(io);
		and1.AttachInput1(io);
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
	XorGate xor1;
	XorGate xor2;
	AndGate and1;
	AndGate and2;
	OrGate orGate;
};

#endif
