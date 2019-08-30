# +mkmake+ -- Everything after this line is automatically generated

EXECUTABLES = cd_partition cd_partition_prototype readlist refparam rev_1 rev_2 timing_convert timing_procedure total_etc_1 total_etc_2

all: $(EXECUTABLES)

clean:
	rm -f core *.o $(EXECUTABLES) a.out

CFLAGS = -O

.SUFFIXES: .cpp .o
.cpp.o:
	g++ $(CFLAGS) -c $*.cpp


cd_partition: cd_partition.o
	g++ $(CFLAGS) -o cd_partition cd_partition.o

cd_partition_prototype: cd_partition_prototype.o
	g++ $(CFLAGS) -o cd_partition_prototype cd_partition_prototype.o

readlist: readlist.o
	g++ $(CFLAGS) -o readlist readlist.o

refparam: refparam.o
	g++ $(CFLAGS) -o refparam refparam.o

rev_1: rev_1.o
	g++ $(CFLAGS) -o rev_1 rev_1.o

rev_2: rev_2.o
	g++ $(CFLAGS) -o rev_2 rev_2.o

timing_convert: timing_convert.o
	g++ $(CFLAGS) -o timing_convert timing_convert.o

timing_procedure: timing_procedure.o
	g++ $(CFLAGS) -o timing_procedure timing_procedure.o

total_etc_1: total_etc_1.o
	g++ $(CFLAGS) -o total_etc_1 total_etc_1.o

total_etc_2: total_etc_2.o
	g++ $(CFLAGS) -o total_etc_2 total_etc_2.o
