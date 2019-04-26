#include<reg51.h>  // to access ports, timer registers etc.,  

unsigned   char dig7[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; 
void main(void)
{
void delay(unsigned int);
int i=0, i1, i2, k;    // i = 99 for down 
P11 =0, P10 = 0;  // configured as output
while(1)
                {
                   i2 = i%10;  // LS digit, unit place 
                   i1 = i/10;    // MS digit, tenth place
i++;          // decrement for DOWN 
for(k=0;k<125;k++)   // loop repeated for 0.5 s
                        {
		   P0= dig7[i1]; P1 = 0x10;  // place data on P0 and enable right LED 
delay(250);     // data on the bus for 2 ms.
                            P0= dig7[i2];  P1 =0x20;    // P1 – bit 0 enables right LED, bit 1 enables left LED (MSD) 
	delay(250);
                         } 	
		if(i >99)   // i < 0
                         i= 0;
else
                           ;
                       }
}    

void delay(unsigned int n)
{ 
unsignedint i;     // can you write without i? Possible, How?
for (i=0; i<n;i++)
            ;	// null executed.  Is there a statement in C? 
}
