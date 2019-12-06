CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/stack_rev \
      bin/stack_overload \
      bin/stack_overload_2 \
      bin/stack_overload_2_bad \
      bin/stack_overload_naoc \
      bin/stack_copy \
      bin/queue_tail \
      bin/queue_overload \
      bin/queue_copy \

DLIST = \
      bin/dlist_rev_1 \
      bin/dlist_rev_2 \
      bin/dlist_rev_3 \
      bin/dlist_rev_4 \
      bin/dlist_rev_5 \
      bin/dlist_rev_6 \

all: $(ALL)

dlist: $(DLIST)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Object files

obj/stack.o: src/stack.cpp include/stack.hpp
	g++ $(CFLAGS) -c -o obj/stack.o src/stack.cpp

obj/stack_bad_overload.o: src/stack_bad_overload.cpp include/stack.hpp
	g++ $(CFLAGS) -c -o obj/stack_bad_overload.o src/stack_bad_overload.cpp

obj/stack_no_ao_or_cc.o: src/stack_no_ao_or_cc.cpp include/stack_no_ao_or_cc.hpp
	g++ $(CFLAGS) -c -o obj/stack_no_ao_or_cc.o src/stack_no_ao_or_cc.cpp

obj/stack_rev.o: src/stack_rev.cpp include/stack.hpp
	g++ $(CFLAGS) -c -o obj/stack_rev.o src/stack_rev.cpp

obj/stack_overload.o: src/stack_overload.cpp include/stack.hpp
	g++ $(CFLAGS) -c -o obj/stack_overload.o src/stack_overload.cpp

obj/stack_overload_2.o: src/stack_overload_2.cpp include/stack.hpp
	g++ $(CFLAGS) -c -o obj/stack_overload_2.o src/stack_overload_2.cpp

obj/stack_overload_naoc.o: src/stack_overload_naoc.cpp include/stack_no_ao_or_cc.hpp
	g++ $(CFLAGS) -c -o obj/stack_overload_naoc.o src/stack_overload_naoc.cpp

obj/stack_copy.o: src/stack_copy.cpp include/stack.hpp
	g++ $(CFLAGS) -c -o obj/stack_copy.o src/stack_copy.cpp

obj/queue.o: src/queue.cpp include/queue.hpp
	g++ $(CFLAGS) -c -o obj/queue.o src/queue.cpp

obj/queue_tail.o: src/queue_tail.cpp include/queue.hpp
	g++ $(CFLAGS) -c -o obj/queue_tail.o src/queue_tail.cpp

obj/queue_overload.o: src/queue_overload.cpp include/queue.hpp
	g++ $(CFLAGS) -c -o obj/queue_overload.o src/queue_overload.cpp

obj/queue_copy.o: src/queue_copy.cpp include/queue.hpp
	g++ $(CFLAGS) -c -o obj/queue_copy.o src/queue_copy.cpp

obj/dlist.o: src/dlist.cpp include/dlist.hpp
	g++ $(CFLAGS) -c -o obj/dlist.o src/dlist.cpp

obj/dlist_rev_1.o: src/dlist_rev_1.cpp include/dlist.hpp
	g++ $(CFLAGS) -c -o obj/dlist_rev_1.o src/dlist_rev_1.cpp

obj/dlist_rev_2.o: src/dlist_rev_2.cpp include/dlist.hpp
	g++ $(CFLAGS) -c -o obj/dlist_rev_2.o src/dlist_rev_2.cpp

obj/dlist_rev_3.o: src/dlist_rev_3.cpp include/dlist.hpp
	g++ $(CFLAGS) -c -o obj/dlist_rev_3.o src/dlist_rev_3.cpp

obj/dlist_rev_4.o: src/dlist_rev_4.cpp include/dlist.hpp
	g++ $(CFLAGS) -c -o obj/dlist_rev_4.o src/dlist_rev_4.cpp

obj/dlist_rev_5.o: src/dlist_rev_5.cpp include/dlist.hpp
	g++ $(CFLAGS) -c -o obj/dlist_rev_5.o src/dlist_rev_5.cpp

obj/dlist_rev_6.o: src/dlist_rev_6.cpp include/dlist.hpp
	g++ $(CFLAGS) -c -o obj/dlist_rev_6.o src/dlist_rev_6.cpp


# -------------------------
# Executables

bin/stack_rev: obj/stack_rev.o obj/stack.o
	g++ $(CFLAGS) -o bin/stack_rev obj/stack_rev.o obj/stack.o

bin/stack_overload: obj/stack_overload.o obj/stack.o
	g++ $(CFLAGS) -o bin/stack_overload obj/stack_overload.o obj/stack.o

bin/stack_overload_2: obj/stack_overload_2.o obj/stack.o
	g++ $(CFLAGS) -o bin/stack_overload_2 obj/stack_overload_2.o obj/stack.o

bin/stack_overload_2_bad: obj/stack_overload_2.o obj/stack_bad_overload.o
	g++ $(CFLAGS) -o bin/stack_overload_2_bad obj/stack_overload_2.o obj/stack_bad_overload.o

bin/stack_overload_naoc: obj/stack_overload_naoc.o obj/stack_no_ao_or_cc.o
	g++ $(CFLAGS) -o bin/stack_overload_naoc obj/stack_overload_naoc.o obj/stack_no_ao_or_cc.o

bin/stack_copy: obj/stack_copy.o obj/stack.o
	g++ $(CFLAGS) -o bin/stack_copy obj/stack_copy.o obj/stack.o

bin/queue_tail: obj/queue_tail.o obj/queue.o
	g++ $(CFLAGS) -o bin/queue_tail obj/queue_tail.o obj/queue.o

bin/queue_overload: obj/queue_overload.o obj/queue.o
	g++ $(CFLAGS) -o bin/queue_overload obj/queue_overload.o obj/queue.o

bin/queue_copy: obj/queue_copy.o obj/queue.o
	g++ $(CFLAGS) -o bin/queue_copy obj/queue_copy.o obj/queue.o

bin/dlist_rev_1: obj/dlist_rev_1.o obj/dlist.o
	g++ $(CFLAGS) -o bin/dlist_rev_1 obj/dlist_rev_1.o obj/dlist.o

bin/dlist_rev_2: obj/dlist_rev_2.o obj/dlist.o
	g++ $(CFLAGS) -o bin/dlist_rev_2 obj/dlist_rev_2.o obj/dlist.o

bin/dlist_rev_3: obj/dlist_rev_3.o obj/dlist.o
	g++ $(CFLAGS) -o bin/dlist_rev_3 obj/dlist_rev_3.o obj/dlist.o

bin/dlist_rev_4: obj/dlist_rev_4.o obj/dlist.o
	g++ $(CFLAGS) -o bin/dlist_rev_4 obj/dlist_rev_4.o obj/dlist.o

bin/dlist_rev_5: obj/dlist_rev_5.o obj/dlist.o
	g++ $(CFLAGS) -o bin/dlist_rev_5 obj/dlist_rev_5.o obj/dlist.o

bin/dlist_rev_6: obj/dlist_rev_6.o obj/dlist.o
	g++ $(CFLAGS) -o bin/dlist_rev_6 obj/dlist_rev_6.o obj/dlist.o

