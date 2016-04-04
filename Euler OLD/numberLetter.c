#include <stdio.h>

int one, two, six, ten, et = 3;
int four, five, nine, teen = 4;
int three, seven, eight, fifty, sixty = 5;
int eleven, twelve, twenty, thirty, fourty, eighty, ninety = 6;
int fifteen, sixteen, seventy, hundred = 7;
int thirteen, fourteen, nineteen, thousand = 8;
int seventeen, eighteen = 9;

int main(){
	int words=0;
	/*int i;
	for(i=1; i<1001; i++){
		//1
		if(i%10==1 && (i/10)%10!=1)
			words +=one;
		//2
		if(i%10==2 && (i/10)%10!=1)
			words +=two;
		//3
		if(i%10==3 && (i/10)%10!=1)
			words += 3;
		//4
		if(i%10==3 && (i/10)%10!=1)
			words += 3;
	}*/
	//last digits 1,2,6
	words += 3*90*one + 300;
	//last digits 4,5,9
	words += 3*90*four + 300;
	//last digits 3,7,8
	words += 3*90*three + 300;
	//10
	words += 10*ten;
	//11,12
	words += 2*10*eleven;
	//13,14,19
	words += 3*10*thirteen;
	//15,16
	words += 2*10*fifteen;
	//17,18
	words += 2*10*seventeen;
	//20,30,40,80,90
	words += 5*100*twenty;
	//50,60
	words += 2*100*fifty;
	//70
	words += 100*seventy;
	//100
	words += 899*hundred;
	//and
	words += 890*et;
	//1000
	words += thousand + one;

	printf("%i", words);

	return 0;
}