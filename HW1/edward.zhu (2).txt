# NAME: Edward Zhu
# LECTURE SECTION: 010 MWF 10AM
# RECITATION SECTION: 305 W 9AM

import math
def infinite_sin_1(x):
	iterations = int(raw_input('Enter the number of sine terms to add up: '))
	total = 0
	for n in range(0,iterations):
		# we need the range from 0 to iterations
		# iterations being the number the user types in above
		term = math.pow(-1,n)/math.factorial(2*n+1)*math.pow(x,2*n+1)
		# we set term as the taylor series of sine
		total += term
		# then we add the term to the total
	return total

def infinite_cos_1(x):
	iterations = int(raw_input('Enter the number of cosine terms to add up: '))
	total = 0
	for n in range(0,iterations):
		term = math.pow(-1,n)/math.factorial(2*n)*math.pow(x,2*n)
		#code is the same as sine, just a slightly different equation in term
		total += term
		

	return total

	
# here is where you can test your code

x = math.pi/3	
real_sine = math.sin(x)
real_cosine = math.cos(x)
my_inf_sin_1 = infinite_sin_1(x)		
my_inf_cos_1 = infinite_cos_1(x)

# print the answers out to 25 digits after the decimal, to inspect them

print 'real sine:', "%0.25f" % real_sine
print 'my sine 1:', "%0.25f" % my_inf_sin_1			
print 'my sine is accurate to:', "%0.25f" % math.fabs(real_sine-my_inf_sin_1) 
print 'real cosine:', "%0.25f" % real_cosine
print 'my cosine 1:', "%0.25f" % my_inf_cos_1			
print 'my cosine is accurate to:', "%0.25f" % math.fabs(real_cosine-my_inf_cos_1)
