
#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
#define nop() _nop_()
uchar code table1[]={0x03,0x06,0x0c,0x09}; /*???*/
uchar code table2[]={0x03,0x09,0x0c,0x06}; /*???*/
#define motor P0
void delay(uchar ms) /*??*/
{
uchar j;
while(ms--){
for(j=0;j<250;j++)
{;}
}
} 
void step_motor()
{
uchar i,j;
while(1){
//?? 3 ?? 192 ???
j=0;
for(i=0;i<192;i++){
motor = 0x00;
motor = table1[j];
j++;
if(j>=4) j=0;
delay(2);
}
delay(200);
delay(200);
delay(200);
delay(200);
delay(200);
}
} 