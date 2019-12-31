#include <string>
#include <ncurses.h>
#include "Io.h"
#include "Bus8.h"
#include "Bus16.h"

class TestHarness {
public:
	class Callback {
	public:
		virtual unsigned char Read(unsigned int address) = 0;
	};
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
	void Add7SegmentDisplay(unsigned int address, Callback* callback);

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
	struct Display {
		unsigned int address;
		unsigned char lastValue;
		Callback* callback;
	};
	static unsigned int displayCount;
	static Display displays[32];
};
