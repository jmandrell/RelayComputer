#include <stdlib.h>

#include "Io.h"

bool Io::forcedReset = false;

Io::Io() {
	force = false;
	inputCount = 0;
	inputs = 0;
}


void Io::AttachInput(Io* input) {
	if (inputs == 0) {
		inputs = new Io*[100];
	}
	inputs[inputCount++] = input;
	if (inputCount >= 100) {
		exit(1);
	}
}
