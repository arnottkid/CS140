EXECUTABLES = \
bin/simple_set \
bin/simple_multiset \
bin/simple_set_find \
bin/simple_map \
bin/nnames_multiset \
bin/qb_1_read_input \
bin/qb_2_qbs_class \
bin/qb_3_sort_by_rating_bad \
bin/qb_4_sort_by_rating \
bin/qb_5_print_by_name \
bin/qb_6_print_by_team \
bin/qb_7_destructor_etc \
bin/setreturn \

CFLAGS ?= -Wall -Wextra

all: $(EXECUTABLES)

clean:
	rm -f bin/* obj/* a.out

bin/nnames_multiset: src/nnames_multiset.cpp
	g++ $(CFLAGS) -o bin/nnames_multiset src/nnames_multiset.cpp

bin/setreturn: src/setreturn.cpp
	g++ $(CFLAGS) -o bin/setreturn src/setreturn.cpp

bin/simple_map: src/simple_map.cpp
	g++ $(CFLAGS) -o bin/simple_map src/simple_map.cpp

bin/simple_multiset: src/simple_multiset.cpp
	g++ $(CFLAGS) -o bin/simple_multiset src/simple_multiset.cpp

bin/simple_set: src/simple_set.cpp
	g++ $(CFLAGS) -o bin/simple_set src/simple_set.cpp

bin/simple_set_find: src/simple_set_find.cpp
	g++ $(CFLAGS) -o bin/simple_set_find src/simple_set_find.cpp

bin/qb_1_read_input: src/qb_1_read_input.cpp
	g++ $(CFLAGS) -o bin/qb_1_read_input src/qb_1_read_input.cpp

bin/qb_2_qbs_class: src/qb_2_qbs_class.cpp
	g++ $(CFLAGS) -o bin/qb_2_qbs_class src/qb_2_qbs_class.cpp

bin/qb_2a_bad_find: src/qb_2a_bad_find.cpp
	g++ $(CFLAGS) -o bin/qb_2a_bad_find src/qb_2a_bad_find.cpp

bin/qb_3_sort_by_rating_bad: src/qb_3_sort_by_rating_bad.cpp
	g++ $(CFLAGS) -o bin/qb_3_sort_by_rating_bad src/qb_3_sort_by_rating_bad.cpp

bin/qb_4_sort_by_rating: src/qb_4_sort_by_rating.cpp
	g++ $(CFLAGS) -o bin/qb_4_sort_by_rating src/qb_4_sort_by_rating.cpp

bin/qb_5_print_by_name: src/qb_5_print_by_name.cpp
	g++ $(CFLAGS) -o bin/qb_5_print_by_name src/qb_5_print_by_name.cpp

bin/qb_6_print_by_team: src/qb_6_print_by_team.cpp
	g++ $(CFLAGS) -o bin/qb_6_print_by_team src/qb_6_print_by_team.cpp

bin/qb_7_destructor_etc: src/qb_7_destructor_etc.cpp
	g++ -std=c++11 $(CFLAGS) -o bin/qb_7_destructor_etc src/qb_7_destructor_etc.cpp
