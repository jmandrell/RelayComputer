#include <ncurses.h>
#include <iostream>

#include "Display8Bit.h"

unsigned int Display8Bit::screenLine = 0;

Display8Bit::Display8Bit(const std::string& initName) :
	name(initName) {
	ourScreenLine = screenLine++;
}


void Display8Bit::Update() {
	bool bits[8];
	GetValue(bits);
	move(ourScreenLine, 10 - name.size());
	addstr(name.c_str());
	addstr(": ");
	unsigned int value = 0;
	for (int i = 7; i >= 0; --i) {
		value = value + value;
		if (bits[i]) {
			value++;
			addch('*');
		} else {
			addch('O');
		}
	}
	printw(" (0x%02X) %-4d", value, value);
}
