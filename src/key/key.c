/*
��������
��·��һ����ƺ��ӣ�P1��4567�ֱ�Ӱ���1234

*/
#include <reg52.h>
#include "sys.h"
#include "key.h"

#define LED P2//P2��led�Ƶ�����

sbit K1 = P1^4;
sbit K2 = P1^5;
sbit K3 = P1^6;
sbit K4 = P1^7;
sbit K5 = P3^5;


void key(){
	LED = 0xff;//led��Ϩ��
	while(1){
		if(K1 == 0){
			delays(100);
			if(K1 == 0){
				LED = 0xfe;//��һ���Ƶ���
			}
			//�ɿ��������Ϩ��
			/*else{
				LED = 0xff;
			}*/
		}
		
		if(K2 == 0){
			delays(100);
			if(K2 == 0){
				LED = 0xfd;//�ڶ����Ƶ���
			}
		}
		
		if(K3 == 0){
			delays(100);
			if(K3 == 0){
				LED = 0xfb;//�������Ƶ���
			}
		}
		
		if(K4 == 0){
			delays(100);
			if(K4 == 0){
				LED = 0xf7;//���ĸ��Ƶ���
			}
		}
	
		if(K5 == 0){
			delays(100);
			if(K5 == 0){
				LED = 0xef;//������Ƶ���
			}
		}
	}
}
	
//�������ɨ��
void matrix_key(){
	
	
}