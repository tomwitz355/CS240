l = lab3
p = Planet
s = Star

flags = -Wall -Wextra -DDEBUG -g -std=c++14

all: ${p}.o ${s}.o ${l}.o
	g++ ${flags} -o ${l} ${p}.o ${s}.o ${l}.o

${p}.o: ${p}.cpp
	g++ ${flags} -c -o ${p}.o ${p}.cpp

${l}.o: ${l}.cpp
	g++ ${flags} -c -o ${l}.o ${l}.cpp  
	
star.o: ${s}.cpp
	g++ ${flags} -c -o ${s}.o ${s}.cpp

run: all
	./${l}

memcheck: all
	valgrind ./${l}

clean:
	rm -rf *.o
	rm -rf ${l}
