# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = linear1 linear2 log nlogn nsquared
CC = g++
CFLAGS = 

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .cpp .o
.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp


linear1: linear1.o
	$(CC) $(CFLAGS) -o linear1 linear1.o

linear2: linear2.o
	$(CC) $(CFLAGS) -o linear2 linear2.o

log: log.o
	$(CC) $(CFLAGS) -o log log.o

nlogn: nlogn.o
	$(CC) $(CFLAGS) -o nlogn nlogn.o

nsquared: nsquared.o
	$(CC) $(CFLAGS) -o nsquared nsquared.o
