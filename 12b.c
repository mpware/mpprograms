 #include<reg51.h>
void main(void)
     {
void timer delay(void);
unsigned char x;
      P2 = 0x55;
while(1)
        {
           P2 =~ P2;
for(x =0;x<20;x++)
timer_delay();
        }
     }

     void timer_delay(void)
    {
       TMOD = 0x10; // timer 1 in mode 1
TL1 = 0xFe; // loading values 
                            //A5FE = 42494; 65536 - 42494 = 23042 X 1-085 =      20 ms.
       TH1 = 0xA5;
       TR1 =1;
while(TF1==0); // wait for flag to roll over
       TR1 =0; // turn off timer1
       TF1 =0; // clear flag
    }  
