#ifndef DISPLAY8BIT_H
#define DISPLAY8BIT_H

#include <string>

#include "Updatable.h"

class Display8Bit : public Updatable {
public:
	Display8Bit(const std::string& initName);
	virtual void GetValues(bool* bits) = 0;
	static unsigned int GetScreenLine() {
		return screenLine++;
	}
private:
	void Update();
	
	static unsigned int screenLine;

	const std::string name;
	unsigned int ourScreenLine;
};

#endif
