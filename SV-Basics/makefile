EXECUTABLES = string-basic mytail1 mytail2 reverse vec1 vec2 getline

CFLAGS ?= -Wall -Wextra

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

string-basic: string-basic.cpp
	g++ $(CFLAGS) -o string-basic string-basic.cpp

getline: getline.cpp
	g++ $(CFLAGS) -o getline getline.cpp

mytail1: mytail1.cpp
	g++ $(CFLAGS) -o mytail1 mytail1.cpp

mytail2: mytail2.cpp
	g++ $(CFLAGS) -o mytail2 mytail2.cpp

reverse: reverse.cpp
	g++ $(CFLAGS) -o reverse reverse.cpp

vec1: vec1.cpp
	g++ $(CFLAGS) -o vec1 vec1.cpp

vec2: vec2.cpp
	g++ $(CFLAGS) -o vec2 vec2.cpp
