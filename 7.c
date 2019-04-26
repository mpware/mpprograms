#include <reg51.h>
void main()
{
void delay(unsigned int);
unsigned char x1[] = {0x03,0x09,0x0C,0x06};
unsigned char i;
P2 = 0x00; // configuring P2 as out
While(1)
{
	for (j=0;j<=7;j++)
for(i=0;i<4;i++)
	{ P2 = x1[i];
		Delay(2000);
	}
	
	 // forever wait until restart or reset
}
}  

void delay(unsigned int n)
{
unsigned int i;
for(i=0;i< n ;i++);
}

//clockwise or counter clockwise depending upon switch status read through P1.6

#include <reg51.h>
unsigned char x1[] = {0x03,0x09,0x0C,0x06},temp;
//unsigned char x2[] = {0x03,0x01,0x09,0x08,0x0C,0x04,0x06, 0x02};
// x2 array for alternate phase excitation
void main()
{
voidclk_wise();
voidcclk_wise(); 
void delay(unsigned int);
P2 = 0x00; // configuring P2 as out
	while(1)
	{
	temp = P1 & 0x40;
	 //delay(100);
	if(temp!= 0)
	clk_wise();
	else
	cclk_wise();  
	}
//while(1); 	

}  

void delay(unsigned int n)
{
unsigned  int i;
for(i=0;i< n ;i++);
}
voidclk_wise(void)  // note data array is global 
{ 
	unsigned int i;
	for(i=0;i<4;i++)
	 {
	
	 P2 = x1[i];
	 delay(5000);
	 }
 }
void cclk_wise(void)
{ 
   unsigned int i;
   for(i=0;i<4;i++)
	{
	
	 P2 = x1[3-i];
	delay(5000);
	 }
}  	
