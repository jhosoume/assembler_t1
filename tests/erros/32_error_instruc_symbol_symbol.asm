SECTION TEXT
	COPY ZERO, OLDER
	COPY ONE, OLD
FRONT:	LOAD OLDER
	ADD OLD
	STORE NEW
	SUB LIMIT
	JMPP FINAL + FINAL ;erro
	SUB LIMIT + LIMIT ;erro
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