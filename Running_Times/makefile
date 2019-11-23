CFLAGS ?= -std=c++98 -Wall -Wextra -Iinclude

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/dth_vector bin/ht_vector bin/range_vector \
      bin/dth_map bin/ht_map bin/range_map \
      bin/dth_bad_vec bin/ht_bad_vec bin/range_bad_vec \
      bin/dth_deque bin/ht_deque bin/range_deque  \
      bin/dth_list bin/ht_list bin/range_list  \
      bin/dth_multiset bin/ht_multiset bin/range_multiset  \
      bin/dth_hash bin/ht_hash bin/range_hash  \
      bin/show_line

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/* a.out

# -------------------------
# Object files.  First the main() programs that use the histogram class

obj/data_to_histogram.o: src/data_to_histogram.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/data_to_histogram.o src/data_to_histogram.cpp

obj/histogram_tester.o: src/histogram_tester.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/histogram_tester.o src/histogram_tester.cpp

obj/range_tester.o: src/range_tester.cpp include/histogram.hpp include/MOA.hpp
	g++ $(CFLAGS) -c -o obj/range_tester.o src/range_tester.cpp

# -------------------------
# Object files.  Next, the four implementations of the histogram class.

obj/histogram_vector.o: src/histogram_vector.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/histogram_vector.o src/histogram_vector.cpp

obj/histogram_map.o: src/histogram_map.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/histogram_map.o src/histogram_map.cpp

obj/histogram_bad_vec.o: src/histogram_bad_vec.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/histogram_bad_vec.o src/histogram_bad_vec.cpp

obj/histogram_deque.o: src/histogram_deque.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/histogram_deque.o src/histogram_deque.cpp

obj/histogram_list.o: src/histogram_list.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/histogram_list.o src/histogram_list.cpp

obj/histogram_multiset.o: src/histogram_multiset.cpp include/histogram.hpp
	g++ $(CFLAGS) -c -o obj/histogram_multiset.o src/histogram_multiset.cpp

obj/histogram_hash.o: src/histogram_hash.cpp include/histogram.hpp include/MOA.hpp
	g++ $(CFLAGS) -c -o obj/histogram_hash.o src/histogram_hash.cpp

# -------------------------
# Executables.  12 of them -- 3 mains, 4 implementations.

bin/dth_vector: obj/data_to_histogram.o obj/histogram_vector.o
	g++ $(CFLAGS) -o bin/dth_vector obj/data_to_histogram.o obj/histogram_vector.o

bin/ht_vector: obj/histogram_tester.o obj/histogram_vector.o
	g++ $(CFLAGS) -o bin/ht_vector obj/histogram_tester.o obj/histogram_vector.o

bin/range_vector: obj/range_tester.o obj/histogram_vector.o
	g++ $(CFLAGS) -o bin/range_vector obj/range_tester.o obj/histogram_vector.o

bin/dth_map: obj/data_to_histogram.o obj/histogram_map.o
	g++ $(CFLAGS) -o bin/dth_map obj/data_to_histogram.o obj/histogram_map.o

bin/ht_map: obj/histogram_tester.o obj/histogram_map.o
	g++ $(CFLAGS) -o bin/ht_map obj/histogram_tester.o obj/histogram_map.o

bin/range_map: obj/range_tester.o obj/histogram_map.o
	g++ $(CFLAGS) -o bin/range_map obj/range_tester.o obj/histogram_map.o

bin/dth_bad_vec: obj/data_to_histogram.o obj/histogram_bad_vec.o
	g++ $(CFLAGS) -o bin/dth_bad_vec obj/data_to_histogram.o obj/histogram_bad_vec.o

bin/ht_bad_vec: obj/histogram_tester.o obj/histogram_bad_vec.o
	g++ $(CFLAGS) -o bin/ht_bad_vec obj/histogram_tester.o obj/histogram_bad_vec.o

bin/range_bad_vec: obj/range_tester.o obj/histogram_bad_vec.o
	g++ $(CFLAGS) -o bin/range_bad_vec obj/range_tester.o obj/histogram_bad_vec.o

bin/dth_deque: obj/data_to_histogram.o obj/histogram_deque.o
	g++ $(CFLAGS) -o bin/dth_deque obj/data_to_histogram.o obj/histogram_deque.o

bin/ht_deque: obj/histogram_tester.o obj/histogram_deque.o
	g++ $(CFLAGS) -o bin/ht_deque obj/histogram_tester.o obj/histogram_deque.o

bin/range_deque: obj/range_tester.o obj/histogram_deque.o
	g++ $(CFLAGS) -o bin/range_deque obj/range_tester.o obj/histogram_deque.o

bin/dth_list: obj/data_to_histogram.o obj/histogram_list.o
	g++ $(CFLAGS) -o bin/dth_list obj/data_to_histogram.o obj/histogram_list.o

bin/ht_list: obj/histogram_tester.o obj/histogram_list.o
	g++ $(CFLAGS) -o bin/ht_list obj/histogram_tester.o obj/histogram_list.o

bin/range_list: obj/range_tester.o obj/histogram_list.o
	g++ $(CFLAGS) -o bin/range_list obj/range_tester.o obj/histogram_list.o

bin/dth_multiset: obj/data_to_histogram.o obj/histogram_multiset.o
	g++ $(CFLAGS) -o bin/dth_multiset obj/data_to_histogram.o obj/histogram_multiset.o

bin/ht_multiset: obj/histogram_tester.o obj/histogram_multiset.o
	g++ $(CFLAGS) -o bin/ht_multiset obj/histogram_tester.o obj/histogram_multiset.o

bin/range_multiset: obj/range_tester.o obj/histogram_multiset.o
	g++ $(CFLAGS) -o bin/range_multiset obj/range_tester.o obj/histogram_multiset.o

bin/dth_hash: obj/data_to_histogram.o obj/histogram_hash.o
	g++ $(CFLAGS) -o bin/dth_hash obj/data_to_histogram.o obj/histogram_hash.o

bin/ht_hash: obj/histogram_tester.o obj/histogram_hash.o
	g++ $(CFLAGS) -o bin/ht_hash obj/histogram_tester.o obj/histogram_hash.o

bin/range_hash: obj/range_tester.o obj/histogram_hash.o
	g++ $(CFLAGS) -o bin/range_hash obj/range_tester.o obj/histogram_hash.o

bin/show_line: src/show_line.cpp
	g++ $(CFLAGS) -o bin/show_line src/show_line.cpp

