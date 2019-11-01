CC = gcc
ROOTDIR = /home/plank/cs140/Fall-2005
INCLUDE = -I/$(ROOTDIR)/include
LIBDIR = $(ROOTDIR)/objs
LIBS = $(LIBDIR)/libfdr.a
CFLAGS = -g $(INCLUDE)
ALL = bstree_test

all: $(ALL)

clean:
	rm -f *.o core $(ALL)

bstree_test: bstree_test.o bstree.o
	$(CC) $(CFLAGS) -o bstree_test bstree_test.o bstree.o $(LIBS)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $*.c


