

#include "sys.h"
#include "digital_pile.h"

unsigned int num = 0;


static void system_Ini()
{
    TMOD = 0x00;
   // TH0=0x1C;   
   //TL0=0x18;	
	 TH0 = (8192 - 1000)/32;
	 TL0 = (8192 - 1000)%32	;
   IE = 0x8A;   //??	
   TR0  = 1;
}


void int0(){
	system_Ini();
	while(1){
		delays(100);
		digital_pile_show_number(num%10000/1000,num%1000/100,num%100/10,num%10);
	}

}
void T0zd(void) interrupt 1
{
	 //TH0 = 0xFc;    //12.000
	 //TL0 = 0x18;

	 TH0 = (8192 - 1000)/32	;
	 TL0 = (8192 - 1000)%32;

 	 num++;
}