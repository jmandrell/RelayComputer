#include <string>
#include <ncurses.h>
#include "Io.h"
#include "Bus8.h"
#include "Bus16.h"

class TestHarness {
public:
	TestHarness();
	static void exitFunc();
	static void AddInput(const std::string& label, Io* io);
	static void AddInput(const std::string& label, Bus8* bus);
	static void AddInput(const std::string& label, Bus16* bus);
	static void AddOutput(const std::string& label, Io* io);
	static void AddOutput(const std::string& label, Bus8* bus);
	static void AddOutput(const std::string& label, Bus16* bus);
	static void AddInt(const std::string& label, int* value);
	static void Run();
	static int GetReservedLines() {
		return 4;
	}

private:
	static void UpdateInputs();
	static void UpdateOutputs();
	static Io* inputs[52];
	static unsigned int inputCount;
	static Io* outputs[26];
	static unsigned int outputCount;
	static std::string intLabel;
	static int* intValue;
	static WINDOW* mainwin;
	static int maxX;
	static int maxY;
	static int columnWidth;
};

