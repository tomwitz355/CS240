file1= Planet
file2= Parser
file3= program2
file4= Scanner
target= program2
OBJECTS= $(file1).o $(file2).o $(file3).o $(file4).o
CFLAGS= -std=c++14 -g

all: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o $(target)


$(file1).o: $(file1).h $(file1).cpp
	g++ -c $(CFLAGS) $(file1).cpp

$(file2).o: $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp

$(file3).o: $(file3).cpp
	g++ -c $(CFLAGS) $(file3).cpp

$(file4).o: $(file4).cpp
	g++ -c $(CFLAGS) $(file4).cpp
clean:
	rm -rf *.o
	rm $(target)

run: all
	./$(target)
memcheck: all
	valgrind ./$(target) -v --leak-check=full

winclean:
	del *.o
	del $(target).exe
