/*
标题: 流水灯
电路：开发板中P2口已接到LED灯的阴极
*/


#include "led3.h"

static unsigned char coded[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
static void fun1();
static void fun2();
static void fun3();

void led3(){
		fun3();
}

//使用数组的方式
void fun1(){
	
	int i;
	while(1){
		for(i=0;i<8;i++){
			P2 = coded[i];
			delay();
		}
		for(i=6;i>=0;i--){
			P2 = coded[i];
			delay();
		}
	}
}


//使用指针的方式
void fun2(){
	int i;
	while(1){
		for(i=0;i<8;i++){
			P2 = *(coded+i);
			delay();
		}
		for(i=7;i>=0;i--){
			P2 = *(coded+i);
			delay();
		}
	}
}


//使用位移运算
void fun3(){
	unsigned char i;
	unsigned char state = 0xfe;
	while(1){
		state = 0xfe;
		P2 = state;
		delay();
		for(i=0;i<7;i++){
			state = (state<<1)|0x01;
			P2 = state;
			delay();
		}
		for(i=0;i<7;i++){
			state = (state >> 1)|0x80;
			P2 = state;
			delay();
		}
	}
}


