HEADERS = errormsg.h util.h

parsetest: parsetest.o y.tab.o lex.yy.o errormsg.o util.o
	cc -g -o parsetest parsetest.o y.tab.o lex.yy.o errormsg.o util.o

parsetest.o: parsetest.c $(HEADERS)
	cc -g -c parsetest.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: tiger.grm
	yacc -dv tiger.grm

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c $(HEADERS)
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h $(HEADERS)
	cc -g -c lex.yy.c

util.o: util.c $(HEADERS)
	cc -g -c util.c

clean:
	rm -f *.o *.out y.tab.c y.tab.h
