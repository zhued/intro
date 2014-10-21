EXPENDABLES = cipher cipher.o

all:	
	@make $(EXPENDABLES)

cipher : cipher.o
	g++ -Wall -gstabs cipher.o -o cipher

# make object file (ends in .o) with partial compilation of code for the main program
cipher.o : cipher.cpp
	g++ -Wall -gstabs -c cipher.cpp -o cipher.o

clean:
	rm $(EXPENDABLES)
