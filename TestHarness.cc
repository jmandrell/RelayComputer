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

static void exitFunc() {
	TestHarness::exitFunc();
}


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

	mvaddstr(29, 0, "ESC to exit");
	atexit(exitFunc);
}

void TestHarness::exitFunc() {
	delwin(mainwin);
	endwin();
	refresh();
}


void TestHarness::AddInputBus8(const std::string& label, Bus8* bus) {
	for (int i = 0; i < 8; ++i) {
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
	mvaddstr(row + 5, (col + 1) * 25 - label1.size(), label1.c_str());
	refresh();
	inputs[inputCount++] = io;
}


void TestHarness::AddOutputBus8(const std::string& label, Bus8* bus) {
	for (int i = 0; i < 8; ++i) {
		std::ostringstream newLabel;
		newLabel << label << " " << i;
		AddOutput(newLabel.str(), bus->bits + i);
	}
}


void TestHarness::AddOutput(const std::string& label, Io* io) {
	mvaddstr(outputCount + 5, 75 - label.size(), label.c_str());
	outputs[outputCount++] = io;
}


void TestHarness::UpdateInputs() {
	for (unsigned int i = 0; i < 52; ++i) {
		const int row = i % 26;
		const int col = i / 26;
		if (inputs[i]) {
			bool value = inputs[i]->GetOutput();
			mvaddstr(row + 5, (col + 1) * 25 + 5, value ? "*" : "O");
		}
	}
}


void TestHarness::UpdateOutputs() {
	for (unsigned int i = 0; i < 26; ++i) {
		if (outputs[i]) {
			bool value = outputs[i]->GetOutput();
			mvaddstr(i + 5, 77, value ? "*" : "O");
		}
	}
}


void TestHarness::Run() {
	Relay::Lock();
	for (;;) {
		Relay::Unlock();
		usleep(50000);
		Relay::Lock();
		UpdateInputs();
		UpdateOutputs();
		refresh();
		int ch = getch();
		if (ch != ERR) {
			move(0, 0);
			clrtoeol();
			if (ch == 27) {
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
				unsigned int item = ch - 'a' + 26;
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
