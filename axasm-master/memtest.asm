	ORG 0
	ZERO	FMEM_MP0
	MOV	FCON_f0,FLOOP_I
	MOV	FCON_ff,FLOOP_IEND
	MOV	FCON_1,FLOOP_IINC ; should not need -- reset logic is bad
	MOV	FCON_1,FMEM_SIZE1 ; ditto
	MOVI	X
	MOV	FIMMV,FLOOP_IADD
X:	MOV	FLOOP_I,FMEM_VALUE0POST
	MOV	FLOOP_IADD,FPC_VALUE
	ZERO	FMEM_MP0
	ZERO	FLOOP_I
	MOV	FCON_f,FLOOP_IEND
	MOVI	Y
	MOV	FIMMV,FLOOP_IADD
Y:	MOV	FMEM_VALUE0POST,FIO_DISP
	MOV	FCON_ff0000,FIO_DELAY
	MOV	FIO_DELAY,FZERO
	MOV	FLOOP_IADD,FPC_VALUE
	JMP	0
	END
	
