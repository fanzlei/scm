/*
����: ����һ����LED��
��·����������P2���ѽӵ�LED�Ƶ�����

*/


#include <reg52.h>
#include "led1.h"

void led1(){
	//����P2.0��Ϊ�͵�ƽ�����ӵ��ÿڵ�LED�Ƶ���
	//0xfe ====   1111 1110
	P2 = 0xfe;
}