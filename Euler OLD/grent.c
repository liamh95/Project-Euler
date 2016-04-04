#include <stdio.h>
int main(){
	int sols=0;
	int d1,d2,d3,d4;
	for(d1=0; d1<10; d1++){
		for(d2=0; d2<10; d2++){
			for(d3=0; d3<10; d3++){
				for(d4=0; d4<10; d4++){
					if(d1+d2-d3-d4<10 && d1+d2-d3-d4>=0)
						sols++;
				}
			}
		}
	}
	printf("%d solutions", sols);
}