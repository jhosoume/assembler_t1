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
	OUTPUT NEW + 1	
	COPY OLD, OLDER
	COPY NEW, OLD
	JMP FRONT
	JMPP zero + 2 ; Erro por desvio condicional para seção de dados
FINAL:	OUTPUT LIMIT
	STOP

SECTION DATA
DATA_J:   CONST 40
ZERO:	CONST 0
ONE:	CONST 1
OLDER:	SPACE
OLD:	SPACE
NEW:	SPACE 2
LIMIT:	SPACE
