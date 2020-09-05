CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/sudoku1 \
      bin/sudoku2 \
      bin/sudoku3 \
      bin/sudoku4 \
      bin/sudoku5 \
      bin/sudoku \
      bin/sudoku_draw \

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Object files

obj/sudoku1.o: src/sudoku1.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku1.o src/sudoku1.cpp

obj/sudoku2.o: src/sudoku2.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku2.o src/sudoku2.cpp

obj/sudoku3.o: src/sudoku3.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku3.o src/sudoku3.cpp

obj/sudoku4.o: src/sudoku4.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku4.o src/sudoku4.cpp

obj/sudoku5.o: src/sudoku5.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku5.o src/sudoku5.cpp

obj/sudoku.o: src/sudoku.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku.o src/sudoku.cpp

obj/sudoku_draw.o: src/sudoku_draw.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku_draw.o src/sudoku_draw.cpp

obj/sudoku_main.o: src/sudoku_main.cpp include/sudoku.hpp
	g++ $(CFLAGS) -c -o obj/sudoku_main.o src/sudoku_main.cpp



# -------------------------
# Executables

bin/sudoku1: obj/sudoku1.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/sudoku1 obj/sudoku1.o obj/sudoku_main.o

bin/sudoku2: obj/sudoku2.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/sudoku2 obj/sudoku2.o obj/sudoku_main.o

bin/sudoku3: obj/sudoku3.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/sudoku3 obj/sudoku3.o obj/sudoku_main.o

bin/sudoku4: obj/sudoku4.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/sudoku4 obj/sudoku4.o obj/sudoku_main.o

bin/sudoku5: obj/sudoku5.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/sudoku5 obj/sudoku5.o obj/sudoku_main.o

bin/sudoku: obj/sudoku.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/sudoku obj/sudoku.o obj/sudoku_main.o

bin/sudoku_draw: obj/sudoku_draw.o obj/sudoku_main.o
	g++ $(CFLAGS) -o bin/sudoku_draw obj/sudoku_draw.o obj/sudoku_main.o

