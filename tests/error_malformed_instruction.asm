SECTION TEXT
	COPY ZERO, OLDER
	COPY ONE, OLD
	INPUT LIMIT
	OUTPUT OLD
FRONT:	LOAD OLDER
	ADD OLD, ONE ; Erro por uso indevido da instrução (ADD aceita apenas um operando)
	STORE NEW
	SUB LIMIT
	JMPP FINAL
	OUTPUT NEW
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