/*
����ܵ���ʾ���
��·��һ����ƺ��ӣ�������������P0�ڽӹ�������ܵĶ�ѡ�ˣ�P1�ڵ�0123�ֱ������ܵ�λѡ��

*/

#include <reg52.h>
#include "sys.h"
#include "digital_pile.h"

int duan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int wei[]={0x01,0x02,0x04,0x08};

//��̬�������ʾ
void static_pile(unsigned char number){
	if(number <= 9)
	 P3 = duan[number];
}

//��̬�������ʾ
void digital_pile(){
	int i;
	while(1){
		for(i=0;i<4;i++){
			P1 = wei[i];//ѡ��ĳ�������
			P0 = duan[i];//ѡ����������ʾ
			delays(50);
		}
	}
}