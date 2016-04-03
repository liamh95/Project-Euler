def isPalindrome(n):
	strn = str(n)
	return True if strn==strn[::-1] else False

largest = 1
for i in range(100, 1000):
	for j in range(i, 1000):
		test = i*j
		if test>largest and isPalindrome(test):
			largest = test
print largest