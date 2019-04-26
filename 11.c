#include<reg51.h>
sbit rs = P2^4;
sbit rw = P2^5;
sbit en  = P2^6; 

void main()
{
void delay(unsigned int n);
void lcdcmd(unsigned char cmd);  // command function 
void lcddata(unsigned char d);       // write data  function 
unsigned char x[] = {"Hello RV"};  // string to be displayed
unsigned char i = 0;
lcdcmd(0x3C);    // command 0x38 for 1 line & 5X7 dots ;  
delay(100);  // write time required for LCD to set the function (40  s)
lcdcmd(0x0e);	
lcdcmd(0x01); // clears display screen
delay(100);
lcdcmd(0x06);  // shift display to right after each char dispaly
delay(100);
//lcdcmd(0x0C); // cursor off & display on
//delay(100);
lcdcmd(0x80); // cursor off & display on
delay(100);
for(i=0;i< 8;i++)    // time for sending data 
{
lcddata(x[i]);    // display the string of length 8
delay(1000);
}

/* lcdcmd(0xC0); // sets cursor on the 2nd half  line   
delay(50);      // display your name by sending 8 char of your name
*/
while(1);  // after displaying enters infinite loop
}

void lcdcmd(unsigned char cmd)
{
 P0= cmd;
 rs =0;  // register select 0  
 rw = 0;  // read / write 0 for writing
 en = 1;    // high to low pulse
 delay(20);
 en = 0;
 return;
 }
 
void lcddata(unsigned char d)
{
 P0 = d;
 rs = 1;   // for data 1
 rw = 0;
 en = 1;
 delay(20);
 en = 0;
 return;
 }
  
  void delay(unsigned int n)
  {
   unsigned int i;
   for(i=0;i<n;i++)
    ;
  }  
