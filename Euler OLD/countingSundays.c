#include <stdio.h>

int main(){
	int month, week, year, suns;
	
	week=3;//1Sun 2Mon etc
	for(year=1901; year<2001; year++){
		for(month=1; month<13; month++){
			if(week==1)
				suns++;
			
			if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
				week = (week+31)%7;
			else if(month==4 || month==6 || month==9 || month==11)
				week = (week+30)%7;
			else{
				if(year%4==0)
					week = (week+29)%7;
				else
					week = (week+28)%7;
			}
		}
	}
	printf("%d",suns);
	return 0;
}