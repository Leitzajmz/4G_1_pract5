#include <18F4620.h>
#device adc=10 
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use RS232(BAUD=9600,XMIT=PIN_C6,rcv=PIN_C7,BITS=8,PARITY=N,STOP=1)


long resultado = 0x00, resultado2=0x00;

void main (void){
   setup_oscillator(OSC_16MHZ);
   setup_adc(ADC_CLOCK_DIV_32);
   setup_adc_ports(AN0_TO_AN1);  
   set_tris_a(0x03);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_e(0x00);
   set_tris_d(0x00);
   output_c(0x00);
   output_e(0x00);
   output_b(0x00);
   output_d(0x00);
   
   while(1){
      set_adc_channel(0);
      delay_us(20);
      resultado = read_adc();
      output_b(resultado);
      output_d(resultado>>8);
      delay_us(10);
      set_adc_channel(1);
      delay_us(20);
      resultado2=read_adc();
      output_c(resultado2);
      output_e(resultado2>>8);
   }
}
