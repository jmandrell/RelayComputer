#include <string>
#include <ncurses.h>
#include "Io.h"
#include "Bus8.h"

class TestHarness {
public:
	TestHarness();
	static void exitFunc();
	static void AddInput(const std::string& label, Io* io);
	static void AddInputBus8(const std::string& label, Bus8* bus);
	static void AddOutput(const std::string& label, Io* io);
	static void AddOutputBus8(const std::string& label, Bus8* bus);
	static void Run();
	
private:
	static void UpdateInputs();
	static void UpdateOutputs();
	static Io* inputs[52];
	static unsigned int inputCount;
	static Io* outputs[26];
	static unsigned int outputCount;
	static WINDOW* mainwin;
};

