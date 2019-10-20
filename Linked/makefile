ALL = stackrev queuetail dlistrev-1 dlistrev-2 dlistrev-3 dlistrev-4 dlistrev-5 dlistrev-6
    

all: $(ALL)

clean:
	rm *.o $(ALL)

.SUFFIXES: .cpp .o

.cpp.o:
	g++ -c $*.cpp

stack.o: stack.h
stackrev.o: stack.h

stackrev: stackrev.o stack.o
	g++ -o stackrev stackrev.o stack.o

queue.o: queue.h
queuetail.o: queue.h

queuetail: queuetail.o queue.o
	g++ -o queuetail queuetail.o queue.o

dlisttail.o: dlist.h

dlisttail: dlisttail.o dlist.o
	g++ -o dlisttail dlisttail.o dlist.o

dlistrev-1.o: dlist.h
dlistrev-1: dlistrev-1.o dlist.o
	g++ -o dlistrev-1 dlistrev-1.o dlist.o

dlistrev-2.o: dlist.h
dlistrev-2: dlistrev-2.o dlist.o
	g++ -o dlistrev-2 dlistrev-2.o dlist.o

dlistrev-3.o: dlist.h
dlistrev-3: dlistrev-3.o dlist.o
	g++ -o dlistrev-3 dlistrev-3.o dlist.o

dlistrev-4.o: dlist.h
dlistrev-4: dlistrev-4.o dlist.o
	g++ -o dlistrev-4 dlistrev-4.o dlist.o

dlistrev-5.o: dlist.h
dlistrev-5: dlistrev-5.o dlist.o
	g++ -o dlistrev-5 dlistrev-5.o dlist.o

dlistrev-6.o: dlist.h
dlistrev-6: dlistrev-6.o dlist.o
	g++ -o dlistrev-6 dlistrev-6.o dlist.o

