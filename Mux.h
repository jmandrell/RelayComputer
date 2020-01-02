#ifndef MUX_H
#define MUX_H

#include <string>

#include "Relay.h"

/// A 1-to-8 Mux or 8-to-1 demux class. Since this is made up of
/// relays it can move data in either direction, so depending on how
/// you attach the signals you will get different results.
/// Which signal path is chosen is based on the 3-bit channel
/// signal fed in.
/// To differentiate between the 1 and 8 sides of the mux, the
/// single signal side will be considered to be on the left,
/// and the 8-signal side will be on the right.
class Mux {
public:
	Mux(const std::string& initName);
	void AttachChannel0(Io* io) {
		relay1.AttachCoil(io);
	}
	void AttachChannel1(Io* io) {
		relay2.AttachCoil(io);
		relay3.AttachCoil(io);
	}
	void AttachChannel2(Io* io) {
		relay4.AttachCoil(io);
		relay5.AttachCoil(io);
		relay6.AttachCoil(io);
		relay7.AttachCoil(io);
	}
	Io* GetLeftSignal() {
		return relay1.GetCommon();
	}
	Io* GetRightSignal0() {
		return relay4.GetNc();
	}
	Io* GetRightSignal1() {
		return relay6.GetNc();
	}
	Io* GetRightSignal2() {
		return relay5.GetNc();
	}
	Io* GetRightSignal3() {
		return relay7.GetNc();
	}
	Io* GetRightSignal4() {
		return relay4.GetNo();
	}
	Io* GetRightSignal5() {
		return relay6.GetNo();
	}
	Io* GetRightSignal6() {
		return relay5.GetNo();
	}
	Io* GetRightSignal7() {
		return relay7.GetNo();
	}

private:
	const std::string name;
	Relay relay1;
	Relay relay2;
	Relay relay3;
	Relay relay4;
	Relay relay5;
	Relay relay6;
	Relay relay7;
};
#endif

