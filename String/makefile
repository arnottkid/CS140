# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = argv-mess gendouble genstring string-find string-sub

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


argv-mess: argv-mess.cpp
	g++ $(CFLAGS) -o argv-mess argv-mess.cpp

gendouble: gendouble.cpp
	g++ $(CFLAGS) -o gendouble gendouble.cpp

genstring-bad: genstring-bad.cpp
	g++ $(CFLAGS) -o genstring-bad genstring-bad.cpp

genstring: genstring.cpp
	g++ $(CFLAGS) -o genstring genstring.cpp

string-find: string-find.cpp
	g++ $(CFLAGS) -o string-find string-find.cpp

string-sub: string-sub.cpp
	g++ $(CFLAGS) -o string-sub string-sub.cpp
