	ORG 0
	MOV F(FCON,FCON_aaaaaaaa),F(FIO,FIO_LED)
	MOV F(FCON,FCON_ff00),FACC
	MOV F(FCON,FCON_ff),F(FCMP,FCMP_X)
	LDI step1
	MOV FIMMV,F(FCMP,FCMP_TARGET)
	MOV F(FCMP,FCMP_EQ),FPC
	MOV FONE,F(FCMP,FCMP_TARGET)
	MOV F(FCMP,FCMP_TARGET),F(FIO,FIO_DISP)
	MOV F(FCMP,FCMP_NE),FPC
step1:	MOV FONE,F(FIO,FIO_LED)
	JMP step1 
	END