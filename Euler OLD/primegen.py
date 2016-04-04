#
#	Creates a csv for first million primes
#	100 cols. Check primality by iterating through current list of primes
#	Start by generating the first 150 with a naive sieve.

import math, csv

primes = open("primes.csv", "r+")
writer = csv.writer(primes, delimiter = ",")

ROWSIZE=200
MAX=664600

#	First chunk of primes
p=2
lst = []
while len(lst)<ROWSIZE:
	if p==2:
		lst.append(p)
	else:
		i=0
		good = True
		while i<len(lst) and lst[i]<=math.ceil(math.sqrt(p)) and good==True:
			good = False if p%lst[i]==0 else True
			i=i+1
		if good==True:
			lst.append(p)
	p = 3 if p==2 else p+2

largest = lst[ROWSIZE-1]
writer.writerow(lst)
primes.close()

# moar primes
written=1
p=largest+2
while written<MAX/ROWSIZE:
	nuRow=[]
	while len(nuRow)<ROWSIZE:
		dead=False
		primes = open("primes.csv", "r+")
		writer = csv.writer(primes, delimiter = ",")
		reader = csv.reader(primes, delimiter = ",")
		for row in reader:
			i=0
			good=True
			while i<ROWSIZE and int(row[i])<=int(math.ceil(math.sqrt(p))) and good==True:
				good = False if p%int(row[i])==0 else True
				i=i+1
			if good==False:
				dead=True
				break
		if dead==False:
			nuRow.append(p)
		p=p+2
	writer.writerow(nuRow)
	if(written%5==0):
		print written*200
	written = written+1
primes.close()