/*
���⣺�̵�������
��·��HC6800V3�汾����������м̵�����P2.1�ڽ�J2
*/

#include <reg52.h>
#include "relay.h"
#include "sys.h"
//ʹ���ຯ���꣬��ǰѧ���ģ�����������ַ��滻������DO���൱����RELAY=~RELAY
#define DO RELAY=~RELAY
sbit RELAY = P2^1;

//ÿ��һ��ʱ��̵�������һ��
void relay(){
		while(1){
			//DO;//�൱��: RELAY=~RELAY;
			RELAY=~RELAY;
			delays(50000);
		}
}