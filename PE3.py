import math
primes = [2]
factorization = [1]
product=1
largest = 1

def isPrime(n):
	for p in primes:
		#print("Testing n=%i with p=%i" % (n, p))
		if n%p==0:
			return False
	return True

i=3
while product<600851475143 and i<int(math.sqrt(600851475143) ):
	#print("testing %i" % (i))
	if isPrime(i):
		primes.append(i)
		if 600851475143%i==0:
			factorization.append(i)
			#how hard does it divide?
			tmp = 600851475143/i
			while i%tmp==0:
				factorization.append(i)
				tmp /= i
			largest = i
	i += 2
	temp=1
	for p in factorization:
		temp *= p
	product = temp
print largest

