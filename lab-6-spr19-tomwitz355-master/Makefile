file1= BSTree
file2= lab6
OBJECTS= $(file2).o
CFLAGS= -std=c++14 -g

all: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o $(file2)


$(file1).o: $(file1).h $(file2).cpp
	g++ -c $(CFLAGS) $(file1).cpp

clean:
	rm -rf *.o
	rm $(file2)

run: all
	./$(file2)
memcheck: all
	valgrind ./$(file2)
