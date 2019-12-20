#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <iostream>

#include "Clock.h"
#include "Mux.h"


class Sequencer : public Clock {
public:
	Sequencer(const std::string& initName);
	void AttachClear(Io* io) {
		clear.AttachInput(io);
	}
	Io* Get0() {
		return mux1.GetRightSignal0();
	}
	Io* Get1() {
		return mux1.GetRightSignal1();
	}
	Io* Get2() {
		return mux1.GetRightSignal2();
	}
	Io* Get3() {
		return mux1.GetRightSignal3();
	}
	Io* Get4() {
		return mux1.GetRightSignal4();
	}
	Io* Get5() {
		return mux1.GetRightSignal5();
	}
	Io* Get6() {
		return mux1.GetRightSignal6();
	}
	Io* Get7() {
		return mux1.GetRightSignal7();
	}
	Io* Get8() {
		return mux2.GetRightSignal0();
	}
	Io* Get9() {
		return mux2.GetRightSignal1();
	}
	Io* Get10() {
		return mux2.GetRightSignal2();
	}
	Io* Get11() {
		return mux2.GetRightSignal3();
	}
	Io* Get12() {
		return mux2.GetRightSignal4();
	}
	Io* Get13() {
		return mux2.GetRightSignal5();
	}
	Io* Get14() {
		return mux2.GetRightSignal6();
	}
	Io* Get15() {
		return mux2.GetRightSignal7();
	}

private:
	void Tick();
	
	const std::string name;
	Mux mux1;
	Mux mux2;
	Io mux1Enable;
	Io mux2Enable;
	Io clear;
	Io channel0;
	Io channel1;
	Io channel2;
};

#endif
