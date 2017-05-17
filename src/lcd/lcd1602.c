/*
LCD1602液晶显示
使用HC6800 ES开发板，MS不显示内容
*/
#include <reg51.h>
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

//????,??????????,LCD?????
//??????:RS = 0,RW = 1????????,D7=1??,D7=0???
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
	RW = 0;//0???,1???
	RS = 0;//0????,1????
	LCD = cmd;
	for(m-0;m<=2;m++);
	E = 1;//????
	for(m-0;m<=2;m++);
	E = 0;//????
}

void writeData(uchar c){
	uchar m;
	while((Busy_Check()&0x80)==0x80);
	RW = 0;
	RS = 1;
	LCD = c;
	for(m-0;m<=2;m++);
	E = 1;//????
	for(m-0;m<=2;m++);
	E = 0;//????
}

//?????,?????????,???
void init(){
	RW = 0;//??????
	E = 0;//????
	writeCMD(0x38);
	writeCMD(0x0c);
	writeCMD(0x06);
	writeCMD(0x01);
	writeCMD(0x80);
}

void clear(void)//LCD??
{
  while((Busy_Check()&0x80)==0x80);
  RS=0;
  RW=0;
  P0=0x01;
  E=1;
  E=0; 
}

void show_char(uchar row,uchar column,uchar c){
	uchar m;
	writeCMD(0x80+row*0x40+column);//???,?????
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