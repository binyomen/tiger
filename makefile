lextest: driver.o lex.yy.o errormsg.o util.o
	cc -g -o lextest driver.o lex.yy.o errormsg.o util.o

driver.o: driver.c errormsg.h tokens.h util.h
	cc -g -c driver.c

errormsg.o: errormsg.c errormsg.h tokens.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c errormsg.h tokens.h util.h
	cc -g -c lex.yy.c

lex.yy.c: tiger.lex
	lex tiger.lex

util.o: util.c errormsg.h tokens.h util.h
	cc -g -c util.c

clean:
	rm -f *.o *.out lex.yy.c lextest
