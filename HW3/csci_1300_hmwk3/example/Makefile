EXPENDABLES = map_example map_example.o

all:	
	@make $(EXPENDABLES)

map_example : map_example.o
	g++ -Wall -gstabs map_example.o -o map_example

# make object file (ends in .o) with partial compilation of code for the main program
map_example.o : map_example.cpp
	g++ -Wall -gstabs -c map_example.cpp -o map_example.o

clean:
	rm $(EXPENDABLES)
