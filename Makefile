#GATELIB_SRCS = Io.cc Relay.cc Inverter.cc AndGate.cc OrGate.cc XorGate.cc FullAdder.cc Adder8.cc Latch.cc Register8.cc And8.cc
GATELIB_SRCS = \
	Io.cc \
	Relay.cc \
	Inverter.cc \
	AndGate.cc \
	And8.cc \
	OrGate.cc \
	Or8.cc \
	XorGate.cc \
	Xor8.cc \
	Latch.cc \
	Register8.cc

#TEST_SRCS = RelayTest.cc InverterTest.cc AndGateTest.cc OrGateTest.cc XorGateTest.cc FullAdderTest.cc Adder8Test.cc LatchTest.cc Register8Test.cc And8Test.cc
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
	Register8Test.cc

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

And8.o: And8.h AndGate.h Relay.h /usr/include/pthread.h
And8.o: /usr/include/features.h /usr/include/stdc-predef.h
And8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Io.h
And8Test.o: /usr/include/unistd.h /usr/include/features.h
And8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
And8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
And8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
And8Test.o: Io.h And8.h AndGate.h Relay.h /usr/include/pthread.h
And8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
AndGate.o: AndGate.h Relay.h /usr/include/pthread.h /usr/include/features.h
AndGate.o: /usr/include/stdc-predef.h /usr/include/endian.h
AndGate.o: /usr/include/sched.h /usr/include/time.h Io.h
AndGateTest.o: /usr/include/unistd.h /usr/include/features.h
AndGateTest.o: /usr/include/stdc-predef.h TestHarness.h
AndGateTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
AndGateTest.o: /usr/include/stdint.h /usr/include/stdio.h
AndGateTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h AndGate.h
AndGateTest.o: Relay.h /usr/include/pthread.h /usr/include/endian.h
AndGateTest.o: /usr/include/sched.h /usr/include/time.h
Inverter.o: Inverter.h Relay.h /usr/include/pthread.h /usr/include/features.h
Inverter.o: /usr/include/stdc-predef.h /usr/include/endian.h
Inverter.o: /usr/include/sched.h /usr/include/time.h Io.h
InverterTest.o: /usr/include/unistd.h /usr/include/features.h
InverterTest.o: /usr/include/stdc-predef.h TestHarness.h
InverterTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
InverterTest.o: /usr/include/stdint.h /usr/include/stdio.h
InverterTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Inverter.h
InverterTest.o: Relay.h /usr/include/pthread.h /usr/include/endian.h
InverterTest.o: /usr/include/sched.h /usr/include/time.h
Io.o: Io.h
Latch.o: Latch.h Relay.h /usr/include/pthread.h /usr/include/features.h
Latch.o: /usr/include/stdc-predef.h /usr/include/endian.h
Latch.o: /usr/include/sched.h /usr/include/time.h Io.h
LatchTest.o: /usr/include/unistd.h /usr/include/features.h
LatchTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
LatchTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
LatchTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
LatchTest.o: Io.h Latch.h Relay.h /usr/include/pthread.h
LatchTest.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Or8.o: Or8.h OrGate.h Relay.h /usr/include/pthread.h /usr/include/features.h
Or8.o: /usr/include/stdc-predef.h /usr/include/endian.h /usr/include/sched.h
Or8.o: /usr/include/time.h Io.h
Or8Test.o: /usr/include/unistd.h /usr/include/features.h
Or8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Or8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Or8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Or8Test.o: Io.h Or8.h OrGate.h Relay.h /usr/include/pthread.h
Or8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
OrGate.o: OrGate.h Relay.h /usr/include/pthread.h /usr/include/features.h
OrGate.o: /usr/include/stdc-predef.h /usr/include/endian.h
OrGate.o: /usr/include/sched.h /usr/include/time.h Io.h
OrGateTest.o: /usr/include/unistd.h /usr/include/features.h
OrGateTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
OrGateTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
OrGateTest.o: /usr/include/stdio.h /usr/include/unctrl.h
OrGateTest.o: /usr/include/curses.h Io.h OrGate.h Relay.h
OrGateTest.o: /usr/include/pthread.h /usr/include/endian.h
OrGateTest.o: /usr/include/sched.h /usr/include/time.h
Register8.o: Register8.h Latch.h Relay.h /usr/include/pthread.h
Register8.o: /usr/include/features.h /usr/include/stdc-predef.h
Register8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
Register8.o: Io.h
Register8Test.o: /usr/include/unistd.h /usr/include/features.h
Register8Test.o: /usr/include/stdc-predef.h TestHarness.h
Register8Test.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
Register8Test.o: /usr/include/stdint.h /usr/include/stdio.h
Register8Test.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Register8.h
Register8Test.o: Latch.h Relay.h /usr/include/pthread.h /usr/include/endian.h
Register8Test.o: /usr/include/sched.h /usr/include/time.h
Relay.o: /usr/include/unistd.h /usr/include/features.h
Relay.o: /usr/include/stdc-predef.h Relay.h /usr/include/pthread.h
Relay.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Io.h
RelayTest.o: /usr/include/unistd.h /usr/include/features.h
RelayTest.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
RelayTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
RelayTest.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
RelayTest.o: Io.h Relay.h /usr/include/pthread.h /usr/include/endian.h
RelayTest.o: /usr/include/sched.h /usr/include/time.h
TestHarness.o: /usr/include/stdlib.h /usr/include/string.h
TestHarness.o: /usr/include/unistd.h /usr/include/features.h
TestHarness.o: /usr/include/stdc-predef.h TestHarness.h
TestHarness.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
TestHarness.o: /usr/include/stdint.h /usr/include/stdio.h
TestHarness.o: /usr/include/unctrl.h /usr/include/curses.h Io.h Relay.h
TestHarness.o: /usr/include/pthread.h /usr/include/endian.h
TestHarness.o: /usr/include/sched.h /usr/include/time.h
Xor8.o: Xor8.h XorGate.h Relay.h /usr/include/pthread.h
Xor8.o: /usr/include/features.h /usr/include/stdc-predef.h
Xor8.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h Io.h
Xor8Test.o: /usr/include/unistd.h /usr/include/features.h
Xor8Test.o: /usr/include/stdc-predef.h TestHarness.h /usr/include/ncurses.h
Xor8Test.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Xor8Test.o: /usr/include/stdio.h /usr/include/unctrl.h /usr/include/curses.h
Xor8Test.o: Io.h Xor8.h XorGate.h Relay.h /usr/include/pthread.h
Xor8Test.o: /usr/include/endian.h /usr/include/sched.h /usr/include/time.h
XorGate.o: XorGate.h Relay.h /usr/include/pthread.h /usr/include/features.h
XorGate.o: /usr/include/stdc-predef.h /usr/include/endian.h
XorGate.o: /usr/include/sched.h /usr/include/time.h Io.h
XorGateTest.o: /usr/include/unistd.h /usr/include/features.h
XorGateTest.o: /usr/include/stdc-predef.h TestHarness.h
XorGateTest.o: /usr/include/ncurses.h /usr/include/ncurses_dll.h
XorGateTest.o: /usr/include/stdint.h /usr/include/stdio.h
XorGateTest.o: /usr/include/unctrl.h /usr/include/curses.h Io.h XorGate.h
XorGateTest.o: Relay.h /usr/include/pthread.h /usr/include/endian.h
XorGateTest.o: /usr/include/sched.h /usr/include/time.h
