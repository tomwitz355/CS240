file1= Vector
file2= lab4
file3= Queue
OBJECTS= $(file2).o
CFLAGS= -std=c++14 -g

all: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o $(file2)


$(file2).o: $(file3).h $(file1).h $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp


clean:
	rm -rf *.o
	rm $(file2)

run: all
	./$(file2)
memcheck: all
	valgrind ./$(file2) -v --leak-check=full
