a.out: main.o prog1.o slp.o util.o
	cc -g main.o prog1.o slp.o util.o

main.o: main.c prog1.h slp.h util.h
	cc -g -c main.c

prog1.o: prog1.c prog1.h slp.h util.h
	cc -g -c prog1.c

slp.o: slp.c prog1.h slp.h util.h
	cc -g -c slp.c

util.o: util.c prog1.h slp.h util.h
	cc -g -c util.c

clean:
	rm -f a.out util.o prog1.o slp.o main.o
