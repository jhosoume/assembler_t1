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
FINAL:	OUTPUT LIMIT
	STOP
SECTION DATA
ZERO:	CONST 0
ONE:	CONST 1
OLDER:	SPACE
OLD:	SPACE
    ADD ZERO ; Erro por instrução na seção de dados
NEW:	SPACE
LIMIT:	SPACE