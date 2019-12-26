#ifndef BUS16_H
#define BUS16_H

#include <string>

#include "Io.h"
#include "Display16Bit.h"

class Bus16 : public Display16Bit {
public:
	Bus16(const std::string& initName, bool show = true);
	unsigned int GetValue();
	Io bits[16];

private:
	void GetValues(bool* bitValues);
	
	const std::string name;
};

#endif
