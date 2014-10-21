class Edge:

	# Build a new Edge. If the user supplies a cost, set our cost 
	# for this Edge to that cost.  If he doesn't give a cost,
	# assume the cost is 0.0.
	# By default, an Edge is good, so we set its badness
	# to False at the start.
	def __init__(self, newCost = 0.0):
		self.cost = newCost
		self.bad = False
				
	# change the cost of an Edge
	def setCost(self, newCost):
		self.cost = newCost
		
	# get the cost of an Edge
	def getCost(self):
		return self.cost
		
	# change the badness of an Edge
	def setBadness(self, badOrNot):
		self.bad = badOrNot
	
	# find out the badness of an Edge
	def getBadness(self):
		return self.bad
	
	# decide if an Edge is really a zero edge
	def empty(self):
		# by checking if it's less than a really small number
		return self.cost < 0.00000000000000000001;
		
	
