#ifndef REGISTER16_H
#define REGISTER16_H

#include <string>

#include "Latch.h"
#include "Bus16.h"
#include "Display16Bit.h"
#include "Enablable.h"


/// A 16-bit register. Data on the input
/// lines is latched when the capture line is driven,
/// and the outputs are driven when the enable line is
/// driven.
class Register16 : public Display16Bit, Enablable {
public:
	Register16(const std::string& initName, bool show = true);
	void AttachCapture(Io* io);
	void AttachEnable(Io* io);
	void AttachInputBus(Bus16* bus);
	void AttachOutputBus(Bus16* bus);
	
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
	Latch latch8;
	Latch latch9;
	Latch latch10;
	Latch latch11;
	Latch latch12;
	Latch latch13;
	Latch latch14;
	Latch latch15;
};
#endif
