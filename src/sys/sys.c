/*
����: ϵͳ���ù��ߺ���
*/



void delay(){
	int i = 10000;
	while(i--);
}
void delays(int d){
	while(d--);
}


/*
*ʹ��12MHz���񣨻�������Ϊ1us�����ӳ�
*/
void delay_ms(unsigned int ms)
{
    unsigned int i = 1000;
		while(ms--){
			while(i--);
		}
}