#include <18F4620.h>
#device adc=10 
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

void configuracionDePuertos();
void inicializarPuertos();

long resultado = 0x00;

#int_ad
void ISR_AD(){
   resultado = read_adc(ADC_READ_ONLY);
   read_adc(ADC_START_ONLY);
}

void main (void){
   setup_oscillator(OSC_16MHZ);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0_TO_AN1);  
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   
   configuracionDePuertos();
   inicializarPuertos();
   
   while(1){ 
      set_adc_channel(0);
      delay_ms(1);
      read_adc(ADC_START_ONLY);
      output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      
      set_adc_channel(1);
      delay_ms(1);
      read_adc(ADC_START_ONLY);
      output_c(resultado);
      output_e(resultado >> 8);
      delay_us(10);
   }
}

/*FUNCIONES*/


void configuracionDePuertos(){
   set_tris_a(0x03);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_e(0x00);
   set_tris_d(0x00);
}

void inicializarPuertos(){
   output_c(0x00);
   output_e(0x00);
   output_b(0x00);
   output_d(0x00);
}

