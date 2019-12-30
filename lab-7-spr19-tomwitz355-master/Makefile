file1= Trie
file2= lab7
OBJECTS= $(file1).o $(file2).o
CFLAGS= -std=c++14 -g

all: $(file1).o $(file2).o
	g++ $(CFLAGS) $(OBJECTS) -o $(file2)

$(file1).o: $(file1).h $(file1).cpp
	g++ -c $(CFLAGS) $(file1).cpp

$(file2).o: $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp
clean:
	rm -rf *.o
	rm $(file2)

run: all
	./$(file2)
memcheck: all
	valgrind ./$(file2) -v --leak-check=full
