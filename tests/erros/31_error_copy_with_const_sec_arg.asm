SECTION TEXT
	COPY ZERO, OLDER
	COPY ONE, OLD
FRONT:	LOAD OLDER
	ADD OLD
	STORE NEW
	SUB LIMIT
	JMPP FINAL
	COPY OLD, ZERO ; ERRO alterando const
    copy old + 1, zero ; erro alterando const
    copy old + 1, zero + 1; ; erro alterando const
    copy old, zero + 1 ; erro alterando const e erro usando + NUM_DEc para label que nao aceita
    COPY OLD, zero + 1;
	COPY NEW, OLD
	JMP FRONT
FINAL:	OUTPUT LIMIT
	STOP 
SECTION DATA
ZERO:	CONST 0
ONE:	CONST 1
OLDER:	SPACE
OLD:	SPACE 3
NEW:	SPACE
LIMIT:	SPACE
