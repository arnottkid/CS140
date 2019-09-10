CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/ttt_tester \
      bin/ttt_player \
      bin/ttt_random

all: $(ALL)

# -------------------------
# "make develop" makes two programs that I used when I was writing tic_tac_toe.cpp

DEVELOP = bin/ttt_tester_1 \
          bin/ttt_tester_2

develop: $(DEVELOP)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Object files

obj/tic_tac_toe_1.o: src/tic_tac_toe_1.cpp include/tic_tac_toe.hpp
	g++ $(CFLAGS) -c -o obj/tic_tac_toe_1.o src/tic_tac_toe_1.cpp

obj/tic_tac_toe_2.o: src/tic_tac_toe_2.cpp include/tic_tac_toe.hpp
	g++ $(CFLAGS) -c -o obj/tic_tac_toe_2.o src/tic_tac_toe_2.cpp

obj/tic_tac_toe.o: src/tic_tac_toe.cpp include/tic_tac_toe.hpp
	g++ $(CFLAGS) -c -o obj/tic_tac_toe.o src/tic_tac_toe.cpp

obj/ttt_tester.o: src/ttt_tester.cpp include/tic_tac_toe.hpp
	g++ $(CFLAGS) -c -o obj/ttt_tester.o src/ttt_tester.cpp

obj/ttt_player.o: src/ttt_player.cpp include/tic_tac_toe.hpp
	g++ $(CFLAGS) -c -o obj/ttt_player.o src/ttt_player.cpp

obj/ttt_random.o: src/ttt_random.cpp include/tic_tac_toe.hpp
	g++ $(CFLAGS) -c -o obj/ttt_random.o src/ttt_random.cpp

# -------------------------
# Executables

bin/ttt_tester_1: obj/ttt_tester.o obj/tic_tac_toe_1.o
	g++ $(CFLAGS) -o bin/ttt_tester_1 obj/ttt_tester.o obj/tic_tac_toe_1.o

bin/ttt_tester_2: obj/ttt_tester.o obj/tic_tac_toe_2.o
	g++ $(CFLAGS) -o bin/ttt_tester_2 obj/ttt_tester.o obj/tic_tac_toe_2.o

bin/ttt_tester: obj/ttt_tester.o obj/tic_tac_toe.o
	g++ $(CFLAGS) -o bin/ttt_tester obj/ttt_tester.o obj/tic_tac_toe.o

bin/ttt_player: obj/ttt_player.o obj/tic_tac_toe.o
	g++ $(CFLAGS) -o bin/ttt_player obj/ttt_player.o obj/tic_tac_toe.o

bin/ttt_random: obj/ttt_random.o obj/tic_tac_toe.o
	g++ $(CFLAGS) -o bin/ttt_random obj/ttt_random.o obj/tic_tac_toe.o

