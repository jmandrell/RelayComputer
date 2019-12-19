GATELIB_SRCS = \
	Io.cc \
	Updatable.cc \
	Relay.cc \
	Inverter.cc \
	AndGate.cc \
	And8.cc \
	OrGate.cc \
	Or8.cc \
	XorGate.cc \
	Xor8.cc \
	Latch.cc \
	Register8.cc \
	FullAdder.cc \
	Adder8.cc \
	Mux.cc

TEST_SRCS = \
	RelayTest.cc \
	InverterTest.cc \
	AndGateTest.cc \
	And8Test.cc \
	OrGateTest.cc \
	Or8Test.cc \
	XorGateTest.cc \
	Xor8Test.cc \
	LatchTest.cc \
	Register8Test.cc \
	FullAdderTest.cc \
	Adder8Test.cc \
	MuxTest.cc

GATELIB = gatelib.a

CC=g++
LDLIBS=-lncurses -lpthread
CXXFLAGS=-g

GATELIB_OBJS = $(GATELIB_SRCS:.cc=.o)
TESTS = $(TEST_SRCS:.cc=)

.PHONY: all

all: $(TESTS)

clean:
	rm -f *.o *.a $(TESTS)

$(TESTS): TestHarness.o $(GATELIB)

$(GATELIB): $(GATELIB_OBJS)
	ar r $@ $^

depend:
	makedepend -- $(CXXFLAGS) -- *.cc

# DO NOT DELETE

