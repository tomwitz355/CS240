file1= Vector
file2= List
file3= Star
file4= Planet
file5= program1
OBJECTS= $(file1).o $(file2).o $(file3).o $(file4).o $(file5).o
CFLAGS= -std=c++14 -g

all: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o output

$(file1).o: $(file1).h $(file1).cpp
	g++ -c $(CFLAGS) $(file1).cpp

$(file2).o: $(file2).h $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp

$(file3).o: $(file3).h $(file3).cpp
	g++ -c $(CFLAGS) $(file3).cpp

$(file4).o: $(file4).h $(file4).cpp
	g++ -c $(CFLAGS) $(file4).cpp

$(file5).o: $(file5).cpp
	g++ -c $(CFLAGS) $(file5).cpp

clean:
	rm -rf *.o
	rm output

run: all
	./output
memcheck: all
	valgrind ./output -v
