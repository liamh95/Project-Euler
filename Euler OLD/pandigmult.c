#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long conc(int *nums){//num[0]= # of numbers following it
	long ret = 0;
	int i;
	int pwr=0;
	for(i=nums[0]; i>1; i--){//over nums
		int temp = nums[i];
		while(temp>0){
			pwr++;
			temp /= 10;
		}
		ret += nums[i-1]*(int)pow((double)10,(double)pwr);
	}
	ret += nums[nums[0]];
	return ret;
}

int isPandig(int n){
	int temp=n;
	int digs[10];//Settin up digits
	int i;
	for(i=0; i<10; i++)
		digs[i]=0;
	i=0;
	while(temp>0){
		if(temp%10==0)
			return 0;
		if(digs[temp%10]!=0)
			return 0;
		digs[temp%10]++;
		temp /= 10;
		i++;
	}
	return (i==9)?1:0;
}

long concProd(int n, int size){
	int i;
	int list[size+1];
	list[0]=size;
	for(i=1; i<=size; i++)
		list[i]=n*i;
	return conc(list);
}

int main(){
	
	unsigned int largest = 0;
	int num;
	int lst;
	int i;
	for(i=2; i<50000; i++){
		unsigned int test=0;
		int j=2;
		while(test<=987654321){
			test = concProd(i,j);
			if(isPandig(test)&&test>largest){
				largest=test;
				num=i;
				lst=j;
			}
			j++;
		}
	}
	printf("%i & %i: %i", num, lst, largest);
	return 0;
}