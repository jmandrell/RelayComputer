#ifndef MEMORY_H
#define MEMORY_H

#include <string>

#include "Bus8.h"
#include "Bus16.h"
#include "Updatable.h"

/// This class implements a 64K block of 8-bit memory.
/// It's sort of a cop-out since I'm not actually
/// implementing it with the Relay class, but that just
/// got to be rather repetitive and I want to get this
/// thing running. Maybe later.
/// I'm also taking a short-cut and assuming there is only
/// one address and data bus attached to the memory.
class Memory : public Updatable {
public:
	Memory(const std::string& initName);
	void AttachDataBus(Bus8* bus);
	void AttachAddressBus(Bus16* bus) {
		addressBus = bus;
	}
	void AttachEnable(Io* io) {
		enable.AttachInput(io);
	}
	void AttachWrite(Io* io) {
		write.AttachInput(io);
	}

private:
	void Update();
	const std::string name;
	Bus16* addressBus;
	Bus8* dataBus;
	Bus8 outputData;	// we need to keep a local output bus to
						// drive for reads
	Io enable;
	Io write;
	unsigned char memory[65535];
};

#endif
