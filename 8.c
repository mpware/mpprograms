void main(void)
{
void delay(int);
unsigned char ch =0x00;
P0 = 0x00; P1 = 0x00; // ports P0, P1 are configured as OUT
	while(1)
	{
		P0= ch;
		P1= ch;  // required only if Dual DAC card is used
		delay(50);
		P0 =~ch;
		P1= ch;
		delay(50);
	}
}
void delay(int n)
	{
	int i;
	for(i=0;i<n;i++)
	;
	}
		Ramp / Triangular
#include<reg51.h>
void main(void)
{
unsigned char chu =0x00, chd = 0xff;
//unsigned flag= 0xFF;
while(1)
{
	 /*while(1) // commented to observe negative ramp, check initial value of chu
	{
	P0= chu;
	chu++;
	if(chu == 0xff)
	break;
	else
	;
	}*/
	while(1)
	{
	P0= chd;
	chd--;
	if (chd == 0x00)
	break;
	else
	;
	}
} // end of forever while
} // end of main
// staircase signal
#include<reg51.h>
void main(void)
{
void delay(int);
unsigned char ch[] = {0x00, 0x33,0x66,0x99,0xCC,0xFF}; // corresponds to 0, 1, 2 , …5 V Modify the program to get staircase signal in either direction.
unsigned char i =0;
	while(1)           // Can it be implemented with one loop? 
	{		// Don’t think of complex logic, use loops 2 or 3?
	P0= ch[i];
	//P1= ch[i];
	delay (10);
	i++;
	if(i>6)
	i=1;
	else
	;
	}
}
