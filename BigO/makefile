EXECUTABLES = \
bin/linear1 \
bin/linear2 \
bin/log \
bin/nlogn \
bin/nsquared \
bin/all_i_j_pairs \
bin/two_to_the_n

CFLAGS ?= -Wall -Wextra

all: $(EXECUTABLES)

clean:
	rm -f bin/* obj/* a.out

bin/linear1: src/linear1.cpp
	g++ $(CFLAGS) -o bin/linear1 src/linear1.cpp

bin/linear2: src/linear2.cpp
	g++ $(CFLAGS) -o bin/linear2 src/linear2.cpp

bin/log: src/log.cpp
	g++ $(CFLAGS) -o bin/log src/log.cpp

bin/nlogn: src/nlogn.cpp
	g++ $(CFLAGS) -o bin/nlogn src/nlogn.cpp

bin/nsquared: src/nsquared.cpp
	g++ $(CFLAGS) -o bin/nsquared src/nsquared.cpp

bin/all_i_j_pairs: src/all_i_j_pairs.cpp
	g++ $(CFLAGS) -o bin/all_i_j_pairs src/all_i_j_pairs.cpp

bin/two_to_the_n: src/two_to_the_n.cpp
	g++ $(CFLAGS) -o bin/two_to_the_n src/two_to_the_n.cpp

