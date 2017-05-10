/*
数码管的显示输出
电路：一代版黄盒子，开发板中内置P0口接共阴数码管的段选端，P1口的0123分别接数码管的位选端

*/

#include <reg52.h>
#include "sys.h"
#include "digital_pile.h"

int duan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int wei[]={0x01,0x02,0x04,0x08};

//静态数码管显示
void static_pile(unsigned char number){
	if(number <= 9)
	 P3 = duan[number];
}

//动态数码管显示
void digital_pile(){
	int i;
	while(1){
		for(i=0;i<4;i++){
			P1 = wei[i];//选择某个数码管
			P0 = duan[i];//选择的数码管显示
			delays(50);
		}
	}
}