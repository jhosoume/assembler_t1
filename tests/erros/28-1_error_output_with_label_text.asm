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
	OUTPUT FRONT ; erro output com label da text
	OUTPUT FRONT + 2 ; erro output com label da text
	COPY OLD, OLDER
	COPY NEW, OLD
	JMP FRONT
FINAL:	OUTPUT LIMIT
	STOP 

SECTION DATA
ZERO:	CONST 0
ONE:	CONST 1
OLDER:	SPACE
OLD:	SPACE
NEW:	SPACE
LIMIT:	SPACE