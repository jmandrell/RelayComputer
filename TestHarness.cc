#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sstream>

#include "TestHarness.h"
#include "Relay.h"


WINDOW* TestHarness::mainwin = 0;
unsigned int TestHarness::inputCount;
unsigned int TestHarness::outputCount;
Io* TestHarness::inputs[52];
Io* TestHarness::outputs[26];
int* TestHarness::intValue = 0;
std::string TestHarness::intLabel;

int TestHarness::maxX;
int TestHarness::maxY;
int TestHarness::columnWidth;

TestHarness::TestHarness() {
	inputCount = 0;
	for (unsigned int i = 0; i < 52; ++i) {
		inputs[i] = 0;
	}
	outputCount = 0;
	for (unsigned int i = 0; i < 26; ++i) {
		outputs[i] = 0;
	}
	mainwin = initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	clear();
	keypad(mainwin, TRUE);
	
	getmaxyx(mainwin, maxY, maxX);
	columnWidth = maxX / 4;
	mvaddstr(maxY-1, maxX / 2 - 5, "ESC to exit");
	atexit(exitFunc);
}

void TestHarness::exitFunc() {
	delwin(mainwin);
	endwin();
	refresh();
}


void TestHarness::AddInput(const std::string& label, Bus8* bus) {
	for (int i = 0; i < 8; ++i) {
		std::ostringstream newLabel;
		newLabel << label << " " << i;
		AddInput(newLabel.str(), bus->bits + i);
	}
}


void TestHarness::AddInput(const std::string& label, Bus16* bus) {
	for (int i = 0; i < 16; ++i) {
		std::ostringstream newLabel;
		newLabel << label << " " << i;
		AddInput(newLabel.str(), bus->bits + i);
	}
}


void TestHarness::AddInput(const std::string& label, Io* io) {
	const unsigned int col = inputCount / 26;
	const unsigned int row = inputCount % 26;
	char letter = "aA"[col] + row;
	std::string label1 = label + " [" + letter + "]";
	mvaddstr(row + GetReservedLines(), ((col + 2) * columnWidth) - label1.size() - 3, label1.c_str());
	refresh();
	inputs[inputCount++] = io;
}


void TestHarness::AddOutput(const std::string& label, Bus8* bus) {
	for (int i = 0; i < 8; ++i) {
		std::ostringstream newLabel;
		newLabel << label << " " << i;
		AddOutput(newLabel.str(), bus->bits + i);
	}
}


void TestHarness::AddOutput(const std::string& label, Bus16* bus) {
	for (int i = 0; i < 16; ++i) {
		std::ostringstream newLabel;
		newLabel << label << " " << i;
		AddOutput(newLabel.str(), bus->bits + i);
	}
}


void TestHarness::AddOutput(const std::string& label, Io* io) {
	mvaddstr(outputCount + GetReservedLines(), columnWidth * 4 - label.size() - 3, label.c_str());
	outputs[outputCount++] = io;
}


void TestHarness::AddInt(const std::string& label, int* value) {
	intLabel = label;
	intValue = value;
}


void TestHarness::UpdateInputs() {
	for (unsigned int i = 0; i < inputCount; ++i) {
		const int row = i % 26;
		const int col = i / 26;
		if (inputs[i]) {
			bool value = inputs[i]->GetOutput();
			mvaddstr(row + GetReservedLines(), (col + 2) * columnWidth - 2, value ? "*" : "O");
		}
	}
	static int lastIntValue = -999999999;
	if (intValue && lastIntValue != *intValue) {
		std::ostringstream newLabel;
		newLabel << intLabel << " " << *intValue << "        ";
		mvaddstr(maxY - 2, columnWidth, newLabel.str().c_str());
		lastIntValue = *intValue;
	}
}


void TestHarness::UpdateOutputs() {
	for (unsigned int i = 0; i < outputCount; ++i) {
		if (outputs[i]) {
			bool value = outputs[i]->GetOutput();
			mvaddstr(i + GetReservedLines(), columnWidth * 4 - 2, value ? "*" : "O");
		}
	}
}


void TestHarness::Run() {
	Relay::Lock();
	for (;;) {
		Relay::Unlock();
		usleep(100000);
		Relay::Lock();
		UpdateInputs();
		UpdateOutputs();
		refresh();
		int ch = getch();
		if (ch != ERR) {
			move(0, 0);
			clrtoeol();
			if (ch == KEY_UP) {
				*intValue = *intValue + *intValue / 4;
			} else if (ch == KEY_DOWN) {
				*intValue = *intValue * 8 / 10;
			} else if (ch == 27) {
				return;
			} else if ((ch >= 'a') && (ch <= 'z')) {
				unsigned int item = ch - 'a';
				if (inputs[item]) {
					if (inputs[item]->GetOutput()) {
						inputs[item]->Force(false);
					} else {
						inputs[item]->Force(true);
					}
				}
			} else if ((ch >= 'A') && (ch <= 'Z')) {
				unsigned int item = ch - 'A' + 26;
				if (inputs[item]) {
					if (inputs[item]->GetOutput()) {
						inputs[item]->Force(false);
					} else {
						inputs[item]->Force(true);
					}
				}
			} else {
				mvaddstr(0, 20, "Unrecognized character");
				refresh();
			}
		}
	}
}
