#include <stdlib.h>

#include "Io.h"

static bool forcedReset = false;

Io::Io() {
	force = false;
	inputCount = 0;
	inputs = 0;
}


void Io::ForceReset(bool reset) {
	forcedReset = reset;
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

bool Io::GetOutput(bool useForce) {
	if (forcedReset) {
		return false;
	}
	if (useForce && force) {
		return true;
	}
	if (inputs != 0) {
		for (unsigned int i = 0; i < inputCount; ++i)
		{
			if (inputs[i]->GetOutput()) {
				return true;
			}
		}
	}
	return false;
}
