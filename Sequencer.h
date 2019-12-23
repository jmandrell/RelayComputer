#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <iostream>

#include "Clock.h"
#include "Mux.h"
#include "Bus16.h"

class Sequencer : public Clock {
public:
	Sequencer(const std::string& initName);
	void AttachClear(Io* io) {
		clear.AttachInput(io);
	}
	void AttachOutputBus(Bus16* bus);

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
