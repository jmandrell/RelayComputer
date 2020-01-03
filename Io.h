#ifndef IO_H
#define IO_H

// class the supports connecting a whole group of inputs
// to an output.
// This duplicates a wire-or: if any input is true the
// output is true
class Io {
public:
	Io();
	void AttachInput(Io* input);
	void Force(bool value) {
		force = value;
	}
	bool GetOutput(bool useForce = true) {
		for (unsigned int i = 0; i < inputCount; ++i)
		{
			if (inputs[i]->GetOutput()) {
				// ignore true if we are forcing a reset
				return !forcedReset;
			}
		}
		// force the output true if requested
		return useForce && force;
	}
	static void ForceReset(bool reset) {
		forcedReset = reset;
	}
	
private:
	bool force;
	static bool forcedReset;
	unsigned int inputCount;
	Io** inputs;
};

#endif
