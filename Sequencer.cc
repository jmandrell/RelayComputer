#include "Sequencer.h"

Sequencer::Sequencer(const std::string& initName) :
	name(initName),
	mux(name + " mux") {
	power.Force(true);
	mux.AttachChannel0(&channel0);
	mux.AttachChannel1(&channel1);
	mux.AttachChannel2(&channel2);
	mux.GetLeftSignal()->AttachInput(&power);
}


static unsigned int count = 0;

void Sequencer::Tick() {
	if (clear.GetOutput()) {
		count = 0;
	} else {
		count += 1;
		if (count >= 8) {
			count = 0;
		}
	}
	channel0.Force((count & 1) != 0);
	channel1.Force((count & 2) != 0);
	channel2.Force((count & 4) != 0);
}


void Sequencer::Tock() {
	Tick();
}
