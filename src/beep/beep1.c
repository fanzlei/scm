/*
���⣺��������ʹ��
��·��P1.0�ڽ�P11

*/
#include "sys.h"
#include <reg52.h>
#include "beep1.h"

sbit beez = P2^1;
void beep1(){
	while(1){
		beez = 1;
		delays(100);
		beez = 0;
		delays(100);
	}
}