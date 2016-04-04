#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIST_SIZE 5163
#define MAX_NAME_LEN 20

void merge(char *A[], char *B[], int begin, int mid, int end){
	int i, leftEnd, elements, temp;

	leftEnd=mid-1;
	temp=begin;
	elements=end-begin+1;

	while((begin<=leftEnd) && (mid<=end)){
		if(strcmp(A[begin], A[mid])<=0){
			B[temp] = (char*)malloc(sizeof(char)*(strlen(A[begin])));
			strcpy(B[temp], A[begin]);
			temp++;
			begin++;
		}
		else{
			B[temp] = (char*)malloc(sizeof(char)*(strlen(A[mid])));
			strcpy(B[temp], A[mid]);
			temp++;
			mid++;
		}
	}

	while(begin <= leftEnd){
		B[temp] = (char*)malloc(sizeof(char)*(strlen(A[begin])));
		strcpy(B[temp], A[begin]);
		begin++;
		temp++;
	}

	while(mid<=end){
		B[temp] = (char*)malloc(sizeof(char)*(strlen(A[mid])));
		strcpy(B[temp], A[mid]);
		mid++;
		temp++;
	}

	for(i=0; i<=elements; i++){
		A[end] = (char*)malloc(sizeof(char)*(strlen(B[end])));
		strcpy(A[end], B[end]);
		end--;
	}
}

void split(char *A[], char *B[], int begin, int end){
	int mid;
	if(end > begin){
		mid = (begin + end) / 2;
		split(A, B, begin, mid);
		split(A, B, mid+1, end);

		merge(A, B, begin, mid+1, end);
	}
}

int score(char *name){
	int i;
	int score=0;
	for(i=0; i<strlen(name); i++)
		score += name[i] - 64;
	return score;
}

void mergeSort(char *list[], char *temp[], int size){
	split(list, temp, 0, size-1);
}

int main(){
	FILE *names;
	names = fopen("names.txt", "r");
	char buff[MAX_NAME_LEN];

	char *lst[LIST_SIZE];
	char *tmp[LIST_SIZE];

	int i;
	for(i=0; i<LIST_SIZE; i++){
		fgets(buff, MAX_NAME_LEN, names);
		lst[i]=(char*)malloc(sizeof(char)*(strlen(buff)+1));
		strcpy(lst[i], buff);
	}
	fclose(names);

	mergeSort(lst, tmp, LIST_SIZE);
	int ret=0;
	for(i=0; i<LIST_SIZE; i++)
		ret += score(lst[i])*(i+1);
	printf("%s", lst[0]);

	return 0;
}