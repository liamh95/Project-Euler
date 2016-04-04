#include <stdio.h>
#include <math.h>
#define MAX 28124

int abundance(int n){
	int sum=1;
	int i;
	for(i=2; i<n; i++){
		if(n%i==0)
			sum += i;
	}
	if(n==1)
		return -1;
	else if(sum<n)
		return -1;
	else if(sum>n)
		return 1;
	return 0;
}

int main(){
	/* D: 21167
	   P: 3
	   A: 6953*/
	int uau[MAX];
	int jsus[MAX];
	int i;
	for(i=1; i<MAX; i++){
		uau[i]=abundance(i);
		if(uau[i]==1){
			int j;
			for(j=1; j<=i && i+j<MAX; j++){
				if(uau[j]==1)
					jsus[i+j]=1;
			}
		}
	}
	int hng = 395465626;
	for(i=1; i<MAX; i++){
		if(jsus[i]==1)
			hng -= i;
	}
	printf("%i", hng);
	return 0;
}