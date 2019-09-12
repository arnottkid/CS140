CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/badhash \
      bin/acmhash \
      bin/djbhash \
      bin/cc_hacker

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Executables

bin/badhash: src/badhash.cpp
	g++ $(CFLAGS) -o bin/badhash src/badhash.cpp

bin/acmhash: src/acmhash.cpp
	g++ $(CFLAGS) -o bin/acmhash src/acmhash.cpp

bin/djbhash: src/djbhash.cpp
	g++ $(CFLAGS) -o bin/djbhash src/djbhash.cpp

bin/cc_hacker: src/cc_hacker.cpp
	g++ $(CFLAGS) -o bin/cc_hacker src/cc_hacker.cpp
