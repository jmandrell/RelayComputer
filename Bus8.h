#ifndef BUS8_H
#define BUS8_H

#include <string>

#include "Io.h"
#include "Display8Bit.h"

class Bus8 : public Display8Bit {
public:
	Bus8(const std::string& initName);
	Io bits[8];
private:
	void GetValue(bool* bitValues);
	
	const std::string name;
};

#endif
