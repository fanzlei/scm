/*
����: ��˸��LED��
��·����������P2���ѽӵ�LED�Ƶ�����
*/


#include <reg52.h>
#include "led2.h"
#include "sys.h"

void led2(){
	int i;
	while(1){
		//����P2.0��Ϊ�͵�ƽ�����ӵ��ÿڵ�LED�Ƶ���
		//0xfe ====   1111 1110
		P2 = 0xfe;
		for(i=0;i<10000;i++);//��ʱһ��ʱ��
		P2 = 0xff;
		for(i=0;i<10000;i++);//��ʱһ��ʱ��
	}
	
	
}
