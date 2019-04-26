#include <reg51.h>
#include<eledata.h>
#include<del.h>
main()
{
unsigned char reqflr,curflr = 0x01,i,j; // note all var’s are  unsigned char
 P0 = 0xf0;
while(1)
 {
	P1 = 0x0f;  			// lower nibble of P1 made input port 
	reqflr = P1 | 0xf0;	 // read floor request & append f (for upper nibble)					 // loop until request  appears
	while (reqflr == 0xff)
		reqflr = P1 | 0xf0;	// Read Request Floor from P1 
	
	reqflr = ~ reqflr;		// complement request  becomes a power of 2 num		
	if(curflr == reqflr)		 // If Request floor is equal to Current Floor 
	{	
              P0 = fclr[curflr];	
delay(65535); 		// Clear Floor Indicator 
	 }			// Go up to read again 
	else
	if(curflr>reqflr)		 // If Current floor is > request floor 
	{
	  i = flr_no[curflr] - flr_no[reqflr];  // gives the floor difference 1,2,4,8….. 
	  j = flr_ind[curflr]; 		// get the respective floor byte to glow led
	for(;i>0;i--)	
	delay(32767); 
	      }	
        } // end of else
curflr =  reqflr;			/*Move the indicator down */
	  {
	   P0 = j; 			 // keep displaying LED’s
		j--;
	delay(32767); 		 // a delay of 0.5 sec
	  }
	  }     
	else				// If Current floor is < request floor 
	{
	  i = flr_no[reqflr] - flr_no[curflr]; // Get the no of floors to travel 
	  j = flr_ind[curflr];	
	for(;i>0;i--)		// Move the indicator Up 
	      {								
	             P0 = j;
		j++;
		//request floor becomes the current floor
P0 = fclr[curflr];			// Clear the indicator 
  }
}
