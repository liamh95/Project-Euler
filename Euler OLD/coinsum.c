#include <stdio.h>

int gcd ( int a, int b ){
	int c;
	while ( a != 0 ){
	c = a; a = b%a;  b = c;
	}
	return b;
}

int lgcd(int ls[], int nos){
	int ret=ls[0];
	int i;
	for(i=1; i<nos; i++)
		ret=gcd(ret,ls[i]);
	return ret;
}

int lcm(int a, int b){
	return a / gcd(a,b) * b;
}

void bezout(int a, int b, int *u, int *v){
	int q;
	if(b==0){
		*u=1;
		*v=0;
	}
	else{
		q=a/b;
		bezout(b,a%b, u, v);
		int temp = (*u) - (*v)*q;
		*u=*v;
		*v=temp;
	}
}

/*
coeffs: coefficients
solve: RHS
1. Divide through by GCD(coeffs) (sol to coprime equation = sol to original)
2. Solve babby diophantine to get top left corner = solve/gcd
*/
void dio(int coeffs[], int vars, int solve, int matrix[vars][vars+1] ){
	if(1){
		printf("Valid!\n");
		int geeceedee = lgcd(coeffs,vars);
		if( solve % geeceedee == 0 ){
			printf("Solutions!\n");
			int i;
			int coprimes[vars];
			for(i=0; i<vars; i++){//coeffs NOW COPRIME. NOW SOLVING FOR solve/geeceedee
				coprimes[i]=coeffs[i]/geeceedee;
				matrix[i][0]=coprimes[i];
			}
			for(i=0; i<vars; i++){//1s n 0s
				int j;
				for(j=1; j<vars+1; j++)
					matrix[i][j] = (j==i+1) ? 1 : 0;
			}
			//SOLVING SHIT (COPRIME MATRIX)//
			int g=1;
			i=1;
			while((solve/geeceedee) % gcd(coprimes[0],coprimes[i]) != 0){//finds coeff[i]: coeff[0]x + coeff[i]y=solve has sol
				i++;
			}
			g=i;
			int d=(solve/geeceedee)/gcd(coprimes[0], coprimes[g]/geeceedee);
			int u, v;
			bezout(coprimes[0], coprimes[g],&u,&v);
			u *= d;//coeff[0]u + gv = solve;
			v *= d;
			for(i=0; i<vars+1; i++)//puts solve in top corner
				matrix[0][i] = (u*matrix[0][i]) + (v*matrix[g][i]);
			for(i=1; i<vars; i++){//elim row with top row
				int j;
				int fact = lcm(coprimes[i], matrix[0][0]);
				for(j=0; j<vars+1; j++){
					matrix[i][j] = (fact/coprimes[i])*matrix[i][j] -  (fact/matrix[0][0])*matrix[0][j];
				}
			}
		}
		//No Solution
		else{
			printf("No solution!\n");
		}
	}
	//Bad input
	else{
		printf("Bad input!\n");
	}
}
/*


*/
int main(){
	int coins[] = {1,1,-1,-1,2};
	int size=4;
	int s = 0;
	int mat[size][size+1];
	dio(coins,size,s,mat);
	
	int i;
	for(i=0; i<size; i++){
		int j;
		for(j=0; j<size+1; j++)
			printf("%i ", mat[i][j]);
		printf("\n");
	}
	return 0;
}