// fibonacci calculation
	ORG 0
start:
// set up the starting values
	MVI(r0,0)
	MVI(r1,1)

loop:
	mov(r2,r1)
	add(r2)
	mov(r0,r1)
	mov(r1,r2)
	jmp loop

	END
