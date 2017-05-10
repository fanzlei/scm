/*
标题: 点亮一个了LED灯
电路：开发板中P2口已接到LED灯的阴极

*/


#include <reg52.h>
#include "led1.h"

void led1(){
	//设置P2.0口为低电平，连接到该口的LED灯点亮
	//0xfe ====   1111 1110
	P2 = 0xfe;
}
