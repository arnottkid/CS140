EXECUTABLES = setreturn simple_map simple_multiset simple_set simple_set_find nnames_multiset sort_names_1 sort_names_2 sort_names_bad2 sort_names_bad3 sort_names_bad

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


nnames_multiset: nnames_multiset.o
	g++ $(CFLAGS) -o nnames_multiset nnames_multiset.o

setreturn: setreturn.o
	g++ $(CFLAGS) -o setreturn setreturn.o

simple_map: simple_map.o
	g++ $(CFLAGS) -o simple_map simple_map.o

simple_multiset: simple_multiset.o
	g++ $(CFLAGS) -o simple_multiset simple_multiset.o

simple_set: simple_set.o
	g++ $(CFLAGS) -o simple_set simple_set.o

simple_set_find: simple_set_find.o
	g++ $(CFLAGS) -o simple_set_find simple_set_find.o

sort_names_1: sort_names_1.o
	g++ $(CFLAGS) -o sort_names_1 sort_names_1.o

sort_names_2: sort_names_2.o
	g++ $(CFLAGS) -o sort_names_2 sort_names_2.o

sort_names_bad2: sort_names_bad2.o
	g++ $(CFLAGS) -o sort_names_bad2 sort_names_bad2.o

sort_names_bad3: sort_names_bad3.o
	g++ $(CFLAGS) -o sort_names_bad3 sort_names_bad3.o

sort_names_bad: sort_names_bad.o
	g++ $(CFLAGS) -o sort_names_bad sort_names_bad.o
