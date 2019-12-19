#ifndef XOR8_H
#define xOR8_H

#include "XorGate.h"

/// an 8-bit binary XOR gate. The output is
/// driven when the enable line is active.
class Xor8 {
public:
	Xor8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachInputA0(Io* io) {
		gate0.AttachInput1(io);
	}
	void AttachInputA1(Io* io) {
		gate1.AttachInput1(io);
	}
	void AttachInputA2(Io* io) {
		gate2.AttachInput1(io);
	}
	void AttachInputA3(Io* io) {
		gate3.AttachInput1(io);
	}
	void AttachInputA4(Io* io) {
		gate4.AttachInput1(io);
	}
	void AttachInputA5(Io* io) {
		gate5.AttachInput1(io);
	}
	void AttachInputA6(Io* io) {
		gate6.AttachInput1(io);
	}
	void AttachInputA7(Io* io) {
		gate7.AttachInput1(io);
	}
	void AttachInputB0(Io* io) {
		gate0.AttachInput2(io);
	}
	void AttachInputB1(Io* io) {
		gate1.AttachInput2(io);
	}
	void AttachInputB2(Io* io) {
		gate2.AttachInput2(io);
	}
	void AttachInputB3(Io* io) {
		gate3.AttachInput2(io);
	}
	void AttachInputB4(Io* io) {
		gate4.AttachInput2(io);
	}
	void AttachInputB5(Io* io) {
		gate5.AttachInput2(io);
	}
	void AttachInputB6(Io* io) {
		gate6.AttachInput2(io);
	}
	void AttachInputB7(Io* io) {
		gate7.AttachInput2(io);
	}
	Io* GetOutput0() {
		return gate0.GetOutput();
	}
	Io* GetOutput1() {
		return gate1.GetOutput();
	}
	Io* GetOutput2() {
		return gate2.GetOutput();
	}
	Io* GetOutput3() {
		return gate3.GetOutput();
	}
	Io* GetOutput4() {
		return gate4.GetOutput();
	}
	Io* GetOutput5() {
		return gate5.GetOutput();
	}
	Io* GetOutput6() {
		return gate6.GetOutput();
	}
	Io* GetOutput7() {
		return gate7.GetOutput();
	}
	
private:
	const std::string name;
	XorGate gate0;
	XorGate gate1;
	XorGate gate2;
	XorGate gate3;
	XorGate gate4;
	XorGate gate5;
	XorGate gate6;
	XorGate gate7;
};

#endif

