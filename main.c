#include <18F4620.h>
#device adc=10 
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(BAUD=9600,XMIT=PIN_C6,rcv=PIN_C7,BITS=8,PARITY=N,STOP=1)


void main (void){
   setup_oscillator(OSC_16MHZ);
   setup_adc(ADC_CLOCK_DIV_32);
   setup_adc_ports(AN0_TO_AN1);  
   while(1){
      
   }
}



