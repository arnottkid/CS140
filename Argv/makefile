EXEC = argc argv1int argv2int argvallint clearing-output identify_words onetoten

CFLAGS ?= -Wall -Wextra

all: $(EXEC)

clean:
	rm -f a.out $(EXEC) *.o

argc: argc.cpp
	g++ $(CFLAGS) -o argc argc.cpp

argv1int: argv1int.cpp
	g++ $(CFLAGS) -o argv1int argv1int.cpp


argv2int: argv2int.cpp
	g++ $(CFLAGS) -o argv2int argv2int.cpp

argvallint: argvallint.cpp
	g++ $(CFLAGS) -o argvallint argvallint.cpp

clearing-output: clearing-output.cpp
	g++ $(CFLAGS) -o clearing-output clearing-output.cpp

identify_words: identify_words.cpp
	g++ $(CFLAGS) -o identify_words identify_words.cpp

onetoten: onetoten.cpp
	g++ $(CFLAGS) -o onetoten onetoten.cpp

