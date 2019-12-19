#ifndef REGISTER8_H
#define REGISTER8_H

#include <string>

#include "Latch.h"

/// An 8-bit register. Data on the input
/// lines is latched when the capture line is driven,
/// and the outputs are driven when the enable line is
/// driven.
class Register8 {
public:
	Register8(const std::string& initName);
	void AttachCapture(Io* io);
	void AttachEnable(Io* io);
	void AttachIn0(Io* io) {
		latch0.AttachData(io);
	}
	void AttachIn1(Io* io) {
		latch1.AttachData(io);
	}
	void AttachIn2(Io* io) {
		latch2.AttachData(io);
	}
	void AttachIn3(Io* io) {
		latch3.AttachData(io);
	}
	void AttachIn4(Io* io) {
		latch4.AttachData(io);
	}
	void AttachIn5(Io* io) {
		latch5.AttachData(io);
	}
	void AttachIn6(Io* io) {
		latch6.AttachData(io);
	}
	void AttachIn7(Io* io) {
		latch7.AttachData(io);
	}
	Io* GetOut0() {
		return latch0.GetOutput();
	}
	Io* GetOut1() {
		return latch1.GetOutput();
	}
	Io* GetOut2() {
		return latch2.GetOutput();
	}
	Io* GetOut3() {
		return latch3.GetOutput();
	}
	Io* GetOut4() {
		return latch4.GetOutput();
	}
	Io* GetOut5() {
		return latch5.GetOutput();
	}
	Io* GetOut6() {
		return latch6.GetOutput();
	}
	Io* GetOut7() {
		return latch7.GetOutput();
	}
	
private:
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
