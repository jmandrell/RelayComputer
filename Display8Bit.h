#ifndef DISPLAY8BIT_H
#define DISPLAY8BIT_H

#include <string>

#include "Updatable.h"

class Display8Bit : public Updatable {
public:
	Display8Bit(const std::string& initName);
	virtual void GetValue(bool* bits) = 0;
	
private:
	void Update();
	
	static unsigned int screenLine;

	const std::string name;
	unsigned int ourScreenLine;
};

#endif
