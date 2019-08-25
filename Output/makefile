# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = 100-rand coutcerr hwpf ints1 ints2 printchars ssn-reader weirdints

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


100-rand: 100-rand.o
	g++ $(CFLAGS) -o 100-rand 100-rand.o

coutcerr: coutcerr.o
	g++ $(CFLAGS) -o coutcerr coutcerr.o

hwpf: hwpf.o
	g++ $(CFLAGS) -o hwpf hwpf.o

ints1: ints1.o
	g++ $(CFLAGS) -o ints1 ints1.o

ints2: ints2.o
	g++ $(CFLAGS) -o ints2 ints2.o

printchars: printchars.o
	g++ $(CFLAGS) -o printchars printchars.o

ssn-reader: ssn-reader.o
	g++ $(CFLAGS) -o ssn-reader ssn-reader.o

weirdints: weirdints.o
	g++ $(CFLAGS) -o weirdints weirdints.o
