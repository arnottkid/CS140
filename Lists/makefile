EXECUTABLES = bin/reverse_1 \
              bin/reverse_2 \
              bin/reverse_3 \
              bin/reverse_4 \
              bin/reverse_5 \
              bin/mytail_list \
              bin/mytail_100_list \
              bin/mytail_100_vector \
              bin/mytail_100_deque \
              bin/DiamondHunt1 \
              bin/DiamondHunt2 \
              bin/make_bad_diamond \

CFLAGS ?= -Wall -Wextra

all: $(EXECUTABLES)

clean:
	rm -f bin/* obj/* a.out

bin/reverse_1: src/reverse_1.cpp
	g++ $(CFLAGS) -o bin/reverse_1 src/reverse_1.cpp

bin/reverse_2: src/reverse_2.cpp
	g++ $(CFLAGS) -o bin/reverse_2 src/reverse_2.cpp

bin/reverse_3: src/reverse_3.cpp
	g++ $(CFLAGS) -o bin/reverse_3 src/reverse_3.cpp

bin/reverse_4: src/reverse_4.cpp
	g++ $(CFLAGS) -o bin/reverse_4 src/reverse_4.cpp

bin/reverse_5: src/reverse_5.cpp
	g++ $(CFLAGS) -o bin/reverse_5 src/reverse_5.cpp

bin/DiamondHunt1: src/DiamondHunt1.cpp
	g++ $(CFLAGS) -o bin/DiamondHunt1 src/DiamondHunt1.cpp

bin/DiamondHunt2: src/DiamondHunt2.cpp
	g++ $(CFLAGS) -o bin/DiamondHunt2 src/DiamondHunt2.cpp

bin/make_bad_diamond: src/make_bad_diamond.cpp
	g++ $(CFLAGS) -o bin/make_bad_diamond src/make_bad_diamond.cpp

bin/mytail_list: src/mytail_list.cpp
	g++ $(CFLAGS) -o bin/mytail_list src/mytail_list.cpp

bin/mytail_100_deque: src/mytail_100_deque.cpp
	g++ $(CFLAGS) -o bin/mytail_100_deque src/mytail_100_deque.cpp

bin/mytail_100_list: src/mytail_100_list.cpp
	g++ $(CFLAGS) -o bin/mytail_100_list src/mytail_100_list.cpp

bin/mytail_100_vector: src/mytail_100_vector.cpp
	g++ $(CFLAGS) -o bin/mytail_100_vector src/mytail_100_vector.cpp
