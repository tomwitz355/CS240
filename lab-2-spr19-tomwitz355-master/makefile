p = lab2

flags = -Wall -Wextra -DDEBUG -g -std=c++14

all: main

main: ${p}.o star.o
	g++ ${flags} -o ${p} ${p}.o star.o

${p}.o: ${p}.cpp
	g++ ${flags} -c -o ${p}.o ${p}.cpp 
	
star.o: Star.cpp
	g++ ${flags} -c -o star.o Star.cpp

run: all
	./${p}

clean:
	rm -rf *.o
	rm -rf ${p}.exe
