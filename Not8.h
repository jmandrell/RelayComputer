#ifndef Not8_H
#define Not8_H

#include "Inverter.h"
#include "Bus8.h"
#include "Enablable.h"


/// an 8-bit binary NOT gate. The output is
/// driven when the enable line is active.
class Not8 : public Enablable {
public:
	Not8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachInputBus(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	
private:
	const std::string name;
	Inverter gate0;
	Inverter gate1;
	Inverter gate2;
	Inverter gate3;
	Inverter gate4;
	Inverter gate5;
	Inverter gate6;
	Inverter gate7;
};

#endif

