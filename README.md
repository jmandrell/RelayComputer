# RelayComputer
A simulation of a computer built completely from simulated relays.
I call it the 'J80' for no particular reason.

The code is C++ and designed to be built on a Linux system. It depends on
the presence of ncurses to provide a basic UI.

At this point the computer is basically operational, and can run simple
programs. There is a table-driven assembler that was downloaded from the
internet and configured for my processor.

Use the 'make' command to build the various elements and their test
harnesses as well as the final tester named 'ProcessorTest'.

Running the executable ProcessorTest will run the full CPU. It expects a
memory image to be provided in the file 'memory.img'.

There are 16 7-segment LEDs in the UI, mapped to the memory addresses
0xfff0-0xffff. Writes to these addresses are bit-mapped to each of the
segments in each display. A "Hello People" example is in helloj80.asm.
