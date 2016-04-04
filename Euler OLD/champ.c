#include <stdio.h>
#include <math.h>

int firstDig(int n){
	int temp=n;
	while(temp>10){
		temp /= 10;
	}
	return temp;
}

int reverse(int n){
	int ret=0;
	int temp = n;
	int pwr=0;
	while(temp>0){
		ret += (temp%10) * pow(10, (int)log10(n)-pwr);
		temp /= 10;
		pwr++;
	}
	return ret;
}

int chopFirst(int n){
	return n - firstDig(n)*(int)pow((double)10, (int)log10((double)n));
}

int main(){
	int t = 12345;
	printf("%d", reverse(t));
	return 0;
}