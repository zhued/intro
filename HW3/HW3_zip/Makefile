EXPENDABLES = main_map main_map.o

all:	
	@make $(EXPENDABLES)

main_map : main_map.o
	g++ -Wall -gstabs main_map.o -o main_map

# make object file (ends in .o) with partial compilation of code for the main program
main_map.o : main_map.cpp
	g++ -Wall -gstabs -c main_map.cpp -o main_map.o

clean:
	rm $(EXPENDABLES)
