/*
黄盒子
按键控制数码管的显示内容
*/


#include <reg52.h>
#include "key2.h"
#include "sys.h"
#include "digital_pile.h"

sbit K5 = P3^5;
unsigned char num;
unsigned char n4;

//K5按键每按一次，显示内容加1
void key2(){
	num=0;
	while(1){
		if(K5 == 0){
			delay();
			if(K5 == 0){
				num++;
				n4 = num%10;
			}
		}
		digital_pile_show_number(10,10,10,n4);
		delays(100);
	}
	

}