EXECUTABLES =  \
     bin/rec1 \
     bin/rec2 \
     bin/rec3 \
     bin/fact1 \
     bin/fact2 \
     bin/mult1 \
     bin/mult2 \
     bin/fib1 \
     bin/fib2 \
     bin/towers_play \
     bin/towers_solution \

CFLAGS = -Wall -Wextra -Iinclude

all: $(EXECUTABLES)

clean:
	rm -f bin/* obj/* a.out

# ------------- Executable Files

bin/fact1: src/fact1.cpp
	g++ $(CFLAGS) -o bin/fact1 src/fact1.cpp

bin/fact2: src/fact2.cpp
	g++ $(CFLAGS) -o bin/fact2 src/fact2.cpp

bin/fib1: src/fib1.cpp
	g++ $(CFLAGS) -o bin/fib1 src/fib1.cpp

bin/fib2: src/fib2.cpp
	g++ $(CFLAGS) -o bin/fib2 src/fib2.cpp

bin/mult1: src/mult1.cpp
	g++ $(CFLAGS) -o bin/mult1 src/mult1.cpp

bin/mult2: src/mult2.cpp
	g++ $(CFLAGS) -o bin/mult2 src/mult2.cpp

bin/rec1: src/rec1.cpp
	g++ $(CFLAGS) -o bin/rec1 src/rec1.cpp

bin/rec2: src/rec2.cpp
	g++ $(CFLAGS) -o bin/rec2 src/rec2.cpp

bin/rec3: src/rec3.cpp
	g++ $(CFLAGS) -o bin/rec3 src/rec3.cpp

bin/towers_play: obj/towers_play.o obj/towers.o
	g++ $(CFLAGS) -o bin/towers_play obj/towers_play.o obj/towers.o

bin/towers_solution: obj/towers_solution.o obj/towers.o
	g++ $(CFLAGS) -o bin/towers_solution obj/towers_solution.o obj/towers.o

# ------------- Object Files

obj/towers.o: src/towers.cpp include/towers.hpp
	g++ $(CFLAGS) -c -o obj/towers.o src/towers.cpp

obj/towers_play.o: src/towers_play.cpp include/towers.hpp
	g++ $(CFLAGS) -c -o obj/towers_play.o src/towers_play.cpp

obj/towers_solution.o: src/towers_solution.cpp include/towers.hpp
	g++ $(CFLAGS) -c -o obj/towers_solution.o src/towers_solution.cpp
