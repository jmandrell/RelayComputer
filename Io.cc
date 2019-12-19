#include "Io.h"

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
}

bool Io::GetOutput(bool useForce) {
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
