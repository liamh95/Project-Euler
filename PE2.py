sum=0; twoBack=1; oneBack=1;
while oneBack<4000000:
	newNum = oneBack+twoBack
	twoBack=oneBack
	oneBack=newNum
	if newNum%2==0:
		sum+= newNum
print sum