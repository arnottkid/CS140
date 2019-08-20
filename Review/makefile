EXECUTABLES = forget-clear forget-nothing forget-read hw1 hw2 printemall readone readten-bad readten-good readtwo rt2 rt3 rt4 ncnl badeof good-eof-1 good-eof-2

CFLAGS ?= 

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

good-eof-2: good-eof-2.cpp
	g++ $(CFLAGS) -o good-eof-2 good-eof-2.cpp

good-eof-1: good-eof-1.cpp
	g++ $(CFLAGS) -o good-eof-1 good-eof-1.cpp

badeof: badeof.cpp
	g++ $(CFLAGS) -o badeof badeof.cpp

ncnl: ncnl.cpp
	g++ $(CFLAGS) -o ncnl ncnl.cpp

forget-clear: forget-clear.cpp
	g++ $(CFLAGS) -o forget-clear forget-clear.cpp

forget-nothing: forget-nothing.cpp
	g++ $(CFLAGS) -o forget-nothing forget-nothing.cpp

forget-read: forget-read.cpp
	g++ $(CFLAGS) -o forget-read forget-read.cpp

hw1: hw1.cpp
	g++ $(CFLAGS) -o hw1 hw1.cpp

hw2: hw2.cpp
	g++ $(CFLAGS) -o hw2 hw2.cpp

printemall: printemall.cpp
	g++ $(CFLAGS) -o printemall printemall.cpp

readone: readone.cpp
	g++ $(CFLAGS) -o readone readone.cpp

readten-bad: readten-bad.cpp
	g++ $(CFLAGS) -o readten-bad readten-bad.cpp

readten-good: readten-good.cpp
	g++ $(CFLAGS) -o readten-good readten-good.cpp

readtwo: readtwo.cpp
	g++ $(CFLAGS) -o readtwo readtwo.cpp

rt2: rt2.cpp
	g++ $(CFLAGS) -o rt2 rt2.cpp

rt3: rt3.cpp
	g++ $(CFLAGS) -o rt3 rt3.cpp

rt4: rt4.cpp
	g++ $(CFLAGS) -o rt4 rt4.cpp
