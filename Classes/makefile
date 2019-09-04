ALL = roster_01 roster_02 roster_03 roster_ev roster_04 roster_05_bad_1 roster_05_bad_2 \
      roster_05_good roster_06

all: $(ALL)

clean:
	rm -f *.o $(ALL)

.SUFFIXES: .cpp .o

.cpp.o:
	g++ -c $*.cpp 

roster_01.o: roster_01.h
roster_01_main.o: roster_01.h
roster_01: roster_01.o roster_01_main.o
	g++ -o roster_01 roster_01.o roster_01_main.o

roster_02.o: roster_02.h
roster_02_main.o: roster_02.h
roster_02: roster_02.o roster_02_main.o
	g++ -o roster_02 roster_02.o roster_02_main.o

roster_03.o: roster_03.h
roster_03_main.o: roster_03.h
roster_03: roster_03.o roster_03_main.o
	g++ -o roster_03 roster_03.o roster_03_main.o

roster_05_bad_1.o: roster_05.h
roster_05_main.o: roster_05.h
roster_05_bad_1: roster_05_bad_1.o roster_05_main.o
	g++ -o roster_05_bad_1 roster_05_bad_1.o roster_05_main.o

roster_05_bad_2.o: roster_05.h
roster_05_main.o: roster_05.h
roster_05_bad_2: roster_05_bad_2.o roster_05_main.o
	g++ -o roster_05_bad_2 roster_05_bad_2.o roster_05_main.o

roster_05_good.o: roster_05.h
roster_05_main.o: roster_05.h
roster_05_good: roster_05_good.o roster_05_main.o
	g++ -o roster_05_good roster_05_good.o roster_05_main.o

roster_06.o: roster_06.h
roster_06_main.o: roster_06.h
roster_06: roster_06.o roster_06_main.o
	g++ -o roster_06 roster_06.o roster_06_main.o

roster_04.o: roster_04.h
roster_04_main.o: roster_04.h
roster_04: roster_04.o roster_04_main.o
	g++ -o roster_04 roster_04.o roster_04_main.o

roster_03_evil.o: roster_03.h
roster_ev: roster_03.o roster_03_evil.o
	g++ -o roster_ev roster_03.o roster_03_evil.o
