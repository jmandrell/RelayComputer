#include "FullAdder.h"

FullAdder::FullAdder(const std::string& initName) :
	name(initName),
	xor1(name + " xor1"), xor2(name + " xor2"),
	and1(name + " and1"), and2(name + " and2"),
	orGate(name + " orGate") {
	power.Force(true);
	xor1.AttachEnable(&power);
	and1.AttachEnable(&power);
	and2.AttachEnable(&power);
	xor2.AttachInput1(xor1.GetOutput());
	and1.AttachInput2(xor1.GetOutput());
	orGate.AttachInput1(and1.GetOutput());
	orGate.AttachInput2(and2.GetOutput());
}
