SECTION TEXT
	COPY ZERO, OLDER
	COPY ONE, OLD
FRONT:	LOAD OLDER
	ADD OLD
	STORE NEW
	SUB LIMIT
	STORE FRONT + 2; erro usando simbolo da section text e consequentemente usando + com sibolo qu enao aceita +
	STORE FRONT;erro 
	store zero;erro modificando constante
	store one + 3; ultrapassando vetor
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
