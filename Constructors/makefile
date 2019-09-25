EXECUTABLES = bin/const1 \
              bin/const2_exception \
              bin/const3_destructor \
              bin/const4_dest_except \
              bin/const5_vector1 \
              bin/const6_vector2 \
              bin/const7_copy \
              bin/this \
              bin/overload \
              bin/code_in_declarations \
              bin/vector_pointer \
              bin/exception_char_star \

CFLAGS ?= -Wall -Wextra

all: $(EXECUTABLES)

clean:
	rm -f bin/* obj/* a.out

bin/const1: src/const1.cpp
	g++ $(CFLAGS) -o bin/const1 src/const1.cpp

bin/const2_exception: src/const2_exception.cpp
	g++ $(CFLAGS) -o bin/const2_exception src/const2_exception.cpp

bin/const3_destructor: src/const3_destructor.cpp
	g++ $(CFLAGS) -o bin/const3_destructor src/const3_destructor.cpp

bin/const4_dest_except: src/const4_dest_except.cpp
	g++ $(CFLAGS) -o bin/const4_dest_except src/const4_dest_except.cpp

bin/const5_vector1: src/const5_vector1.cpp
	g++ $(CFLAGS) -o bin/const5_vector1 src/const5_vector1.cpp

bin/const6_vector2: src/const6_vector2.cpp
	g++ $(CFLAGS) -o bin/const6_vector2 src/const6_vector2.cpp

bin/const7_copy: src/const7_copy.cpp
	g++ $(CFLAGS) -o bin/const7_copy src/const7_copy.cpp

bin/this: src/this.cpp
	g++ $(CFLAGS) -o bin/this src/this.cpp

bin/overload: src/overload.cpp
	g++ $(CFLAGS) -o bin/overload src/overload.cpp

bin/code_in_declarations: src/code_in_declarations.cpp
	g++ $(CFLAGS) -o bin/code_in_declarations src/code_in_declarations.cpp

bin/vector_pointer: src/vector_pointer.cpp
	g++ $(CFLAGS) -o bin/vector_pointer src/vector_pointer.cpp

bin/exception_char_star: src/exception_char_star.cpp
	g++ $(CFLAGS) -o bin/exception_char_star src/exception_char_star.cpp

