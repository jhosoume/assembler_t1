SECTION TEXT
	COPY ZERO, OLDER
	COPY ONE, OLD
	INPUT LIMIT
	OUTPUT OLD
FRONT:	LOAD OLDER
	ADD OLD
	STORE NEW
	SUB LIMIT
	JMPP FINAL
	OUTPUT NEW
	COPY OLD, OLDER
	COPY NEW, OLD
	JMP FRONT
FINAL: FINAL2:	OUTPUT LIMIT ; erro 2 labels na mesma linha
	STOP
SECTION DATA
ZERO: ZERO2:	CONST 0 ; erro 2 labels na mesma linha
ONE:	CONST 1
OLDER:	SPACE
OLD:	SPACE
NEW:	SPACE
LIMIT:	SPACE