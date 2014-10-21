# import the Edge class code 
from Edge import *
# import the Vertex class code
from Vertex import *

# Define a class to keep track of a Graph using a list
# of Vertices with unique names, and a list of lists of Edges
# with costs > 0.0.  Provide ways to add and remove Edges and
# Vertices, and to find out how the Graph is connected and 
# what it contains.
class Graph:

	# Create an empty Graph
	# This is analogous to the default constructor in C++, Graph( );
	def __init__(self):
		# make an empty Vertex list
		self.vertices = []
		# make an empty Edge list
		self.edges = []
		# initialize the Vertex count to be 0
		self.vertexCount = 0
		# initialize the Edge count to be 0
		self.edgeCount = 0
		# create the 'bad Vertex' 
		self.badVertex = Vertex('bad vertex')
		# set the badness flag for this bad Vertex
		self.badVertex.setBadness(True)
		# create the 'bad Edge'
		self.badEdge = Edge(0.0)
		# set the badness flag for this bad Edge
		self.badEdge.setBadness(True)
	
	# Clear out all the information in the Graph
	# so it is like an empty Graph again.
	# Analogous to the C++ function void clear( );
	def clear(self):
		# remove all the Edges and all the Vertices 
		# (more important in C++ than in Python)
		for i in range(0, self.vertexCount):
			for j in range(0, self.vertexCount):
				# pop the last Edge off the list 
				self.edges[self.vertexCount - 1].pop()
			# pop the last empty Edge sublist off edges
			self.edges.pop()
			# pop the last Vertex off vertices
			self.vertices.pop()
		# now everybody should be empty, and we should have
		# one empty list (vertices == []) for Vertex 
		# and one empty list (edges == []) for Edges
		# set vertexCount to 0
		self.vertexCount = 0
		# and set edgeCount to 0
		self.edgeCount = 0
		
	# Make our self's Graph be an independent copy of another Graph called g.
	# By independent, I mean that we can change our Graph (add a Vertex,
	# remove an Edge) after this and not change g the same way, as a side effect.
	# This function is loosely analogous to two functions in C++:
	# the assignment operator, Graph& operator =(const Graph& source);
    # and the copy constructor, Graph(const Graph& source);
	def copyDeeply(self, g):
		# self assignment check, done in C++ a little differently
		if self.isEqual(g):
			return
		# clear out the existing Vertex and Edge data
		self.clear()
		# copy each Vertex and update the Edge array as we go
		# notice here we can use the vertexCount of the other
		# graph, g to count how many to copy
		for i in range(0, g.vertexCount):
			# make a new Vertex from g's Vertex
			v = Vertex(g.vertices[i].name)
			# add that Vertex to our Vertex list
			self.vertices.append(v)
			# update our vertexCount
			self.vertexCount += 1
			# add a new row to the edges array; this is self.edges[i], below
			self.edges.append([])
			# copy a row of Edges from g to here
			for j in range(0, g.vertexCount):
				# make a new Edge from g's edge
				e = Edge(g.edges[i][j].cost)
				# add the Edge to the end of the row
				self.edges[i].append(e)
				# count edges up if the Edge is not a zero edge
				if e.empty() == False:
					self.edgeCount += 1
		# create the 'bad Vertex' we send back when there's 
		# no good answer to getVertex()
		self.badVertex = Vertex('bad vertex')
		# set this Vertex to be bad
		self.badVertex.setBadness(True)
		# create the 'bad Edge' we send back when there's 
		# no good answer to getEdge()
		self.badEdge = Edge(0.0)
		# set this Edge to be bad
		self.badEdge.setBadness(True)
	
	# function I wrote to compare 2 Graphs for equality
	# optional for you, but not trivial
	def isEqual(self, g):
		if self.vertexCount != g.vertexCount:
			return False
		if self.edgeCount != g.edgeCount:
			return False
		eps = 0.00000000000000000001
		for i in range(0, g.vertexCount):
			index = self.getIndex(g.vertices[i].getName())
			if self.validIndex(index) == False:
				return False
			otherRow = i
			myRow = index
			for j in range(0, g.vertexCount):
				otherCol = j
				myCol = self.getIndex(g.vertices[j].getName())
				if abs(self.edges[myRow][myCol].getCost() - g.edges[otherRow][otherCol].getCost()) > eps:
					return False
		return True
			
	# Put a new Vertex in the Graph and update the Edge list.
	# No duplicate Vertex names are allowed.
	# This function is analogous to the C++ function 
	# bool addVertex(const string& newVertexname);  
	def addVertex(self, vertexName):
		# look at each of our current Vertex
		for i in range(0, self.vertexCount):
			# check if this Vertex has the same name as the
			# one we want to add; if so, bail out without
			# adding the duplicate
			if self.vertices[i].getName() == vertexName:
				return False
		# if we didn't bail out in that for loop, then we add the new Vertex.
		# we make a new Vertex with this name
		v = Vertex(vertexName)
		# we put that Vertex in our vertices list
		self.vertices.append(v)
		# we make a new row that we'll put in the edges array 
		# for this Vertex
		newRow = []
		# we fill that row with empty Edges
		# notice that because vertexCount is still not updated
		# to count the new Vertex, we have to put one more
		# Edge in to keep the whole edges list square
		for i in range(0, self.vertexCount + 1):
			# make a new empty Edge
			e = Edge(0.0)
			# put this Edge in the new row
			newRow.append(e)
		# now add that new row to the edges array
		self.edges.append(newRow)
		# we add one extra Edge to each of the previous rows of edges,
		# which makes a new column in the edges array for this Vertex
		# Note that vertexCount is still not updated, so we only do this
		# for the rows in the edges array that we had before adding this 
		# Vertex.
		for i in range(0, self.vertexCount):
			# make one new empty Edge
			e = Edge(0.0)
			# add that Edge to the end of this row
			self.edges[i].append(e)
		# finally we update vertexCount
		self.vertexCount += 1
		# success, return True
		return True

	# Take a Vertex out of the Graph and update the Edge list, 
	# returning True if things go as expected. If this Vertex 
	# is not in the Graph, remove nothing, and return False.
	# This function is analogous to the C++ function
	# bool removeVertex(const string& unwantedVertexName);  
	def removeVertex(self, vertexName):
		# helper function getIndex tells us the position of a Vertex
		# in our vertices list.  If it's not there, getIndex gives back -1.
		index = self.getIndex(vertexName)
		# helper function validIndex checks that this index >= 0
		# and index < vertexCount. If it's outside that range,
		# we do not have a Vertex by this name, so we bail out
		# without removing anything and send back a False to 
		# indicate weirdness on the user's part.
		if (self.validIndex(index) == False):
			return False
		# if we get to here, then we really have a Vertex to remove
		# First, we have to get rid of this Vertex's row in the Edges list.
		# But we want to keep our count of nonzero Edges up to date,
		# so first we subtract any real Edges in this row from edgeCount.
		for i in range(0, self.vertexCount):
			# if the Edge we're throwing away is nonzero, 
			# count edgeCount down
			if (self.edges[index][i].empty() == False):
				self.edgeCount -= 1
		# take this whole row of Edges out of the edges list
		self.edges.pop(index)
		# now take out the column of Edges to this Vertex in the other rows
		for i in range(0, self.vertexCount - 1):
			# if the Edge we're throwing away is nonzero, 
			# count edgeCount down
			if (self.edges[i][index].empty() == False):
				self.edgeCount -= 1
			# take out the edge in this column
			self.edges[i].pop(index)
		# take out this Vertex from our list
		self.vertices.pop(index)
		# update our vertexCount to be one less
		self.vertexCount -= 1
		# send back True to show that things all went as expected
		return True
				
	# Given the names of 2 Vertex in the Graph, set an Edge 
	# between them to have a particular cost. 
	# If the Vertex both exist and are not the same Vertex, 
	# update the cost of their Edge and return True.
	# If one or both Vertex are not in the Graph, or if
	# the Edge is from one Vertex to itself, make no changes 
	# and send back a False to indicate a problem on the
	# user's end.
	# This function is analogous to the C++ function
	# bool setEdge(const string& fromVertexName, const string& toVertexName, const Edge& newEdge);
	def setEdge(self, fromVertexName, toVertexName, cost):
		# quickly check for self-edges, which are not allowed
		if fromVertexName == toVertexName:
			return False
		# use the helper function getIndex to find the position
		# of the 'from'-Vertex in our Vertex list
		fromIndex = self.getIndex(fromVertexName)
		# use the helper function getIndex to find the position
		# of the 'to'-Vertex in our Vertex list
		toIndex = self.getIndex(toVertexName)
		# check that both of these indexes are valid and update the
		# Edge if they both are
		if (self.validIndex(fromIndex) and self.validIndex(toIndex) and fromIndex != toIndex):
			# we might be overwriting a real (nonzero) Edge;
			# if so we subtract one from edgeCount
			if self.edges[fromIndex][toIndex].empty() == False:
				self.edgeCount -= 1
			# update the Edge to have the new cost
			self.edges[fromIndex][toIndex].setCost(cost)
			# check if this Edge is empty; if not, add one to  
			# edgeCount 
			if self.edges[fromIndex][toIndex].empty() == False:
				self.edgeCount += 1
			# success, we are done
			return True
		# if one or both of fromIndex or toIndex is invalid, then 
		# we don't have one or both of these Vertex, so we bail 
		# out and send back a False to indicate user weirdness
		else:
			return False
	
	# return True if the Graph is empty, which means it has no
	# Vertex at all.  Else, return False.
	# This is analogous to the C++ function bool empty( ) const;
	def empty(self):
		return self.vertexCount == 0
	
	# return True if the Graph contains a Vertex, and False if not.
	# this function is analogous to the C++ function:
	# bool containsVertex(const string& vertexName) const;
	def containsVertex(self, vertexName):
		# use the getIndex helper function to find the position
		# of the Vertex with this name in the vertices list
		index = self.getIndex(vertexName)
		# if this index is valid, the Graph contains this Vertex
		# if it's not, the Graph does not contain this Vertex
		return self.validIndex(index)
		
	# return True if the Graph contains an Edge between 2 Vertex, 
	# and False if not.
	# this function is analogous to the C++ function
	# bool containsEdge(const string& fromVertexname, const string& toVertexName) const;
	def containsEdge(self, fromVertexName, toVertexName):
		# use the getIndex helper function to find the position
		# of the 'from' Vertex with this name in the vertices list
		fromIndex = self.getIndex(fromVertexName)
		# use the getIndex helper function to find the position
		# of the 'to' Vertex with this name in the vertices list
		toIndex = self.getIndex(toVertexName)
		# if these are both valid indexes, then return True
		# if that Edge between them is not a zero edge,
		# and False if it is
		if (self.validIndex(fromIndex) and self.validIndex(toIndex)):
			return self.edges[fromIndex][toIndex].empty()
		# if these aren't valid indices, we don't have an Edge
		# for them in the Graph; return False
		else:
			return False
		
	# Given the names of 2 Vertex in the Graph, set an Edge 
	# between them to have zero cost and return True. If 
	# these Vertex aren't in the Graph, return False.
	# This function is analogous to the C++ function
	# bool removeEdge(const string& fromVertexName, const string& toVertexName);
	def removeEdge(self, fromVertexName, toVertexName):
		# use the getIndex helper function to find the position
		# of the 'from' Vertex with this name in the vertices list
		fromIndex = self.getIndex(fromVertexName)
		# use the getIndex helper function to find the position
		# of the 'to' Vertex with this name in the vertices list
		toIndex = self.getIndex(toVertexName)
		# check if these are both valid indexes, using the helper
		# function isValid; if so, then update the Edge
		# to be zero cost
		if (self.validIndex(fromIndex) and self.validIndex(toIndex)):
			# if we're changing a non-empty Edge to be empty, 
			# we need to subtract one from edgeCount
			if self.edges[fromIndex][toIndex].empty() == False:
				self.edgeCount -= 1
			# update the cost to 0
			self.edges[fromIndex][toIndex].setCost(0.0)
			# success, we're done
			return True
		# if these are not both valid indexes, then we bail and
		# return False
		else:
			return False
	
	# Given a name of a Vertex, return that Vertex if it exists
	# in the Graph.  If it does not exist, return the bad Vertex 
	# we keep around for just this situation.
	# This function is analogous to the C++ function
	# const Vertex& getVertex(const string& vertexName) const;
    # and Vertex& getVertex(const string& vertexName);            
	def getVertex(self, vertexName):
		# use the getIndex helper function to find the position
		# of the Vertex with this name in the vertices list
		index = self.getIndex(vertexName)
		# if this index is valid, return the Vertex in our list at
		# that index
		if self.validIndex(index):
			return self.vertices[index]
		# else, send back the bad Vertex
		else:
			return self.badVertex
	
	# Given the names of two Vertices, return the Edge from the first
	# Vertex to the second one, if these Vertices exist in the Graph.  
	# If one of the Vertices does not exist, or both don't, return the 
	# bad Vertex we keep around for just this situation.
	# this function is analogous to the C++ functions
	# const Edge& getEdge(const string& fromVertexName, const string& toVertexName) const;
    # and Edge& getEdge(const string& fromVertexName, const string& toVertexName);       
	def getEdge(self, fromVertexName, toVertexName):
		# use the getIndex helper function to find the position
		# of the 'from' Vertex with this name in the vertices list
		fromIndex = self.getIndex(fromVertexName)
		# use the getIndex helper function to find the position
		# of the 'to' Vertex with this name in the vertices list
		toIndex = self.getIndex(toVertexName)
		# check if these are both valid indexes, using the helper
		# function isValid; if so, then send back this Edge
		if (self.validIndex(fromIndex) and self.validIndex(toIndex)):
			return self.edges[fromIndex][toIndex]
		# if these are not both valid indexes, return the bad Edge
		else:
			return self.badEdge
			
	# tell me how many Vertex the Graph has
	def countVertices(self):
		return self.vertexCount
	
	# tell me how many nonzero Edges the Graph has
	def countEdges(self):
		return self.edgeCount
	
	# Helper function to print an array representation of the 
	# Graph, with the 'from'-Vertex names down the left hand side 
	# and the 'to'-Vertex names across the top, and the edges 
	# between then printing as their costs
	def display(self):
		s = '\t'
		for i in range(0, self.vertexCount):
			s += self.vertices[i].getName()[:7] 
			s += '\t'
		s += '\n'
		for i in range(0, self.vertexCount):
			s += self.vertices[i].getName()[:7] 
			s += '\t'
			for j in range(0, self.vertexCount):
				s += str(self.edges[i][j].getCost()) 
				s += '\t'
			s += '\n'
		print s
			
	# Helper function to look up vertex names in the vertices list
	# If the vertex name matches one in our Graph, then this returns
	# the position of that Vertex in the vertices list.
	# If not, this returns a weird value, -1, which is a bad
	# index into a list
	def getIndex(self, vertexName):
		# loop over each Vertex in the Vertex list
		for i in range(0, self.vertexCount):
			# check if the name matches the one we're looking for;
			# if so, return this index right away.
			if self.vertices[i].getName() == vertexName:
				return i
		# if we get all the way through the Vertex names,
		# and we never found a match, we don't have this Vertex
		return -1
	
	# Helper function to make sure that an index into the Vertex 
	# list is not out of bounds. Returns True if the index is 
	# valid, and False if it's out of bounds.
	def validIndex(self, index):
		return (index >= 0 and index < self.vertexCount)
	
	
