#ifndef REGISTER8_H
#define REGISTER8_H

#include <string>

#include "Latch.h"
#include "Bus8.h"
#include "Display8Bit.h"
#include "Enablable.h"


/// An 8-bit register. Data on the input
/// lines is latched when the capture line is driven,
/// and the outputs are driven when the enable line is
/// driven.
class Register8 : public Display8Bit, Enablable {
public:
	Register8(const std::string& initName);
	void AttachCapture(Io* io);
	void AttachEnable(Io* io);
	void AttachInputBus(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	
private:
	void GetValues(bool* bitValues);
	const std::string name;
	Latch latch0;
	Latch latch1;
	Latch latch2;
	Latch latch3;
	Latch latch4;
	Latch latch5;
	Latch latch6;
	Latch latch7;
};
#endif
