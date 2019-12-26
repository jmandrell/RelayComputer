#include <ncurses.h>
#include <iostream>

#include "Display8Bit.h"
#include "TestHarness.h"

unsigned int Display8Bit::screenLine = TestHarness::GetReservedLines();

Display8Bit::Display8Bit(const std::string& initName, bool show) :
	Updatable(show),
	name(initName) {
	if (show) {
		ourScreenLine = GetScreenLine();
	}
}


void Display8Bit::Update() {
	bool bits[8];
	GetValues(bits);
	move(ourScreenLine, 30 - name.size());
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
