/*
标题：继电器控制
电路：HC6800V3版本开发板才配有继电器，P2.1口接J2
*/

#include <reg52.h>
#include "relay.h"
#include "sys.h"
//使用类函数宏，以前学过的，宏的作用是字符替换，这里DO就相当于是RELAY=~RELAY
#define DO RELAY=~RELAY
sbit RELAY = P2^1;

//每隔一段时间继电器开关一次
void relay(){
		while(1){
			//DO;//相当于: RELAY=~RELAY;
			RELAY=~RELAY;
			delays(50000);
		}
}