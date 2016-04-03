a=0; b=0; c=1; found = 0;
while found==0 and a<1000/3:
	a += 1
	b=a
	while found==0 and b<500:
		b += 1
		c=1000-a-b
		if  a*a+b*b==c*c:
			found=1
prod = a*b*c
print(prod)
