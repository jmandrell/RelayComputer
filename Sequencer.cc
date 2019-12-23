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
	// TODO: this should be converted to a relay counter
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


void Sequencer::AttachOutputBus(Bus16* bus) {
	bus->bits[0].AttachInput(mux1.GetRightSignal0());
	bus->bits[1].AttachInput(mux1.GetRightSignal1());
	bus->bits[2].AttachInput(mux1.GetRightSignal2());
	bus->bits[3].AttachInput(mux1.GetRightSignal3());
	bus->bits[4].AttachInput(mux1.GetRightSignal4());
	bus->bits[5].AttachInput(mux1.GetRightSignal5());
	bus->bits[6].AttachInput(mux1.GetRightSignal6());
	bus->bits[7].AttachInput(mux1.GetRightSignal7());
	bus->bits[8].AttachInput(mux2.GetRightSignal0());
	bus->bits[9].AttachInput(mux2.GetRightSignal1());
	bus->bits[10].AttachInput(mux2.GetRightSignal2());
	bus->bits[11].AttachInput(mux2.GetRightSignal3());
	bus->bits[12].AttachInput(mux2.GetRightSignal4());
	bus->bits[13].AttachInput(mux2.GetRightSignal5());
	bus->bits[14].AttachInput(mux2.GetRightSignal6());
	bus->bits[15].AttachInput(mux2.GetRightSignal7());
	
}
