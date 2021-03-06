GATELIB_SRCS = \
	Io.cc \
	Updatable.cc \
	Display8Bit.cc \
	Display16Bit.cc \
	Relay.cc \
	Buffer8.cc \
	Buffer16.cc \
	Inverter.cc \
	Not8.cc \
	Shr8.cc \
	AndGate.cc \
	And8.cc \
	OrGate.cc \
	Or8.cc \
	XorGate.cc \
	Xor8.cc \
	Sub8.cc \
	Latch.cc \
	Register8.cc \
	Register16.cc \
	FullAdder.cc \
	Adder8.cc \
	Increment8.cc \
	Adder16.cc \
	Increment16.cc \
	Mux.cc \
	Bus8.cc \
	Bus16.cc \
	ALU.cc \
	Memory.cc \
	Clock.cc \
	Sequencer.cc \
	InstructionDecoder.cc \
	Processor.cc

TEST_SRCS = \
	RelayTest.cc \
	Buffer8Test.cc \
	Buffer16Test.cc \
	InverterTest.cc \
	Not8Test.cc \
	Shr8Test.cc \
	AndGateTest.cc \
	And8Test.cc \
	OrGateTest.cc \
	Or8Test.cc \
	XorGateTest.cc \
	Xor8Test.cc \
	Sub8Test.cc \
	LatchTest.cc \
	Register8Test.cc \
	Register16Test.cc \
	FullAdderTest.cc \
	Adder8Test.cc \
	Increment8Test.cc \
	Adder16Test.cc \
	Increment16Test.cc \
	MuxTest.cc \
	Bus8Test.cc \
	Bus16Test.cc \
	ALUTest.cc \
	MemoryTest.cc \
	SequencerTest.cc \
	ProcessorTest.cc

GATELIB = gatelib.a

CC=g++
LDLIBS=-lncurses -lpthread
CXXFLAGS=-O5 -g -Wall -pedantic -ansi -Werror

GATELIB_OBJS = $(GATELIB_SRCS:.cc=.o)
TESTS = $(TEST_SRCS:.cc=)

.PHONY: all

all: $(TESTS)

clean:
	rm -f *.o *.a *.bak $(TESTS)

$(TESTS): TestHarness.o $(GATELIB)

$(GATELIB): $(GATELIB_OBJS)
	ar r $@ $^

depend:
	makedepend -- $(CXXFLAGS) -- *.cc

# DO NOT DELETE

