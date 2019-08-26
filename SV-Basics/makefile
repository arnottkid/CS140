# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = mytail1 mytail2 mytail3 reverse vec1 vec2 getline string-basic

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


string-basic: string-basic.o
	g++ $(CFLAGS) -o string-basic string-basic.o

getline: getline.o
	g++ $(CFLAGS) -o getline getline.o

mytail1: mytail1.o
	g++ $(CFLAGS) -o mytail1 mytail1.o

mytail2: mytail2.o
	g++ $(CFLAGS) -o mytail2 mytail2.o

mytail3: mytail3.o
	g++ $(CFLAGS) -o mytail3 mytail3.o

reverse: reverse.o
	g++ $(CFLAGS) -o reverse reverse.o

vec1: vec1.o
	g++ $(CFLAGS) -o vec1 vec1.o

vec2: vec2.o
	g++ $(CFLAGS) -o vec2 vec2.o
