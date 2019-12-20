#include "Sequencer.h"

Sequencer::Sequencer(const std::string& initName) :
	name(initName),
	mux1(name + " mux1"),
	mux2(name + " mux2") {
	mux1.AttachChannel0(&channel0);
	mux1.AttachChannel1(&channel1);
	mux1.AttachChannel2(&channel2);
	mux1.GetLeftSignal()->AttachInput(&mux1Enable);
	mux2.AttachChannel0(&channel0);
	mux2.AttachChannel1(&channel1);
	mux2.AttachChannel2(&channel2);
	mux2.GetLeftSignal()->AttachInput(&mux2Enable);
	Tick();
}


static unsigned int count = 99;

void Sequencer::Tick() {
	if (clear.GetOutput()) {
		count = 0;
	} else {
		count += 1;
		if (count >= 16) {
			count = 0;
		}
	}
	channel0.Force((count & 1) != 0);
	channel1.Force((count & 2) != 0);
	channel2.Force((count & 4) != 0);
	mux1Enable.Force((count & 8) == 0);
	mux2Enable.Force((count & 8) != 0);
}
