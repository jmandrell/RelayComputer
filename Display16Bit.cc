#include <ncurses.h>
#include <iostream>

#include "Display16Bit.h"

Display16Bit::Display16Bit(const std::string& initName) :
	name(initName) {
	ourScreenLine = Display8Bit::GetScreenLine();
}


void Display16Bit::Update() {
	bool bits[16];
	GetValue(bits);
	move(ourScreenLine, 10 - name.size());
	addstr(name.c_str());
	addstr(": ");
	unsigned int value = 0;
	for (int i = 15; i >= 0; --i) {
		value = value + value;
		if (bits[i]) {
			value++;
			addch('*');
		} else {
			addch('O');
		}
	}
	printw(" (0x%04X) %-5d", value, value);
}
