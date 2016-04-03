import math
primes = [2]

def isPrime(n):
	i=0
	while primes[i]<int(math.sqrt(n)+1):
		if n%primes[i]==0:
			return False
		i += 1
	return True

sum = 2
k=3
while k<2000000:
	if isPrime(k):
		primes.append(k)
		sum += k
	k += 1
print(sum)
