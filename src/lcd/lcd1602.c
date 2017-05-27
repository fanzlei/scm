/*
LCD1602Һ����ʾ
ʹ��HC6800 ES�����壬MS����ʾ����
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

//��æ�������α��ϵĴ���û����æ�����޷���ʾ����
//1602Ӳ���涨:RS = 0,RW = 1ʱ���Զ���æ�ź�,D7=1Ϊæ,D7=0��æ
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
	RW = 0;//0����д��1�����
	RS = 0;//0�������1��������
	
	E = 1;//Һ��ʹ��
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
	
	
	E = 1;//Һ��ʹ��
	for(m-0;m<=2;m++);
	LCD = c;
	for(m-0;m<=2;m++);
	E = 0;
}

//Һ����ʼ��
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