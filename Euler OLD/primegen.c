#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int ROW_SIZE=200;
const int MAX=664600;

int* strtoi(char* str){
	int found=0;
	int* ret = malloc(sizeof(int)*(5));
	int i=0;
	while(found<5){
		char temp[6];
		int j=0;
		while(str[i]!=' '){
			temp[j]=str[i];
			i++;
			j++;
		}
		ret[found]=atoi(temp);
		found++;
	}
	return ret;
}

int main(){
	/*FILE *f = fopen("cprimes.csv", "r");
	int p=2;
	int [ROW_SIZE] lst;

	//get the first ROW_SIZE primes
	int i=0;
	while(i<ROW_SIZE){
		if(p==2){
			lst[i]=p;
			i++;
			p++;
		}
		else{
			int j=0;
			int good=1;
			while(j<i && j<=(int)ceil(sqrt((double)p)) && good==1 ){
				good = (p%lst[j]==0) ? 0 : 1;
				j++;
			}
			if(good==1){
				lst[i]=p;
				i++;
			}
			p+=2;
		}
	}

	int largest = lst[ROW_SIZE-1];
	//Write first row to file
	for(i=0; i<ROW_SIZE; i++){
		fprintf(f, "%d ", lst[i]);
	}
	fprintf(f, "\n");
	fclose(f);

	//hard part
	int rowsWritten=1;
	p=largest+2;
	while(rowsWritten<MAX/ROW_SIZE){
		i=0;
		while(i<ROW_SIZE){
			int dead=0;
			f = fopen("cprimes.csv", "r");
			int j=0;
			while(j<rowsWritten){

			}
		}
	}*/
	char* teststr = "1 2 3 4 5";
	int* formattest = strtoi(teststr);
	int i;
	for(i=0;i<5;i++)
		printf("%d ", formattest[i]);
	return 0;
}