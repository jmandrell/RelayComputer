#define TOS 0xFFF


	ORG 0
        MOVI TOS
        MOV FIMMV,F(FSTK,FSTK_SP)
top:	
        MOV F(FCON,FCON_10),F(FMEM,FMEM_VALUE0POST)
        MOV F(FMEM,FMEM_MP0),F(FIO,FIO_LED)
        MOV F(FMEM,FMEM_VALUE1),FACC
        CALL delay
        JMP top
delay:	MOVI 25000000
        MOV FIMMV,F(FIO,FIO_DELAY)
        MOV F(FIO,FIO_DELAY),FZERO
        RET
	END