SECTION TEXT
	COPY ZERO, OLDER
	COPY ONE, OLD
	INPUT LIMIT
	OUTPUT OLD
FRONT:	LOAD OLDER
	ADD FRONT
	STORE NEW
	SUB LIMIT
	JMPP FINAL
	OUTPUT NEW
	COPY OLD, OLDER
	COPY NEW, OLD
	JMP ZERO
FINAL:	OUTPUT LIMIT
	STOP


SECTION DATA
ZERO:	CONST 0
ONE:	CONST 1
OLDER:	SPACE
OLD:	SPACE
NEW:	SPACE
LIMIT:	SPACE