/*
标题：蜂鸣器发出不同的音调
电路：p2.1口接P11

*/

#include <reg52.h>
#include "sys.h"
#include "beep2.h"
sbit beez = P2^1;

void beep2(){
	int i;
	while(1){
	for(i = 0;i<1000;i++){
			beez = 0;
			delays(100);
			beez = 1;
			delays(100);
		}
		
		for(i = 0;i<1000;i++){
			beez = 0;
			delays(200);
			beez = 1;
			delays(200);
		}
		
		for(i = 0;i<1000;i++){
			beez = 0;
			delays(50);
			beez = 1;
			delays(50);
		}
		
		for(i = 0;i<1000;i++){
			beez = 0;
			delays(150);
			beez = 1;
			delays(150);
		}
	
	}
		

}

