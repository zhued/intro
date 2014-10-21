from Graph import *		
from Vertex import *
from Edge import *

def main():

	print 'Testing all the things'
	# make a new variable of type Graph (so it gets made like the Graph.py class)
	g = Graph()
	# add 4 Vertices to the Graph, with the names Abilene, Boston, Chicago, Denver
	g.addVertex('Abilene')	
	g.addVertex('Boston')
	g.addVertex('Chicago')
	g.addVertex('Denver')
	# Now we have a Graph with 4 Vertices and 16 empty Edges.
	# Let's try to set all the Edges.  (We don't actually set 
	# Edges from a Vertex to itself, so these self Edges should 
	# never actually show up when we display that Graph.)
	g.setEdge('Abilene', 'Abilene', 1.0)
	g.setEdge('Abilene', 'Boston', 2.0)
	g.setEdge('Abilene', 'Chicago', 3.0)
	g.setEdge('Abilene', 'Denver', 4.0)
	g.setEdge('Boston', 'Abilene', 5.0)
	g.setEdge('Boston', 'Boston', 6.0)
	g.setEdge('Boston', 'Chicago', 7.0)
	g.setEdge('Boston', 'Denver', 8.0)
	g.setEdge('Chicago', 'Abilene', 9.0)
	g.setEdge('Chicago', 'Boston', 10.0)
	g.setEdge('Chicago', 'Chicago', 11.0)
	g.setEdge('Chicago', 'Denver', 12.0)
	g.setEdge('Denver', 'Abilene', 13.0)
	g.setEdge('Denver', 'Boston', 14.0)
	g.setEdge('Denver', 'Chicago', 15.0)
	g.setEdge('Denver', 'Denver', 16.0)
	
	# print the Vertex names and the Edge costs in the array
	g.display()
	
	# check if our vertexCount is correct
	if g.countVertices() != 4:
		print 'Bad graph! Vertices are wrong', g.countVertices()
	else:
		print 'Test 1 ok'
		
	# check if our edgeCount is correct
	if g.countEdges() != 12:
		print 'Bad graph! Edges are wrong', g.countEdges()
	else:
		print 'Test 2 ok'
		
	# make a copy of g, called h
	h = Graph()
	h.copyDeeply(g)

	# take out a Vertex
	g.removeVertex('Chicago')
	print 'Here is graph g after Chicago is removed'
	g.display()

	# make a copy of the 3-Vertex Graph g, called i
	i = Graph()
	i.copyDeeply(g)
	
	# check if our vertexCount is correct after Chicago comes out
	if g.countVertices() != 3:
		print 'Bad graph! Vertices are wrong', g.countVertices()
	else:
		print 'Test 3 ok'
	
	# check if our edgeCount is correct after Chicago's edges come out
	if g.countEdges() != 6:
		print 'Bad graph! Edges are wrong', g.countEdges()
	else:
		print 'Test 4 ok'
	
	# check if our edgeCount is correct after Abilene->Boston edge comes out
	g.setEdge('Abilene','Boston', 0.0)
	if g.countEdges() != 5:
		print 'Bad graph! Edges are wrong', g.countEdges()
	else:
		print 'Test 5 ok'
		
	g.removeEdge('Boston','Denver')
	# check if our edgeCount is correct after Boston->Denver edge comes out
	if g.countEdges() != 4:
		print 'Bad graph! Edges are wrong', g.countEdges()
	else:
		print 'Test 6 ok'
	
	g.removeEdge('Boston','Boston')
	# check if our edgeCount is correct after empty Boston->Boston edge comes out
	if g.countEdges() != 4:
		print 'Bad graph! Edges are wrong', g.countEdges()
	else:
		print 'Test 7 ok'
	
	# check if we know that the Boston->Denver edge is out
	if not g.containsEdge('Boston', 'Denver'):
		print 'Bad graph! Edges are wrong, Boston->Denver should not be in Graph'
	else:
		print 'Test 8 ok'
		
	# check if Boston is there
	if not g.containsVertex('Boston'):
		print 'Bad graph! Boston should be in Graph'
	else:
		print 'Test 9 ok'

	# check if Boston is there and Chicago is not
	if g.containsVertex('Chicago'):
		print 'Bad graph! Chicago should not be in Graph'
	else:
		print 'Test 10 ok'
	
	
	g.display()	
	
	# put Chicago back into i
	i.addVertex('Chicago')
	# put all the old Edges g used to have to and from Chicago into i
	i.setEdge('Chicago', 'Abilene', 9.0)
	i.setEdge('Chicago', 'Boston', 10.0)
	i.setEdge('Chicago', 'Chicago', 11.0)
	i.setEdge('Chicago', 'Denver', 12.0)
	i.setEdge('Abilene', 'Chicago', 3.0)
	i.setEdge('Boston', 'Chicago', 7.0)
	i.setEdge('Denver', 'Chicago', 15.0)
	
	# show us the Graph i now
	print 'Here is graph i.'
	i.display()
	
	# show us the Graph h, which we copied from g before
	# we deleted Chicago from g 
	if h.isEqual(i):
		print 'Here is graph h, which is the same as i.'
		print 'Anyone who says different is itching for a fight.'
	else:
		print 'Here is graph h, which is not the same as i.'
	h.display()
	
	j = Graph()
	j.copyDeeply(h)
	# check if deep copy works on self-copying (h to h)
	h.copyDeeply(h)
	if j.countVertices() != h.countVertices():
		print 'Bad graph! These should be the same size'
		h.display()
		j.display()
	else:
		print 'Test 11 ok'
	
	
	
# this line is needed to run main programs in Python.  God only knows why.
if __name__ == "__main__":
    main()
