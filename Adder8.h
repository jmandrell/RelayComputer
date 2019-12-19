#ifndef ADDER8_H
#define ADDER8_H

#include "FullAdder.h"

/// an 8-bit wide adder, including carry in and out.
/// The results are only output when the enable line is
/// driven.
class Adder8 {
public:
	Adder8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachCarryIn(Io* io) {
		faddr0.AttachCarryIn(io);
	}
	void AttachA0(Io* io) {
		faddr0.AttachInput1(io);
	}
	void AttachB0(Io* io) {
		faddr0.AttachInput2(io);
	}
	void AttachA1(Io* io) {
		faddr1.AttachInput1(io);
	}
	void AttachB1(Io* io) {
		faddr1.AttachInput2(io);
	}
	void AttachA2(Io* io) {
		faddr2.AttachInput1(io);
	}
	void AttachB2(Io* io) {
		faddr2.AttachInput2(io);
	}
	void AttachA3(Io* io) {
		faddr3.AttachInput1(io);
	}
	void AttachB3(Io* io) {
		faddr3.AttachInput2(io);
	}
	void AttachA4(Io* io) {
		faddr4.AttachInput1(io);
	}
	void AttachB4(Io* io) {
		faddr4.AttachInput2(io);
	}
	void AttachA5(Io* io) {
		faddr5.AttachInput1(io);
	}
	void AttachB5(Io* io) {
		faddr5.AttachInput2(io);
	}
	void AttachA6(Io* io) {
		faddr6.AttachInput1(io);
	}
	void AttachB6(Io* io) {
		faddr6.AttachInput2(io);
	}
	void AttachA7(Io* io) {
		faddr7.AttachInput1(io);
	}
	void AttachB7(Io* io) {
		faddr7.AttachInput2(io);
	}
	Io* GetSum0() {
		return faddr0.GetSum();
	}
	Io* GetSum1() {
		return faddr1.GetSum();
	}
	Io* GetSum2() {
		return faddr2.GetSum();
	}
	Io* GetSum3() {
		return faddr3.GetSum();
	}
	Io* GetSum4() {
		return faddr4.GetSum();
	}
	Io* GetSum5() {
		return faddr5.GetSum();
	}
	Io* GetSum6() {
		return faddr6.GetSum();
	}
	Io* GetSum7() {
		return faddr7.GetSum();
	}
	Io* GetCarryOut() {
		return faddr7.GetCarryOut();
	}
	
private:
	const std::string name;
	FullAdder faddr0;
	FullAdder faddr1;
	FullAdder faddr2;
	FullAdder faddr3;
	FullAdder faddr4;
	FullAdder faddr5;
	FullAdder faddr6;
	FullAdder faddr7;
};

#endif
