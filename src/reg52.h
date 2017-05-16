/*--------------------------------------------------------------------------
自定义REG52头文件
@auth lei
@date 2017-05
--------------------------------------------------------------------------*/

#ifndef __REG52_H__
#define __REG52_H__

/*  一个字节的寄存器  */
sfr P0    = 0x80;//双向IO，向外输出要接上拉电阻
sfr P1    = 0x90;//准双向IO，作为输入要先置1
sfr P2    = 0xA0;//准双向IO，作为输入要先置1
sfr P3    = 0xB0;//准双向IO，作为输入要先置1，有第二功能
sfr PSW   = 0xD0;
sfr ACC   = 0xE0;
sfr B     = 0xF0;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr PCON  = 0x87;
sfr TCON  = 0x88;//中断控制寄存器
sfr TMOD  = 0x89;//定时器工作方式寄存器
sfr TL0   = 0x8A;//定时器/计数器0低8位
sfr TL1   = 0x8B;//定时器/计数器1低8位
sfr TH0   = 0x8C;//定时器/计数器0高8位
sfr TH1   = 0x8D;//定时器/计数器1高8位
sfr IE    = 0xA8;//中断允许寄存器
sfr IP    = 0xB8;//中断优先级寄存器
sfr SCON  = 0x98;
sfr SBUF  = 0x99;

/*  8052单片机扩展的寄存器 */
sfr T2CON  = 0xC8;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;


/*  一位长度的寄存器  */
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit P     = PSW^0; //8052 专用

/*------------中断内容详解----------------------------
*相关的寄存器
*			1.IE中断允许寄存器
*			2.TCON定时控制寄存器
*			3.IP中断优先级寄存器（不常用）
*			4.TMOD定时器工作方式寄存器（定时器/计数器中断才用到）
*使用中断的步骤：
*			1.中断初始化函数（只需要调用一次，不要放到循环里重复调用）
*			2.编写中断处理函数
*			3.主函数中调用中断初始化函数
*------------中断内容详解----------------------------/

/*  TCON定时控制寄存器  */
sbit TF1   = TCON^7;//定时器/计数器中标志位：
sbit TR1   = TCON^6;//定时器/计数器中1启动、停止：
sbit TF0   = TCON^5;//定时器/计数器中0标志位：
sbit TR0   = TCON^4;//定时器/计数器中断0启动、停止:
sbit IE1   = TCON^3;//外部中断1中断标志位：中断产生时硬件置1，中断函数处理完后硬件置0
sbit IT1   = TCON^2;//外部中断1触发方式：0为电平、1为下降沿
sbit IE0   = TCON^1;//外部中断0中断标志位：中断产生时硬件置1，中断函数处理完后硬件置0
sbit IT0   = TCON^0;//外部中断0触发方式：0为电平、1为下降沿

/*  IE中断允许寄存器  */
sbit EA    = IE^7;//中断总开关
sbit ET2   = IE^5; //8052 专用
sbit ES    = IE^4;
sbit ET1   = IE^3;//定时器/计数器中断1开关
sbit EX1   = IE^2;//外部中断1开关
sbit ET0   = IE^1;//定时器/计数器中断0开关
sbit EX0   = IE^0;//外部中断0开关

/*  IP中断优先级寄存器  */
sbit PT2   = IP^5;
sbit PS    = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;

/*------------------TMOD寄存器详解-----------------
8位从高到低依次为：GATE		C/T		M1	M0				GATE	C/T		M1	M0
									{----配置定时器1----}				{----配置定时器0----}
GATE:门控位，由外部引脚（T0、T1）作为定时器的启动总开关：GATE=0时，T0和T1无效；GATE=1时，需要T0或者T1开关打开（高电平）定时器才能启动
C/T:计数方式选择，C/T=0时用作定时器，C/T=1时用作计数器
M1、M0:工作方式选择位，00为工作方式0，13位定时器/计数器，TH存放高8位，TL存放低5位
											 01为工作方式1，16位定时器/计数器，TH存放高8位，TL存放低8位（常用）
											 10为工作方式2，初值自动装载的8位定时器/计数器（常用）
											 11为工作方式3，T0被分为两个8位独立计数器，T1停止工作
*------------------TMOD寄存器详解-----------------/


/*  P3口的第二功能  */
sbit RD    = P3^7;//外部存储器读选通信号
sbit WR    = P3^6;//外部存储器写选通信号
sbit T1    = P3^5;//外部控制定时器/计数器1的启动（TMOD寄存器第7位GATE = 1时才有效），1为启动，0位停止
sbit T0    = P3^4;//外部控制定时器/计数器0的启动（TMOD寄存器第3位GATE = 1时才有效），1为启动，0位停止
sbit INT1  = P3^3;//外部中断1输入
sbit INT0  = P3^2;//外部中断0输入
sbit TXD   = P3^1;//串行输出
sbit RXD   = P3^0;//串行输入

/*  SCON串口控制寄存器  */
sbit SM0   = SCON^7;
sbit SM1   = SCON^6;
sbit SM2   = SCON^5;
sbit REN   = SCON^4;
sbit TB8   = SCON^3;
sbit RB8   = SCON^2;
sbit TI    = SCON^1;
sbit RI    = SCON^0;

/*  P1口第二功能  */
sbit T2EX  = P1^1; // 8052 专用
sbit T2    = P1^0; // 8052 专用
             
/*  T2CON  */
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;



#endif
