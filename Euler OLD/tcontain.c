#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Vectors

double getMag(int *v){
	return sqrt( pow((double)v[0], 2) + pow((double)v[1], 2) );
}

double getAngle(int *u, int *v){
	int dot =0;
	int i;
	for(i=0; i<2; i++)
		dot += u[i]*v[i];
	return acos((double)dot / (getMag(u)*getMag(v)) );
}

int main(){
	FILE *triangles;
	triangles = fopen("triangles.txt", "r");
	char buff[50], *ptr;
	int A[6];
	int contain=0;
	int p;
	for(p=0; p<1000; p++){
		int q=0;
		while(fgets(buff, sizeof buff, triangles) && q<6){
			A[q] = (int)strtol(ptr, &ptr, 10);
			q++;
		}
		if(p==0){
			int b;
			for(b=0; b<6; b++)
				printf("%d, ", A[b]);
		}
		//iterate over verticies
		int bad=0;
		int j;
		for(j=0; j<3 && bad==0; j++){
			//make vectors
			int u[2] = {A[(2*(j+1))%6]-A[(2*j)%6], A[((2*(j+1))%6)+1]-A[((2*j)%6)+1]};//vertex_i to vertex_(i+1)
			int v[2] = {A[(2*(j+2))%6]-A[(2*j)%6], A[((2*(j+2))%6)+1]-A[((2*j)%6)+1]};//vertex_i to vertex_(i+2)
			int w[2] = {-1*A[(2*j)%6], -1*A[((2*j)%6)+1]};//vertex_i to origin

			bad = ( (getMag(w)<getMag(u) && getMag(w)<getMag(v)) && (getAngle(u,w)<getAngle(u,v) && getAngle(v,w)<getAngle(u,v)) ) ? 0 : 1;
		}
		contain += (bad==0) ? 1: 0;
	}
	return 0;
}