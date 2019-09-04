# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = gendouble string-find string-sub ex1 ex2 ex3 argv-mess
CFLAGS ?= -Wall -Wextra

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


gendouble: gendouble.cpp
	g++ $(CFLAGS) -o gendouble gendouble.cpp

string-find: string-find.cpp
	g++ $(CFLAGS) -o string-find string-find.cpp

string-sub: string-sub.cpp
	g++ $(CFLAGS) -o string-sub string-sub.cpp

ex1: ex1.cpp
	g++ $(CFLAGS) -o ex1 ex1.cpp

ex2: ex2.cpp
	g++ $(CFLAGS) -o ex2 ex2.cpp

ex3: ex3.cpp
	g++ $(CFLAGS) -o ex3 ex3.cpp

argv-mess: argv-mess.cpp
	g++ $(CFLAGS) -o argv-mess argv-mess.cpp

