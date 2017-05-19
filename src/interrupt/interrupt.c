
#include "reg52.h"
#include "interrupt.h"


void interrupt0(){
	EX0 = 1;
	
	EA = 1;
	
}