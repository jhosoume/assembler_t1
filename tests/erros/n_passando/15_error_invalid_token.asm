	SECTION TEXT
	COPY 1ZERO, OLDER ; token problematico
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
1ZERO:	CONST 0 ; Erro por label inválido (não pode iniciar com número) e causa ero de nao definicao 
ONE:	CONST 1
OLDER:	SPACE
OLD:	SPACE
NEW:	SPACE
LIMIT:	SPACE