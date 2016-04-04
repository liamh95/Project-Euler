#include <stdio.h>
#include <math.h>

int isPal(int n, int* dup){
	if( n>=0 && n<10 )//1dig
		return (n==(*dup)%10);
	if(!isPal(n/10, dup)){
		return 0;
	}
	*dup/=10;
	return (n%10==(*dup)%10);
}

int palindrome(int n){
	int *d = &n;
	return isPal(n, d);
}

int main(){
	int test = 1000;

	printf("%i: %i.", test, palindrome(test));

	return 0;
}