CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/bstree_tester \

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Object files

obj/bstree.o: src/bstree.cpp include/bstree.hpp
	g++ $(CFLAGS) -c -o obj/bstree.o src/bstree.cpp

obj/bstree_tester.o: src/bstree_tester.cpp include/bstree.hpp
	g++ $(CFLAGS) -c -o obj/bstree_tester.o src/bstree_tester.cpp

# -------------------------
# Executables

bin/bstree_tester: obj/bstree_tester.o obj/bstree.o
	g++ $(CFLAGS) -o bin/bstree_tester obj/bstree_tester.o obj/bstree.o
