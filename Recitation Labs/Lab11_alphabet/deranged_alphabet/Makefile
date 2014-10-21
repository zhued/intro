EXPENDABLES = deranged_lab deranged_lab.o

all:	
	@make $(EXPENDABLES)

deranged_lab : deranged_lab.o
	g++ -Wall -gstabs deranged_lab.o -o deranged_lab

# make object file (ends in .o) with partial compilation of code for the main program
deranged_lab.o : deranged_lab.cpp
	g++ -Wall -gstabs -c deranged_lab.cpp -o deranged_lab.o

clean:
	rm $(EXPENDABLES)
