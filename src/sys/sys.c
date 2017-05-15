/*
标题: 系统常用工具函数
*/



void delay(){
	int i = 10000;
	while(i--);
}
void delays(int d){
	while(d--);
}


/*
*使用12MHz晶振（机器周期为1us），延迟
*/
void delay_ms(unsigned int ms)
{
    unsigned int i = 1000;
		while(ms--){
			while(i--);
		}
}