SECTION TEXT



	CoPy 		   ZERO,  		 OLDER
	COPY ONE, OLD
	INPUT			   LIMIT
	OUTPUT OLD
FRONT:	
	     	LOAD OLDER
	AdD    OLD
	STORE NEW ; comentario
	;SUB LIMIT
	JMPP FINAL
	OutPUT OLDER + 3 ; passando do tamanho do vetor
	COPY OLD, OLDER
	COPY NEW, OLD
	JMP FRONT
FINAL:	OUTPUT LIMIT
	STOP

SECTION DATA
ZERO:	CONST 0
ONE:	CONST 1
OLDER:	SPACE 3
OLD:	SPACE
NEW:	SPACE
LIMIT:	SPACE