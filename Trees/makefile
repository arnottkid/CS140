ALL = bstree_test
    

all: $(ALL)

clean:
	rm -f *.o $(ALL)

.SUFFIXES: .cpp .o

.cpp.o:
	g++ -c $*.cpp

bstree_test: bstree_test.o bstree.o
	g++ -o bstree_test bstree_test.o bstree.o

