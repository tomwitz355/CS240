file1= Planet
file2= Star
file3= Probe
file4= lab5
OBJECTS= $(file1).o $(file2).o $(file3).o $(file4).o
CFLAGS= -std=c++14 -g

all: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o $(file4)


$(file1).o: $(file1).h $(file1).cpp
	g++ -c $(CFLAGS) $(file1).cpp

$(file2).o: $(file2).h $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp

$(file3).o: $(file3).h $(file3).cpp
	g++ -c $(CFLAGS) $(file3).cpp

$(file4).o: $(file4).cpp
	g++ -c $(CFLAGS) $(file4).cpp


clean:
	rm -rf *.o
	rm $(file4)

run: all
	./$(file4)
memcheck: all
	valgrind ./$(file4) -v --leak-check=full
