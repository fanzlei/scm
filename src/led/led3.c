/*
����: ��ˮ��
��·����������P2���ѽӵ�LED�Ƶ�����
*/


#include "led3.h"

static unsigned char coded[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
static void fun1();
static void fun2();
static void fun3();

void led3(){
		fun3();
}

//ʹ������ķ�ʽ
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


//ʹ��ָ��ķ�ʽ
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


//ʹ��λ������
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


