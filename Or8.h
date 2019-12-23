#ifndef OR8_H
#define OR8_H

#include "OrGate.h"
#include "Bus8.h"
#include "Enablable.h"


/// an 8-bit binary OR gate. The output is
/// driven when the enable line is active.
class Or8 : public Enablable {
public:
	Or8(const std::string& initName);
	void AttachEnable(Io* io);
	void AttachInputBusA(Bus8* bus);
	void AttachInputBusB(Bus8* bus);
	void AttachOutputBus(Bus8* bus);
	
private:
	const std::string name;
	OrGate gate0;
	OrGate gate1;
	OrGate gate2;
	OrGate gate3;
	OrGate gate4;
	OrGate gate5;
	OrGate gate6;
	OrGate gate7;
};

#endif

