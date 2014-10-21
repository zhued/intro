
EXPENDABLES = TestGraph

all:	
	@make $(EXPENDABLES)

TestGraph:TestGraph.cxx 
	g++ -static TestGraph.cxx -L./lib -lGraphTemplate -o TestGraph

clean:
	rm $(EXPENDABLES)
