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
	bool GetOutput(bool useForce = true);

private:
	bool force;
	unsigned int inputCount;
	Io** inputs;
};

#endif
