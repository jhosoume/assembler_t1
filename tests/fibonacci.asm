SECTION TEXT
;Comentario
M1: MACRO &a, &b
COPY &a, &b
INPUT LIMIT ;comentario
OUTPUT &b
END
M2: MACRO
OUTPUT NEW
COPY OLD, OLDER
COPY NEW, OLD
END
COPY	ZERO, OLDER
FRONT:	LOAD OLDER ;comentario
M1 ONE, OLDER
ADD OLD
STORE NEW
SUB LIMIT
JMPP FINAL
DIV ZERo
M2
JMP FRONT
FINAL:	OUTPUT LIMIT ;comentario
STOP

SECTION DATA
ZERO: CONST 0
ONE: CONST 1
OLDER: SPACE
OLD: SPACE
NEW: SPACE
LIMIT: SPACE
