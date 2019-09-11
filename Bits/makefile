# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = and complement exor leftshift or printbits rightshift bit_practice

CC=gcc
CFLAGS=-g
all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c


and: and.o
	$(CC) $(CFLAGS) -o and and.o

complement: complement.o
	$(CC) $(CFLAGS) -o complement complement.o

exor: exor.o
	$(CC) $(CFLAGS) -o exor exor.o

leftshift: leftshift.o
	$(CC) $(CFLAGS) -o leftshift leftshift.o

or: or.o
	$(CC) $(CFLAGS) -o or or.o

printbits: printbits.o
	$(CC) $(CFLAGS) -o printbits printbits.o

rightshift: rightshift.o
	$(CC) $(CFLAGS) -o rightshift rightshift.o
