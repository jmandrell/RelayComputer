	ORG 0
start:
	MVI(r0,1)
	MVI(r1,2)
	MVI(r2,3)
	MVI(R3,4)
	STO(0x1000,r0)
	STO(0x1001,r1)
	STO(0x1002,r2)
	STO(0x1003,r3)

	END
