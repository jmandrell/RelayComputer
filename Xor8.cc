#include "Xor8.h"

Xor8::Xor8(const std::string& initName) :
	name(initName),
	gate0(name + " gate0"),
	gate1(name + " gate1"),
	gate2(name + " gate2"),
	gate3(name + " gate3"),
	gate4(name + " gate4"),
	gate5(name + " gate5"),
	gate6(name + " gate6"),
	gate7(name + " gate7") {
}


void Xor8::AttachEnable(Io* io) {
	gate0.AttachEnable(io);
	gate1.AttachEnable(io);
	gate2.AttachEnable(io);
	gate3.AttachEnable(io);
	gate4.AttachEnable(io);
	gate5.AttachEnable(io);
	gate6.AttachEnable(io);
	gate7.AttachEnable(io);
}
