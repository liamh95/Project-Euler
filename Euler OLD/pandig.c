#include <stdio.h>

int main(){
	int i;
	int sum=0;
	int digs[10] = {0,0,0,0,0,0,0,0,0,0};
	int prods[9999];
	for(i=0; i<9999; i++)
		prods[i]=0;
	for(i=2; i<100; i++){
		int j;
		int jb=(i>9)?123:1234;
		int je=10000/i+1;
		//multiplications
		for(j=jb;j<je;j++){
			//reset digits
			int k;
			for(k=0; k<10; k++)
				digs[k]=0;
			int prod = i*j;
			int it=i;
			int jt=j;
			//check digits
			while(it>0){
				digs[it%10]++;
				it /= 10;
			}
			while(jt>0){
				digs[jt%10]++;
				jt /= 10;
			}
			while(prod>0){
				digs[prod%10]++;
				prod /= 10;
			}
			k=1;
			while(k<10 && digs[k]==1){
				k++;
			}
			//sum += (k==10 && prods[i*j-1]==1) ? i*j : 0;
			if(k==10 && prods[i*j-1]==0){
				prods[i*j-1]=1;
				sum += i*j;
			}
		}
	}
	printf("%i",sum);

	return 0;
}