#include <stdio.h>
#include <stdlib.h>

int isPandig(int test, int n){//is test n-pandig?
	int *digs = malloc(sizeof(int)*n);
	int i;
	for(i=0; i<n; i++)
		digs[i]=0;
	int temp=n;
	while(temp>0){
		digs[temp%10]++;
		temp /= 10;
	}
	i=0;
}