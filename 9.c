#include<reg51.h>
#include<kdata.h>
#include <kpdrd.h>
#include<del.h>
#include<kdisp.h>
void delay(int n);

void main(void)
{
 unsigned int k,i1,i2,n1,n2,op, n, nxt;
do
{
                    nxt =14;
                   disp_op(nxt);   	// display E on 4th LED as prompt to enter number
                    k =11;
                   			// read 1 st number
  	      do
  	     {
                   k = key_rd(); 
                   i1=k;
                 } while(k>10); 	// read a digit between 0 & 9 MSD 
                 delay(65535);  	// come down to user speed to feed number
                  k =12;
                 do
                {
                 k = key_rd();
                 i2 =k;
                 } while(k>11);// reads LSD
                delay(65535);
                n1 = i1*10+i2;	 // construct the number, 2 - digit 
                digit_disp(n1);  // displayed on right corner
                 			// read the operator
                  nxt = 14; 
                 disp_op(nxt);   	// prompt to enter operator
                 op=6;
          	     do
                 {
  	     k = key_rd();
  	    op =k;
  	     }while(op<10);
  	     delay(65535);
//  read 2nd number
              nxt =14;	
             disp_op(nxt);
             k =11;
             while(k>10)
             {
            k = key_rd(); 
             i1 = k;             // read MSD
             }
         delay(65535);
          k =12;
          while(k>11)
         {
          k = key_rd();   		// read LSD
          i2 = k;
         }
         delay(65535);
         n2 = i1*10+i2;
        digit_disp(n2);
    switch(op)
   {
    case 10: n =n1+ n2;
                 break;
    case 11: n =n1- n2;
                 break;
    case 12: n = n1*n2;
                 break;
    case 13: if (n2!=0)
	       n= n1/n2;
                   else
                  n = 0x00;       	  
                  break;
    default: n= n1%n2;
            break;
  }                                               
  disp_op(op);  
 digit_disp(n);
 op =6; 			// to wait for proper op    
}while(1);
}
