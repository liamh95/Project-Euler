import math
primes = [2]
def isPrime(n):
	i=0
	while primes[i]<int(math.sqrt(n)+1):
		#print("Testing n=%i with p=%i" % (n, p))
		if n%primes[i]==0:
			return False
		i+=1
	return True

i=3
while(len(primes)<10001):
	if isPrime(i):
		primes.append(i)
	i+= 2
print primes[10000]