ALU.o: ALU.h Register8.h Latch.h Relay.h Io.h Updatable.h
ALU.o: /usr/include/pthread.h /usr/include/features.h
ALU.o: /usr/include/stdc-predef.h /usr/include/endian.h /usr/include/sched.h
ALU.o: /usr/include/time.h Bus8.h Display8Bit.h Bus16.h Display16Bit.h And8.h
ALU.o: AndGate.h Or8.h OrGate.h Not8.h Inverter.h Xor8.h XorGate.h Adder8.h
ALU.o: FullAdder.h Increment8.h Sub8.h Mux.h Registers.h Register16.h Shr8.h
ALUTest.o: TestHarness.h /usr/include/ncurses.h /usr/include/ncurses_dll.h
ALUTest.o: /usr/include/stdint.h /usr/include/stdio.h /usr/include/unctrl.h
ALUTest.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
ALUTest.o: /usr/include/pthread.h /usr/include/features.h
ALUTest.o: /usr/include/stdc-predef.h /usr/include/endian.h
ALUTest.o: /usr/include/sched.h /usr/include/time.h Bus16.h Display16Bit.h
ALUTest.o: ALU.h Register8.h Latch.h Relay.h And8.h AndGate.h Or8.h OrGate.h
ALUTest.o: Not8.h Inverter.h Xor8.h XorGate.h Adder8.h FullAdder.h
ALUTest.o: Increment8.h Sub8.h Mux.h Registers.h Register16.h Shr8.h
Adder16.o: Adder16.h FullAdder.h XorGate.h Relay.h Io.h Updatable.h
Adder16.o: /usr/include/pthread.h /usr/include/features.h
Adder16.o: /usr/include/stdc-predef.h /usr/include/endian.h
Adder16.o: /usr/include/sched.h /usr/include/time.h OrGate.h AndGate.h
Adder16.o: Bus16.h Display16Bit.h Display8Bit.h
Adder16Test.o: /usr/include/unistd.h /usr/include/features.h
Adder16Test.o: /usr/include/stdc-predef.h TestHarness.h
Adder16Test.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Adder16Test.o: /usr/include/stdint.h /usr/include/stdio.h
Adder16Test.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
Adder16Test.o: Display8Bit.h Updatable.h /usr/include/pthread.h
Adder16Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Adder16Test.o: Bus16.h Display16Bit.h Adder16.h FullAdder.h XorGate.h Relay.h
Adder16Test.o: OrGate.h AndGate.h
Adder8.o: Adder8.h FullAdder.h XorGate.h Relay.h Io.h Updatable.h
Adder8.o: /usr/include/pthread.h /usr/include/features.h
Adder8.o: /usr/include/stdc-predef.h /usr/include/endian.h
Adder8.o: /usr/include/sched.h /usr/include/time.h OrGate.h AndGate.h Bus8.h
Adder8.o: Display8Bit.h
Adder8Test.o: /usr/include/unistd.h /usr/include/features.h
Adder8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Adder8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Adder8Test.o: /usr/include/stdio.h /usr/include/unctrl.h
Adder8Test.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
Adder8Test.o: /usr/include/pthread.h /usr/include/endian.h
Adder8Test.o: /usr/include/sched.h /usr/include/time.h Bus16.h Display16Bit.h
Adder8Test.o: Adder8.h FullAdder.h XorGate.h Relay.h OrGate.h AndGate.h
And8.o: And8.h AndGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
And8.o: /usr/include/features.h /usr/include/stdc-predef.h
And8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Bus8.h
And8.o: Display8Bit.h
And8Test.o: /usr/include/unistd.h /usr/include/features.h
And8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
And8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
And8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
And8Test.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
And8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
And8Test.o: Bus16.h Display16Bit.h And8.h AndGate.h Relay.h
AndGate.o: AndGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
AndGate.o: /usr/include/features.h /usr/include/stdc-predef.h
AndGate.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
AndGateTest.o: /usr/include/unistd.h /usr/include/features.h
AndGateTest.o: /usr/include/stdc-predef.h TestHarness.h
AndGateTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
AndGateTest.o: /usr/include/stdint.h /usr/include/stdio.h
AndGateTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
AndGateTest.o: Display8Bit.h Updatable.h /usr/include/pthread.h
AndGateTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
AndGateTest.o: Bus16.h Display16Bit.h AndGate.h Relay.h
Buffer16.o: Buffer16.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Buffer16.o: /usr/include/features.h /usr/include/stdc-predef.h
Buffer16.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Buffer16.o: Bus16.h Display16Bit.h Display8Bit.h
Buffer16Test.o: TestHarness.h /usr/include/ncurses.h
Buffer16Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Buffer16Test.o: /usr/include/stdio.h /usr/include/unctrl.h
Buffer16Test.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
Buffer16Test.o: /usr/include/pthread.h /usr/include/features.h
Buffer16Test.o: /usr/include/stdc-predef.h /usr/include/endian.h
Buffer16Test.o: /usr/include/sched.h /usr/include/time.h Bus16.h
Buffer16Test.o: Display16Bit.h Buffer16.h Relay.h
Buffer8.o: Buffer8.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Buffer8.o: /usr/include/features.h /usr/include/stdc-predef.h
Buffer8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Buffer8.o: Bus8.h Display8Bit.h
Buffer8Test.o: TestHarness.h /usr/include/ncurses.h
Buffer8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Buffer8Test.o: /usr/include/stdio.h /usr/include/unctrl.h
Buffer8Test.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
Buffer8Test.o: /usr/include/pthread.h /usr/include/features.h
Buffer8Test.o: /usr/include/stdc-predef.h /usr/include/endian.h
Buffer8Test.o: /usr/include/sched.h /usr/include/time.h Bus16.h
Buffer8Test.o: Display16Bit.h Buffer8.h Relay.h
Bus16.o: Bus16.h Io.h Display16Bit.h Updatable.h /usr/include/pthread.h
Bus16.o: /usr/include/features.h /usr/include/stdc-predef.h
Bus16.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Bus16.o: Display8Bit.h
Bus16Test.o: /usr/include/unistd.h /usr/include/features.h
Bus16Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Bus16Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Bus16Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Bus16Test.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
Bus16Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Bus16Test.o: Bus16.h Display16Bit.h
Bus8.o: Bus8.h Io.h Display8Bit.h Updatable.h /usr/include/pthread.h
Bus8.o: /usr/include/features.h /usr/include/stdc-predef.h
Bus8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Bus8Test.o: /usr/include/unistd.h /usr/include/features.h
Bus8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Bus8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Bus8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Bus8Test.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
Bus8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Bus8Test.o: Bus16.h Display16Bit.h
Clock.o: /usr/include/unistd.h /usr/include/features.h
Clock.o: /usr/include/stdc-predef.h Clock.h /usr/include/pthread.h
Clock.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Io.h
Clock.o: Updatable.h Sequencer.h Mux.h Relay.h Bus16.h Display16Bit.h
Clock.o: Display8Bit.h
Display16Bit.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Display16Bit.o: /usr/include/stdint.h /usr/include/stdio.h
Display16Bit.o: /usr/include/unctrl.h /usr/include/curses.h Display16Bit.h
Display16Bit.o: Updatable.h /usr/include/pthread.h /usr/include/features.h
Display16Bit.o: /usr/include/stdc-predef.h /usr/include/endian.h
Display16Bit.o: /usr/include/sched.h /usr/include/time.h Display8Bit.h
Display8Bit.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Display8Bit.o: /usr/include/stdint.h /usr/include/stdio.h
Display8Bit.o: /usr/include/unctrl.h /usr/include/curses.h Display8Bit.h
Display8Bit.o: Updatable.h /usr/include/pthread.h /usr/include/features.h
Display8Bit.o: /usr/include/stdc-predef.h /usr/include/endian.h
Display8Bit.o: /usr/include/sched.h /usr/include/time.h TestHarness.h Io.h
Display8Bit.o: Bus8.h Bus16.h Display16Bit.h
FullAdder.o: FullAdder.h XorGate.h Relay.h Io.h Updatable.h
FullAdder.o: /usr/include/pthread.h /usr/include/features.h
FullAdder.o: /usr/include/stdc-predef.h /usr/include/endian.h
FullAdder.o: /usr/include/sched.h /usr/include/time.h OrGate.h AndGate.h
FullAdderTest.o: /usr/include/unistd.h /usr/include/features.h
FullAdderTest.o: /usr/include/stdc-predef.h TestHarness.h
FullAdderTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
FullAdderTest.o: /usr/include/stdint.h /usr/include/stdio.h
FullAdderTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
FullAdderTest.o: Display8Bit.h Updatable.h /usr/include/pthread.h
FullAdderTest.o: /usr/include/endian.h /usr/include/sched.h
FullAdderTest.o: /usr/include/time.h Bus16.h Display16Bit.h FullAdder.h
FullAdderTest.o: XorGate.h Relay.h OrGate.h AndGate.h
Increment16.o: Increment16.h FullAdder.h XorGate.h Relay.h Io.h Updatable.h
Increment16.o: /usr/include/pthread.h /usr/include/features.h
Increment16.o: /usr/include/stdc-predef.h /usr/include/endian.h
Increment16.o: /usr/include/sched.h /usr/include/time.h OrGate.h AndGate.h
Increment16.o: Bus16.h Display16Bit.h Display8Bit.h
Increment16Test.o: /usr/include/unistd.h /usr/include/features.h
Increment16Test.o: /usr/include/stdc-predef.h TestHarness.h
Increment16Test.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Increment16Test.o: /usr/include/stdint.h /usr/include/stdio.h
Increment16Test.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
Increment16Test.o: Display8Bit.h Updatable.h /usr/include/pthread.h
Increment16Test.o: /usr/include/endian.h /usr/include/sched.h
Increment16Test.o: /usr/include/time.h Bus16.h Display16Bit.h Increment16.h
Increment16Test.o: FullAdder.h XorGate.h Relay.h OrGate.h AndGate.h
Increment8.o: Increment8.h FullAdder.h XorGate.h Relay.h Io.h Updatable.h
Increment8.o: /usr/include/pthread.h /usr/include/features.h
Increment8.o: /usr/include/stdc-predef.h /usr/include/endian.h
Increment8.o: /usr/include/sched.h /usr/include/time.h OrGate.h AndGate.h
Increment8.o: Bus8.h Display8Bit.h
Increment8Test.o: /usr/include/unistd.h /usr/include/features.h
Increment8Test.o: /usr/include/stdc-predef.h TestHarness.h
Increment8Test.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Increment8Test.o: /usr/include/stdint.h /usr/include/stdio.h
Increment8Test.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
Increment8Test.o: Display8Bit.h Updatable.h /usr/include/pthread.h
Increment8Test.o: /usr/include/endian.h /usr/include/sched.h
Increment8Test.o: /usr/include/time.h Bus16.h Display16Bit.h Increment8.h
Increment8Test.o: FullAdder.h XorGate.h Relay.h OrGate.h AndGate.h
InstructionDecoder.o: /usr/include/unistd.h /usr/include/features.h
InstructionDecoder.o: /usr/include/stdc-predef.h InstructionDecoder.h
InstructionDecoder.o: Sequencer.h Clock.h /usr/include/pthread.h
InstructionDecoder.o: /usr/include/endian.h /usr/include/sched.h
InstructionDecoder.o: /usr/include/time.h Io.h Mux.h Relay.h Updatable.h
InstructionDecoder.o: Bus16.h Display16Bit.h Display8Bit.h ALU.h Register8.h
InstructionDecoder.o: Latch.h Bus8.h And8.h AndGate.h Or8.h OrGate.h Not8.h
InstructionDecoder.o: Inverter.h Xor8.h XorGate.h Adder8.h FullAdder.h
InstructionDecoder.o: Increment8.h Sub8.h Registers.h Register16.h Shr8.h
InstructionDecoder.o: Memory.h Increment16.h Buffer16.h Buses.h Components.h
Inverter.o: Inverter.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Inverter.o: /usr/include/features.h /usr/include/stdc-predef.h
Inverter.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
InverterTest.o: /usr/include/unistd.h /usr/include/features.h
InverterTest.o: /usr/include/stdc-predef.h TestHarness.h
InverterTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
InverterTest.o: /usr/include/stdint.h /usr/include/stdio.h
InverterTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
InverterTest.o: Display8Bit.h Updatable.h /usr/include/pthread.h
InverterTest.o: /usr/include/endian.h /usr/include/sched.h
InverterTest.o: /usr/include/time.h Bus16.h Display16Bit.h Inverter.h Relay.h
Io.o: /usr/include/stdlib.h Io.h
Latch.o: Latch.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Latch.o: /usr/include/features.h /usr/include/stdc-predef.h
Latch.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
LatchTest.o: /usr/include/unistd.h /usr/include/features.h
LatchTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
LatchTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
LatchTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
LatchTest.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
LatchTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
LatchTest.o: Bus16.h Display16Bit.h Latch.h Relay.h
Memory.o: /usr/include/stdlib.h /usr/include/fcntl.h /usr/include/features.h
Memory.o: /usr/include/stdc-predef.h /usr/include/unistd.h Memory.h Bus8.h
Memory.o: Io.h Display8Bit.h Updatable.h /usr/include/pthread.h
Memory.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Memory.o: Bus16.h Display16Bit.h
MemoryTest.o: TestHarness.h /usr/include/ncurses.h /usr/include/ncurses_dll.h
MemoryTest.o: /usr/include/stdint.h /usr/include/stdio.h
MemoryTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
MemoryTest.o: Display8Bit.h Updatable.h /usr/include/pthread.h
MemoryTest.o: /usr/include/features.h /usr/include/stdc-predef.h
MemoryTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
MemoryTest.o: Bus16.h Display16Bit.h Memory.h
Mux.o: Mux.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Mux.o: /usr/include/features.h /usr/include/stdc-predef.h
Mux.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
MuxTest.o: /usr/include/unistd.h /usr/include/features.h
MuxTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
MuxTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
MuxTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
MuxTest.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
MuxTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
MuxTest.o: Bus16.h Display16Bit.h Mux.h Relay.h
Not8.o: Not8.h Inverter.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Not8.o: /usr/include/features.h /usr/include/stdc-predef.h
Not8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Bus8.h
Not8.o: Display8Bit.h
Not8Test.o: /usr/include/unistd.h /usr/include/features.h
Not8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Not8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Not8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Not8Test.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
Not8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Not8Test.o: Bus16.h Display16Bit.h Not8.h Inverter.h Relay.h
Or8.o: Or8.h OrGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Or8.o: /usr/include/features.h /usr/include/stdc-predef.h
Or8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Bus8.h
Or8.o: Display8Bit.h
Or8Test.o: /usr/include/unistd.h /usr/include/features.h
Or8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Or8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Or8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Or8Test.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
Or8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Or8Test.o: Bus16.h Display16Bit.h Or8.h OrGate.h Relay.h
OrGate.o: OrGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
OrGate.o: /usr/include/features.h /usr/include/stdc-predef.h
OrGate.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
OrGateTest.o: /usr/include/unistd.h /usr/include/features.h
OrGateTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
OrGateTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
OrGateTest.o: /usr/include/stdio.h /usr/include/unctrl.h
OrGateTest.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
OrGateTest.o: /usr/include/pthread.h /usr/include/endian.h
OrGateTest.o: /usr/include/sched.h /usr/include/time.h Bus16.h Display16Bit.h
OrGateTest.o: OrGate.h Relay.h
Processor.o: /usr/include/unistd.h /usr/include/features.h
Processor.o: /usr/include/stdc-predef.h Processor.h Registers.h Register16.h
Processor.o: Latch.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Processor.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Processor.o: Bus16.h Display16Bit.h Display8Bit.h Register8.h Bus8.h Buses.h
Processor.o: Components.h Memory.h InstructionDecoder.h Sequencer.h Clock.h
Processor.o: Mux.h ALU.h And8.h AndGate.h Or8.h OrGate.h Not8.h Inverter.h
Processor.o: Xor8.h XorGate.h Adder8.h FullAdder.h Increment8.h Sub8.h Shr8.h
Processor.o: Increment16.h Buffer16.h
ProcessorTest.o: Processor.h TestHarness.h /usr/include/ncurses.h
ProcessorTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
ProcessorTest.o: /usr/include/stdio.h /usr/include/unctrl.h
ProcessorTest.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
ProcessorTest.o: /usr/include/pthread.h /usr/include/features.h
ProcessorTest.o: /usr/include/stdc-predef.h /usr/include/endian.h
ProcessorTest.o: /usr/include/sched.h /usr/include/time.h Bus16.h
ProcessorTest.o: Display16Bit.h Clock.h Components.h Memory.h
ProcessorTest.o: InstructionDecoder.h Sequencer.h Mux.h Relay.h ALU.h
ProcessorTest.o: Register8.h Latch.h And8.h AndGate.h Or8.h OrGate.h Not8.h
ProcessorTest.o: Inverter.h Xor8.h XorGate.h Adder8.h FullAdder.h
ProcessorTest.o: Increment8.h Sub8.h Registers.h Register16.h Shr8.h
ProcessorTest.o: Increment16.h Buffer16.h
Register16.o: Register16.h Latch.h Relay.h Io.h Updatable.h
Register16.o: /usr/include/pthread.h /usr/include/features.h
Register16.o: /usr/include/stdc-predef.h /usr/include/endian.h
Register16.o: /usr/include/sched.h /usr/include/time.h Bus16.h Display16Bit.h
Register16.o: Display8Bit.h
Register16Test.o: /usr/include/unistd.h /usr/include/features.h
Register16Test.o: /usr/include/stdc-predef.h TestHarness.h
Register16Test.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Register16Test.o: /usr/include/stdint.h /usr/include/stdio.h
Register16Test.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
Register16Test.o: Display8Bit.h Updatable.h /usr/include/pthread.h
Register16Test.o: /usr/include/endian.h /usr/include/sched.h
Register16Test.o: /usr/include/time.h Bus16.h Display16Bit.h Register16.h
Register16Test.o: Latch.h Relay.h
Register8.o: Register8.h Latch.h Relay.h Io.h Updatable.h
Register8.o: /usr/include/pthread.h /usr/include/features.h
Register8.o: /usr/include/stdc-predef.h /usr/include/endian.h
Register8.o: /usr/include/sched.h /usr/include/time.h Bus8.h Display8Bit.h
Register8.o: Bus16.h Display16Bit.h
Register8Test.o: /usr/include/unistd.h /usr/include/features.h
Register8Test.o: /usr/include/stdc-predef.h TestHarness.h
Register8Test.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Register8Test.o: /usr/include/stdint.h /usr/include/stdio.h
Register8Test.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
Register8Test.o: Display8Bit.h Updatable.h /usr/include/pthread.h
Register8Test.o: /usr/include/endian.h /usr/include/sched.h
Register8Test.o: /usr/include/time.h Bus16.h Display16Bit.h Register8.h
Register8Test.o: Latch.h Relay.h
Relay.o: Relay.h Io.h Updatable.h /usr/include/pthread.h
Relay.o: /usr/include/features.h /usr/include/stdc-predef.h
Relay.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
RelayTest.o: /usr/include/unistd.h /usr/include/features.h
RelayTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
RelayTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
RelayTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
RelayTest.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
RelayTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
RelayTest.o: Bus16.h Display16Bit.h Relay.h
Sequencer.o: Sequencer.h Clock.h /usr/include/pthread.h
Sequencer.o: /usr/include/features.h /usr/include/stdc-predef.h
Sequencer.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Sequencer.o: Io.h Mux.h Relay.h Updatable.h Bus16.h Display16Bit.h
Sequencer.o: Display8Bit.h
SequencerTest.o: Sequencer.h Clock.h /usr/include/pthread.h
SequencerTest.o: /usr/include/features.h /usr/include/stdc-predef.h
SequencerTest.o: /usr/include/endian.h /usr/include/sched.h
SequencerTest.o: /usr/include/time.h Io.h Mux.h Relay.h Updatable.h Bus16.h
SequencerTest.o: Display16Bit.h Display8Bit.h TestHarness.h
SequencerTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
SequencerTest.o: /usr/include/stdint.h /usr/include/stdio.h
SequencerTest.o: /usr/include/unctrl.h /usr/include/curses.h Bus8.h
Shr8.o: Shr8.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Shr8.o: /usr/include/features.h /usr/include/stdc-predef.h
Shr8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Bus8.h
Shr8.o: Display8Bit.h
Shr8Test.o: TestHarness.h /usr/include/ncurses.h /usr/include/ncurses_dll.h
Shr8Test.o: /usr/include/stdint.h /usr/include/stdio.h /usr/include/unctrl.h
Shr8Test.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
Shr8Test.o: /usr/include/pthread.h /usr/include/features.h
Shr8Test.o: /usr/include/stdc-predef.h /usr/include/endian.h
Shr8Test.o: /usr/include/sched.h /usr/include/time.h Bus16.h Display16Bit.h
Shr8Test.o: Shr8.h Relay.h
Sub8.o: Sub8.h FullAdder.h XorGate.h Relay.h Io.h Updatable.h
Sub8.o: /usr/include/pthread.h /usr/include/features.h
Sub8.o: /usr/include/stdc-predef.h /usr/include/endian.h /usr/include/sched.h
Sub8.o: /usr/include/time.h OrGate.h AndGate.h Bus8.h Display8Bit.h
Sub8Test.o: TestHarness.h /usr/include/ncurses.h /usr/include/ncurses_dll.h
Sub8Test.o: /usr/include/stdint.h /usr/include/stdio.h /usr/include/unctrl.h
Sub8Test.o: /usr/include/curses.h Io.h Bus8.h Display8Bit.h Updatable.h
Sub8Test.o: /usr/include/pthread.h /usr/include/features.h
Sub8Test.o: /usr/include/stdc-predef.h /usr/include/endian.h
Sub8Test.o: /usr/include/sched.h /usr/include/time.h Bus16.h Display16Bit.h
Sub8Test.o: Sub8.h FullAdder.h XorGate.h Relay.h OrGate.h AndGate.h
TestHarness.o: /usr/include/stdlib.h /usr/include/string.h
TestHarness.o: /usr/include/unistd.h /usr/include/features.h
TestHarness.o: /usr/include/stdc-predef.h TestHarness.h
TestHarness.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
TestHarness.o: /usr/include/stdint.h /usr/include/stdio.h
TestHarness.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
TestHarness.o: Display8Bit.h Updatable.h /usr/include/pthread.h
TestHarness.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
TestHarness.o: Bus16.h Display16Bit.h Relay.h
Updatable.o: /usr/include/unistd.h /usr/include/features.h
Updatable.o: /usr/include/stdc-predef.h /usr/include/stdlib.h Updatable.h
Updatable.o: /usr/include/pthread.h /usr/include/endian.h
Updatable.o: /usr/include/sched.h /usr/include/time.h
Xor8.o: Xor8.h XorGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Xor8.o: /usr/include/features.h /usr/include/stdc-predef.h
Xor8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Bus8.h
Xor8.o: Display8Bit.h
Xor8Test.o: /usr/include/unistd.h /usr/include/features.h
Xor8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Xor8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Xor8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Xor8Test.o: Io.h Bus8.h Display8Bit.h Updatable.h /usr/include/pthread.h
Xor8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Xor8Test.o: Bus16.h Display16Bit.h Xor8.h XorGate.h Relay.h
XorGate.o: XorGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
XorGate.o: /usr/include/features.h /usr/include/stdc-predef.h
XorGate.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
XorGateTest.o: /usr/include/unistd.h /usr/include/features.h
XorGateTest.o: /usr/include/stdc-predef.h TestHarness.h
XorGateTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
XorGateTest.o: /usr/include/stdint.h /usr/include/stdio.h
XorGateTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Bus8.h
XorGateTest.o: Display8Bit.h Updatable.h /usr/include/pthread.h
XorGateTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
XorGateTest.o: Bus16.h Display16Bit.h XorGate.h Relay.h
