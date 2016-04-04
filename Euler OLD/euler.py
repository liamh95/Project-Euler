import math
def isPrime(n):
	for i in range(2,int(math.sqrt(n))+1):
		if n%i==0:
			return False
	return True

def triangle(n):
	return int(n*(n+1) / 2)

divs=0
trying=500
while(divs<20):
	trying += 1
	divs=2
	test=triangle(trying)
	for i in range(1,int(test/2)):
		if test%i==0:
			divs +=1
	print(str(test) + " " + str(divs))

print(triangle(trying))
