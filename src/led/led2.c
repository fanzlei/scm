/*
标题: 闪烁的LED灯
电路：开发板中P2口已接到LED灯的阴极
*/


#include <reg52.h>
#include "led2.h"
#include "sys.h"

void led2(){
	int i;
	while(1){
		//设置P2.0口为低电平，连接到该口的LED灯点亮
		//0xfe ====   1111 1110
		P2 = 0xfe;
		for(i=0;i<10000;i++);//延时一段时间
		P2 = 0xff;
		for(i=0;i<10000;i++);//延时一段时间
	}
	
	
}
