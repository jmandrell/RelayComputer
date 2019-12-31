	ORG 0

// clear all of the registers
start:
	MVI(r0,0)
	MOV(r1,r0)
	MOV(r2,r0)
	MOV(r3,r0)
	MOV(r4,r0)
	MOV(r5,r0)
	MOV(r6,r0)
	MOV(r7,r0)

loop:
	INC(r0)
	JNC loop
	INC(r1)
	JNC loop
	INC(r2)
	JNC loop
	INC(r3)
	JNC loop
	INC(r4)
	JNC loop
	INC(r5)
	JNC loop
	INC(r6)
	JNC loop
	INC(r7)
	JMP loop

	END
