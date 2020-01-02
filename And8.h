#ifndef AND8_H
#define AND8_H

#include "AndGate.h"
#include "Bus8.h"


/// an 8-bit binary AND gate. The output is
/// driven when the enable line is active.
class And8 {
public:
	And8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachInputBusA(Bus8* bus);
	void AttachInputBusB(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	
private:
	const std::string name;
	AndGate gate0;
	AndGate gate1;
	AndGate gate2;
	AndGate gate3;
	AndGate gate4;
	AndGate gate5;
	AndGate gate6;
	AndGate gate7;
};

#endif

