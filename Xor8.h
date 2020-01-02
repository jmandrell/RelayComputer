#ifndef XOR8_H
#define xOR8_H

#include "XorGate.h"
#include "Bus8.h"


/// an 8-bit binary XOR gate. The output is
/// driven when the enable line is active.
class Xor8 {
public:
	Xor8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachInputBusA(Bus8* bus);
	void AttachInputBusB(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	
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

