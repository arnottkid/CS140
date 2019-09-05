ALL = roster_01 roster_02 roster_03A_good roster_04 roster_05_bad_1 roster_05_bad_2 \
      roster_05_good roster_06

CFLAGS ?= -Wall -Wextra
all: $(ALL)

clean:
	rm -f *.o $(ALL)

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CFLAGS) -c $*.cpp 

roster_01.o: roster_01.hpp
roster_01_main.o: roster_01.hpp
roster_01: roster_01.o roster_01_main.o
	g++ $(CFLAGS) -o roster_01 roster_01.o roster_01_main.o

roster_02.o: roster_02.hpp
roster_02_main.o: roster_02.hpp
roster_02: roster_02.o roster_02_main.o
	g++ $(CFLAGS) -o roster_02 roster_02.o roster_02_main.o

roster_03.o: roster_03.hpp
roster_03A_good_main.o: roster_03.hpp
roster_03A_good: roster_03.o roster_03A_good_main.o
	g++ $(CFLAGS) -o roster_03A_good roster_03.o roster_03A_good_main.o

roster_05_bad_1.o: roster_05.hpp
roster_05_main.o: roster_05.hpp
roster_05_bad_1: roster_05_bad_1.o roster_05_main.o
	g++ $(CFLAGS) -o roster_05_bad_1 roster_05_bad_1.o roster_05_main.o

roster_05_bad_2.o: roster_05.hpp
roster_05_main.o: roster_05.hpp
roster_05_bad_2: roster_05_bad_2.o roster_05_main.o
	g++ $(CFLAGS) -o roster_05_bad_2 roster_05_bad_2.o roster_05_main.o

roster_05_good.o: roster_05.hpp
roster_05_main.o: roster_05.hpp
roster_05_good: roster_05_good.o roster_05_main.o
	g++ $(CFLAGS) -o roster_05_good roster_05_good.o roster_05_main.o

roster_06.o: roster_06.hpp
roster_06_main.o: roster_06.hpp
roster_06: roster_06.o roster_06_main.o
	g++ $(CFLAGS) -o roster_06 roster_06.o roster_06_main.o

roster_04.o: roster_04.hpp
roster_04_main.o: roster_04.hpp
roster_04: roster_04.o roster_04_main.o
	g++ $(CFLAGS) -o roster_04 roster_04.o roster_04_main.o

roster_03_evil.o: roster_03.hpp
roster_ev: roster_03.o roster_03_evil.o
	g++ $(CFLAGS) -o roster_ev roster_03.o roster_03_evil.o
