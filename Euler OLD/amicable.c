#include <stdio.h>

int main(){

	unsigned int i;
	int d[10001];
	int amici=0;
	for(i=1; i<10001; i++){
		int j;
		for(j=1; j<(i/2)+1; j++){
			d[i] += (i%j==0)?j:0;
		}
		if(d[i]<i && d[d[i]]==i)
			amici += d[i]+i;
	}

	printf("%d",amici);

	return 0;
}