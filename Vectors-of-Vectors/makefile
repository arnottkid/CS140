# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = fred pascal vcopy vdm 

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


fred: fred.o
	g++ $(CFLAGS) -o fred fred.o

genlines: genlines.o
	g++ $(CFLAGS) -o genlines genlines.o

pascal: pascal.o
	g++ $(CFLAGS) -o pascal pascal.o

vcopy: vcopy.o
	g++ $(CFLAGS) -o vcopy vcopy.o

vdm: vdm.o
	g++ $(CFLAGS) -o vdm vdm.o

