/*
独立按键
电路：一代版黄盒子：P1的4567分别接按键1234

*/
#include <reg52.h>
#include "sys.h"
#include "key.h"

#define LED P2//P2接led灯的阴极

sbit K1 = P1^4;
sbit K2 = P1^5;
sbit K3 = P1^6;
sbit K4 = P1^7;
sbit K5 = P3^5;


void key(){
	LED = 0xff;//led灯熄灭
	while(1){
		if(K1 == 0){
			delays(100);
			if(K1 == 0){
				LED = 0xfe;//第一个灯点亮
			}
			//松开按键后灯熄灭
			/*else{
				LED = 0xff;
			}*/
		}
		
		if(K2 == 0){
			delays(100);
			if(K2 == 0){
				LED = 0xfd;//第二个灯点亮
			}
		}
		
		if(K3 == 0){
			delays(100);
			if(K3 == 0){
				LED = 0xfb;//第三个灯点亮
			}
		}
		
		if(K4 == 0){
			delays(100);
			if(K4 == 0){
				LED = 0xf7;//第四个灯点亮
			}
		}
	
		if(K5 == 0){
			delays(100);
			if(K5 == 0){
				LED = 0xef;//第五个灯点亮
			}
		}
	}
}
	
//矩阵键盘扫描
void matrix_key(){
	
	
}