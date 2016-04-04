#include <stdio.h>

int isBouncy(int n){
	int inc=0;
	int dec=0;
	int last=n%10;
	int temp=n/10;
	while(temp>0){
		if(temp%10>last)
			inc=1;
		else if(temp%10<last)
			dec=1;
		last = temp%10;
		temp /=10;
	}
	return(inc==1 && dec==1) ? 1 : 0;
}

int main(){
	int bounces=0;
	int i=99;
	while( !( (99*i)%100==0 && (99*i)/100==bounces ) ){
		i++;
		bounces += isBouncy(i) ? 1:0;
	}
	printf("%d", i);
}