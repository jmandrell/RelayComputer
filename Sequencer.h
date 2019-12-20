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
		return mux.GetRightSignal0();
	}
	Io* Get1() {
		return mux.GetRightSignal1();
	}
	Io* Get2() {
		return mux.GetRightSignal2();
	}
	Io* Get3() {
		return mux.GetRightSignal3();
	}
	Io* Get4() {
		return mux.GetRightSignal4();
	}
	Io* Get5() {
		return mux.GetRightSignal5();
	}
	Io* Get6() {
		return mux.GetRightSignal6();
	}
	Io* Get7() {
		return mux.GetRightSignal7();
	}

private:
	void Tick();
	void Tock();
	
	const std::string name;
	Mux mux;
	Io power;
	Io clear;
	Io channel0;
	Io channel1;
	Io channel2;
};

#endif
