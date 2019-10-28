# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = rec1 rec2 rec3 fact1 fact2 mult1 mult2 fib1 fib2 tower_solution \
              tower_play
CC = g++

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .c .o
.cpp.o:
	$(CC) -c -g $*.cpp


rec3: rec3.o
	$(CC) -g -o rec3 rec3.o

rec2: rec2.o
	$(CC) -g -o rec2 rec2.o

rec1: rec1.o
	$(CC) -g -o rec1 rec1.o

fact1: fact1.o
	$(CC) -g -o fact1 fact1.o

fact2: fact2.o
	$(CC) -g -o fact2 fact2.o

mult1: mult1.o
	$(CC) -g -o mult1 mult1.o

mult2: mult2.o
	$(CC) -g -o mult2 mult2.o

fib1: fib1.o
	$(CC) -g -o fib1 fib1.o

fib2: fib2.o
	$(CC) -g -o fib2 fib2.o

tower_solution: tower_solution.o towers.o
	$(CC) -g -o tower_solution tower_solution.o towers.o

tower_play: tower_play.o towers.o
	$(CC) -g -o tower_play tower_play.o towers.o $(LIBS)

tower_solution.o: towers.h
tower_play.o: towers.h
towers.o: towers.h
