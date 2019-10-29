# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = sudoku sudoku1 sudoku2 sudoku3 sudoku4 sudoku5

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .c .o
.c.o:
	g++ $(CFLAGS) -c $*.c


sudoku.o: sudoku.h
sudoku_main.o: sudoku.h
sudoku1.o: sudoku.h
sudoku2.o: sudoku.h
sudoku3.o: sudoku.h
sudoku4.o: sudoku.h
sudoku5.o: sudoku.h

sudoku: sudoku_main.o sudoku.o 
	g++ $(CFLAGS) -o sudoku sudoku_main.o sudoku.o 

sudoku1: sudoku_main.o sudoku1.o 
	g++ $(CFLAGS) -o sudoku1 sudoku_main.o sudoku1.o 

sudoku2: sudoku_main.o sudoku2.o 
	g++ $(CFLAGS) -o sudoku2 sudoku_main.o sudoku2.o 

sudoku3: sudoku_main.o sudoku3.o 
	g++ $(CFLAGS) -o sudoku3 sudoku_main.o sudoku3.o 

sudoku4: sudoku_main.o sudoku4.o 
	g++ $(CFLAGS) -o sudoku4 sudoku_main.o sudoku4.o 

sudoku5: sudoku_main.o sudoku5.o 
	g++ $(CFLAGS) -o sudoku5 sudoku_main.o sudoku5.o 

