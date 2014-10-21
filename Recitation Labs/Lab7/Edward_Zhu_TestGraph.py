from Graph import *
from Vertex import *
from Edge import *

def main():
	# make a new Graph called fredo

	fredo = Graph()
	
	fredo.addVertex('A')	
	fredo.addVertex('B')
	fredo.addVertex('C')
	
	fredo.setEdge('A', 'A', 1.0)
	fredo.setEdge('A', 'B', 2.0)
	fredo.setEdge('A', 'C', 3.0)
	fredo.setEdge('B', 'A', 5.0)
	fredo.setEdge('B', 'B', 6.0)
	fredo.setEdge('B', 'C', 7.0)
	fredo.setEdge('C', 'A', 9.0)
	fredo.setEdge('C', 'B', 10.0)
	fredo.setEdge('C', 'C', 11.0)

	
	fredo.display()
	
	if fredo.countVertices() != 3:
		print 'Bad graph! Vertices are wrong', g.countVertices()
	else:
		print 'Vertices are correct'
	
	fredo.addVertex('D')
	fredo.addVertex('E')
	fredo.addVertex('E')
	#duplicating a vertex doesn't add another vertex to the count
	
	fredo.display()
	
	if fredo.countVertices() != 5:
		print 'Bad graph! Vertices are wrong', g.countVertices()
	else:
		print 'Vertices are correct'
	
	if fredo.countEdges() != 6:
		print 'Bad graph! Edges are wrong', fredo.countEdges()
	else:
		print 'Edges are still correct'
	
	
	
	fredo.setEdge('D', 'A', 0.0)
	fredo.setEdge('D', 'A', 9.0)
	#fredo.setEdge('D', 'A', 0.0) 
	#if you set it to zero, it doesn't 
	#count it as a edge
	fredo.setEdge('D', 'B', 2.0)
	fredo.setEdge('E', 'C', 4.0)
	#this edge below doesn't add an edge, and if you take it out, it
	#doesn't change anything as well
	fredo.setEdge('E', 'E', 4.0)
	
	
	fredo.display()
	
	if fredo.countEdges() != 9:
		print 'Bad graph! Edges are wrong', fredo.countEdges()
	else:
		print 'Edges are still correct'
	
	
	#  add code here to test Fredo the Graph. Remember the rules:
	#  no duplicate Vertex names, no edges from a Vertex to itself,
	#  edges with zero cost are just fillers--not real edges.
	#  Some examples to get you thinking about Graphs for the test:
	#  add a few Vertices to fredo, with different names.
	#  display fredo's representation of himself now
	#  quiz fredo about his vertexCount and edgeCount (this last should be 0)
	#  add a few Edges to fredo and test the edgeCount
	#  try a self edge and see if it changes edgeCount or displays 
	#  try a duplicate Vertex and see if it changes vertexCount or displays 
	#  set an existing Edge in the graph to a zero cost and ask if edgeCount has changed
	# remove a zero edge from the graph and ask whether edgeCount has changed
	
	
# this line is needed to run main programs in Python.  God only knows why.
if __name__ == "__main__":
    main()



