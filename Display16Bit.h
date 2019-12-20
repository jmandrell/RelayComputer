#ifndef DISPLAY16BIT_H
#define DISPLAY16BIT_H

#include <string>

#include "Updatable.h"
#include "Display8Bit.h"


class Display16Bit : public Updatable {
public:
	Display16Bit(const std::string& initName);
	virtual void GetValues(bool* bits) = 0;
	
private:
	void Update();

	const std::string name;
	unsigned int ourScreenLine;
};

#endif
