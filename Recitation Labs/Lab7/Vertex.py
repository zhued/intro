class Vertex:

	# Build a new Vertex. If the user supplies a name,
	# set our name to that name.  If he doesn't give a name,
	# assume the name is an empty string ''.
	# By default, a Vertex is good, so we set its badness
	# to False at the start.
	def __init__(self, newName = ''):
		self.name = newName
		self.bad = False
				
	# change the name of a Vertex
	def setName(self, newName):
		self.name = newName
	
	# get the name of a Vertex
	def getName(self):
		return self.name
		
	# change the badness of a Vertex
	def setBadness(self, badOrNot):
		self.bad = badOrNot
	
	# find out the badness of a Vertex
	def getBadness(self):
		return self.bad
		
	
		
	
