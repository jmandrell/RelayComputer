#ifndef _SOLO_ASM_INC
#define _SOLO_ASM_INC
#include <stdio.h>
#include <stdlib.h>
#include <soloasm.h>

// We assume the first ORG is the lowest address
#define ORG(n) unsigned int genasm(int _solo_pass) { \
   unsigned _solo_add=n;\
   _solo_info.psize=8; \
   _solo_info.begin=n; \
   _solo_info.memsize=0xFFFF; \
   _solo_info.ary=malloc(_solo_info.memsize)


#define REORG(n) _solo_add=n;
#define END _solo_info.end=_solo_add-1; return _solo_add; }

#define DEFLABEL(l) static unsigned l
#define LABEL(l) l=_solo_add

#define DB(n) _solo_info.ary[_solo_add++]=(n)
#define DW(n) DB((n)%256); DB((n)/256)

// register values for 8-bit operations
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define r0 0
#define r1 1
#define r2 2
#define r3 3
#define r4 4
#define r5 5
#define r6 6
#define r7 7
// register values when a 16-bit register pair is used
#define R01 0
#define R23 1
#define R45 2
#define R67 3
#define r01 0
#define r23 1
#define r45 2
#define r67 3

#define REGPOS0(r)	((r)&7)
#define REGPOS1(r)	(((r)&7)<< 3)

///////////////////////////////////////////////////////////
// the instructions start here
// the entries are duplicated to allow lower-case
#define MOV(d,s)	DB(0x00+REGPOS1(d)+REGPOS0(s))
#define mov(d,s)	DB(0x00+REGPOS1(d)+REGPOS0(s))

// ALU operations
#define INC(r)		DB(0x40+REGPOS0(r))	// r = r + 1
#define NOT(r)		DB(0x48+REGPOS0(r))	// r = ~r
#define AND(r)		DB(0x50+REGPOS0(r))	// r = r & r0
#define OR(r)		DB(0x58+REGPOS0(r))	// r = r | r0
#define XOR(r)		DB(0x60+REGPOS0(r))	// r = r ^ r0
#define SHR(r)		DB(0x68+REGPOS0(r))	// r = r >> 1
#define ADD(r)		DB(0x70+REGPOS0(r))	// r = r + r0
#define SUB(r)		DB(0x78+REGPOS0(r))	// r = r - r0

// Register load immediate instructions
#define MVI(d,i)	DB(0x80+REGPOS0(d)); DB(i)
#define LD(d,l)		DB(0x88+REGPOS0(d)); DW(l)
#define STO(l,d)	DB(0x90+REGPOS0(d)); DW(l)

// R0 load/store indirect through a register pair
#define LDI(rp)		DB(0x98+((rp)&3))
#define STOI(rp)	DB(0x9c+((rp)&3))

// Branching operations
#define	JZ(l)	DB(0xe0); DW(l)
#define	JC(l)	DB(0xe1); DW(l)
#define	JNEG(l)	DB(0xe2); DW(l)
#define	JNZ(l)	DB(0xe4); DW(l)
#define	JNC(l)	DB(0xe5); DW(l)
#define	JPOS(l)	DB(0xe6); DW(l)
#define JMP(l)	DB(0xe7); DW(l) 
#define HALT	DB(0xff)
#define HLT	DB(0xff)

#endif
