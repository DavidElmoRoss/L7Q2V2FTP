/*
    When the PIR MOTION DETECTOR detects motion it should say
    HALT on the 4 digit display and then scroll  thE SPreAd 
    
    Where it says PUT YOUR STATEMENT HERE, put the statement that will
    make this interaction work. There may be more than one version of 
    this statement that will work.            
*/

// Include Section
#include "mbed.h"                   
#include "DigitDisplay.h"           

// Hardware definitions
DigitDisplay segment(D2,D3);          

// Global variables
unsigned char mess[]= {0x00,0x00,0x00,0x00,           
                       0x78,0x74,0x79,0x00,0x6D,0x73,0x50,0x79,0x77,0x5E,             
                       0x00,0x00,0x00,0x00}; 
unsigned short i;
InterruptIn PIR(D6);                          
// Global Variables
short motion_detected=0;                      

// Asynchronous Interrupt Service Routine
void LOW(void)
{
   motion_detected=1;                       
} 
int main(void)
{
                                      // PUT YOUR STATEMENT HERE
    segment.clear();                
    segment.setColon(0);            
    segment.setBrightness(4);       
    
    for(;;)
    { 
       if(motion_detected==1)        
       {                                           
          segment.writeRaw(0,0x74);    
          segment.writeRaw(1,0x77);
          segment.writeRaw(2,0x38);
          segment.writeRaw(3,0x78);  
          wait_ms(500);
          for(i=0;i<=14;++i)             
          {
             segment.writeRaw(&mess[i]); 
               wait_ms(250);
          }
          wait_ms(1000);                
          motion_detected=0;  
        }
    }                       
}