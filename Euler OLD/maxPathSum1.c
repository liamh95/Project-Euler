#include <stdio.h>

int main(){
	FILE *triangle;
	triangle = fopen("triangle.txt", "r");
	int data[100][100];
	int i;
	for(i=0; i<100; i++){
		int j;
		for(j=0; j<i+1; j++)
			fscanf(triangle, "%d", &data[i][j]);
	}
	fclose(triangle);

	for(i=98; i>=0; i--){
		int j;
		for(j=0; j<i+1; j++){
			if(data[i+1][j]>data[i+1][j+1])
				data[i][j]+=data[i+1][j];
			else
				data[i][j]+=data[i+1][j+1];
		}
	}

	printf("%d",data[0][0]);
	return 0;
}
