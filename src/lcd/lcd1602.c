/*
LCD1602液晶显示
使用HC6800 ES开发板，MS不显示内容
*/
#include <reg52.h>
#include <stdio.h>
#define uchar unsigned char
#define uint unsigned int
#define LCD P0
sbit RS = P2^6;
sbit RW = P2^5;
sbit E = P2^7;

uchar code tab[] = {"hello 137"};

void Delayms(uint ms)
{
 	uchar i;
	while(ms--)
	{
	 	for(i=0;i<120;i++);
	}
}

//判忙函数，课本上的代码没有判忙，故无法显示内容
//1602硬件规定:RS = 0,RW = 1时可以读出忙信号,D7=1为忙,D7=0不忙
uchar Busy_Check()
{
 	uchar LCD_Status;
	RS = 0;
	RW = 1;
	E = 1;
	Delayms(1);
   	LCD_Status = LCD;
	E = 0;
	return LCD_Status;
}

void writeCMD(uchar cmd){
	uchar m;
	while((Busy_Check()&0x80)==0x80);
	RW = 0;//0代表写，1代表读
	RS = 0;//0代表命令，1代表数据
	
	E = 1;//液晶使能
	for(m-0;m<=2;m++);
	LCD = cmd;
	
	for(m-0;m<=2;m++);
	E = 0;
}

void writeData(uchar c){
	uchar m;
	while((Busy_Check()&0x80)==0x80);
	RW = 0;
	RS = 1;
	
	
	E = 1;//液晶使能
	for(m-0;m<=2;m++);
	LCD = c;
	for(m-0;m<=2;m++);
	E = 0;
}

//液晶初始化
void init(){
	RW = 0;
	E = 0;
	writeCMD(0x38);
	writeCMD(0x0c);
	writeCMD(0x06);
	writeCMD(0x01);
	writeCMD(0x80);
}


void show_char(uchar row,uchar column,uchar c){
	uchar m;
	writeCMD(0x80+row*0x40+column);
	for(m=0;m<252;m++);
	writeData(c);
}
void lcd1602(void)
 { 
	 uchar i;
	 init();
	 for(i=0;i<9;i++){
		show_char(0,i,tab[i]);
	 }
	 while(1);
 }