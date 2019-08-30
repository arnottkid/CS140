EXEC = pascal vcopy vdm


CFLAGS ?= -Wall -Wextra

all: $(EXEC)

clean:
	rm -f a.out $(EXEC) *.o

pascal: pascal.cpp
	g++ $(CFLAGS) -o pascal pascal.cpp

vcopy: vcopy.cpp
	g++ $(CFLAGS) -o vcopy vcopy.cpp

vdm: vdm.cpp
	g++ $(CFLAGS) -o vdm vdm.cpp