Adder8.o: Adder8.h FullAdder.h XorGate.h Relay.h Io.h Updatable.h
Adder8.o: /usr/include/pthread.h /usr/include/features.h
Adder8.o: /usr/include/stdc-predef.h /usr/include/endian.h
Adder8.o: /usr/include/sched.h /usr/include/time.h OrGate.h AndGate.h
Adder8Test.o: /usr/include/unistd.h /usr/include/features.h
Adder8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Adder8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Adder8Test.o: /usr/include/stdio.h /usr/include/unctrl.h
Adder8Test.o: /usr/include/curses.h Io.h Adder8.h FullAdder.h XorGate.h
Adder8Test.o: Relay.h Updatable.h /usr/include/pthread.h
Adder8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Adder8Test.o: OrGate.h AndGate.h
And8.o: And8.h AndGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
And8.o: /usr/include/features.h /usr/include/stdc-predef.h
And8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
And8Test.o: /usr/include/unistd.h /usr/include/features.h
And8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
And8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
And8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
And8Test.o: Io.h And8.h AndGate.h Relay.h Updatable.h /usr/include/pthread.h
And8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
AndGate.o: AndGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
AndGate.o: /usr/include/features.h /usr/include/stdc-predef.h
AndGate.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
AndGateTest.o: /usr/include/unistd.h /usr/include/features.h
AndGateTest.o: /usr/include/stdc-predef.h TestHarness.h
AndGateTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
AndGateTest.o: /usr/include/stdint.h /usr/include/stdio.h
AndGateTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h AndGate.h
AndGateTest.o: Relay.h Updatable.h /usr/include/pthread.h
AndGateTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
FullAdder.o: FullAdder.h XorGate.h Relay.h Io.h Updatable.h
FullAdder.o: /usr/include/pthread.h /usr/include/features.h
FullAdder.o: /usr/include/stdc-predef.h /usr/include/endian.h
FullAdder.o: /usr/include/sched.h /usr/include/time.h OrGate.h AndGate.h
FullAdderTest.o: /usr/include/unistd.h /usr/include/features.h
FullAdderTest.o: /usr/include/stdc-predef.h TestHarness.h
FullAdderTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
FullAdderTest.o: /usr/include/stdint.h /usr/include/stdio.h
FullAdderTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h FullAdder.h
FullAdderTest.o: XorGate.h Relay.h Updatable.h /usr/include/pthread.h
FullAdderTest.o: /usr/include/endian.h /usr/include/sched.h
FullAdderTest.o: /usr/include/time.h OrGate.h AndGate.h
Inverter.o: Inverter.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Inverter.o: /usr/include/features.h /usr/include/stdc-predef.h
Inverter.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
InverterTest.o: /usr/include/unistd.h /usr/include/features.h
InverterTest.o: /usr/include/stdc-predef.h TestHarness.h
InverterTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
InverterTest.o: /usr/include/stdint.h /usr/include/stdio.h
InverterTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Inverter.h
InverterTest.o: Relay.h Updatable.h /usr/include/pthread.h
InverterTest.o: /usr/include/endian.h /usr/include/sched.h
InverterTest.o: /usr/include/time.h
Io.o: Io.h
Latch.o: Latch.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Latch.o: /usr/include/features.h /usr/include/stdc-predef.h
Latch.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
LatchTest.o: /usr/include/unistd.h /usr/include/features.h
LatchTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
LatchTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
LatchTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
LatchTest.o: Io.h Latch.h Relay.h Updatable.h /usr/include/pthread.h
LatchTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Mux.o: Mux.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Mux.o: /usr/include/features.h /usr/include/stdc-predef.h
Mux.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
MuxTest.o: /usr/include/unistd.h /usr/include/features.h
MuxTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
MuxTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
MuxTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
MuxTest.o: Io.h Mux.h Relay.h Updatable.h /usr/include/pthread.h
MuxTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Or8.o: Or8.h OrGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Or8.o: /usr/include/features.h /usr/include/stdc-predef.h
Or8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Or8Test.o: /usr/include/unistd.h /usr/include/features.h
Or8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Or8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Or8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Or8Test.o: Io.h Or8.h OrGate.h Relay.h Updatable.h /usr/include/pthread.h
Or8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
OrGate.o: OrGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
OrGate.o: /usr/include/features.h /usr/include/stdc-predef.h
OrGate.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
OrGateTest.o: /usr/include/unistd.h /usr/include/features.h
OrGateTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
OrGateTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
OrGateTest.o: /usr/include/stdio.h /usr/include/unctrl.h
OrGateTest.o: /usr/include/curses.h Io.h OrGate.h Relay.h Updatable.h
OrGateTest.o: /usr/include/pthread.h /usr/include/endian.h
OrGateTest.o: /usr/include/sched.h /usr/include/time.h
Register8.o: Register8.h Latch.h Relay.h Io.h Updatable.h
Register8.o: /usr/include/pthread.h /usr/include/features.h
Register8.o: /usr/include/stdc-predef.h /usr/include/endian.h
Register8.o: /usr/include/sched.h /usr/include/time.h
Register8Test.o: /usr/include/unistd.h /usr/include/features.h
Register8Test.o: /usr/include/stdc-predef.h TestHarness.h
Register8Test.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Register8Test.o: /usr/include/stdint.h /usr/include/stdio.h
Register8Test.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Register8.h
Register8Test.o: Latch.h Relay.h Updatable.h /usr/include/pthread.h
Register8Test.o: /usr/include/endian.h /usr/include/sched.h
Register8Test.o: /usr/include/time.h
Relay.o: /usr/include/unistd.h /usr/include/features.h
Relay.o: /usr/include/stdc-predef.h Relay.h Io.h Updatable.h
Relay.o: /usr/include/pthread.h /usr/include/endian.h /usr/include/sched.h
Relay.o: /usr/include/time.h
RelayTest.o: /usr/include/unistd.h /usr/include/features.h
RelayTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
RelayTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
RelayTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
RelayTest.o: Io.h Relay.h Updatable.h /usr/include/pthread.h
RelayTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
TestHarness.o: /usr/include/stdlib.h /usr/include/string.h
TestHarness.o: /usr/include/unistd.h /usr/include/features.h
TestHarness.o: /usr/include/stdc-predef.h TestHarness.h
TestHarness.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
TestHarness.o: /usr/include/stdint.h /usr/include/stdio.h
TestHarness.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Relay.h
TestHarness.o: Updatable.h /usr/include/pthread.h /usr/include/endian.h
TestHarness.o: /usr/include/sched.h /usr/include/time.h
Updatable.o: Updatable.h /usr/include/pthread.h /usr/include/features.h
Updatable.o: /usr/include/stdc-predef.h /usr/include/endian.h
Updatable.o: /usr/include/sched.h /usr/include/time.h
Xor8.o: Xor8.h XorGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
Xor8.o: /usr/include/features.h /usr/include/stdc-predef.h
Xor8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Xor8Test.o: /usr/include/unistd.h /usr/include/features.h
Xor8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Xor8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Xor8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Xor8Test.o: Io.h Xor8.h XorGate.h Relay.h Updatable.h /usr/include/pthread.h
Xor8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
XorGate.o: XorGate.h Relay.h Io.h Updatable.h /usr/include/pthread.h
XorGate.o: /usr/include/features.h /usr/include/stdc-predef.h
XorGate.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
XorGateTest.o: /usr/include/unistd.h /usr/include/features.h
XorGateTest.o: /usr/include/stdc-predef.h TestHarness.h
XorGateTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
XorGateTest.o: /usr/include/stdint.h /usr/include/stdio.h
XorGateTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h XorGate.h
XorGateTest.o: Relay.h Updatable.h /usr/include/pthread.h
XorGateTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
