CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/pointer_mess_1 \
      bin/pointer_mess_3 \
      bin/pointer_mess_2 \
      bin/in_class \
      bin/sortlines1 \
      bin/sortlines2 \
      bin/bacefook_server 

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Executables

bin/pointer_mess_1: src/pointer_mess_1.cpp
	g++ $(CFLAGS) -o bin/pointer_mess_1 src/pointer_mess_1.cpp

bin/pointer_mess_2: src/pointer_mess_2.cpp
	g++ $(CFLAGS) -o bin/pointer_mess_2 src/pointer_mess_2.cpp

bin/pointer_mess_3: src/pointer_mess_3.cpp
	g++ $(CFLAGS) -o bin/pointer_mess_3 src/pointer_mess_3.cpp

bin/in_class: src/in_class.cpp
	g++ $(CFLAGS) -o bin/in_class src/in_class.cpp

bin/sortlines1: src/sortlines1.cpp
	g++ $(CFLAGS) -o bin/sortlines1 src/sortlines1.cpp

bin/sortlines2: src/sortlines2.cpp
	g++ $(CFLAGS) -o bin/sortlines2 src/sortlines2.cpp

bin/bacefook_server: src/bacefook_server.cpp
	g++ $(CFLAGS) -o bin/bacefook_server src/bacefook_server.cpp

