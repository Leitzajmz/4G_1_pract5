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
void guardar();
void guardar2();
long resultado = 0x00, resultado2 = 0x00, flag = 0x00;

#int_ad
void ISR_AD(){
   resultado = read_adc(ADC_READ_ONLY);
      resultado2 = read_adc(ADC_READ_ONLY);
   read_adc(ADC_START_ONLY);
   flag = 0x01;
}

void main (void){
   setup_oscillator(OSC_16MHZ);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0_TO_AN1);  
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   
   configuracionDePuertos();
   inicializarPuertos();
   
   int canal = 0;
   while(1){ 
      set_adc_channel(canal);
      delay_ms(1);
      read_adc(ADC_START_ONLY);
      
      if(flag == 0x01){    
         guardar();
         delay_us(10);
         
         canal = 0x01;
         set_adc_channel(canal);
         delay_ms(1);
         read_adc(ADC_START_ONLY);
         guardar2();
         delay_us(10);
         flag = 0x00;
      }
      canal = 0;
   }
}

/*FUNCIONES*/

void guardar(){
   if(resultado > 0 && resultado < 100){
         resultado = 0x01;
         output_b(resultado);
         output_d(resultado >> 8);        
         delay_us(10);
      }else if(resultado > 100 && resultado < 201){
         resultado = 0x02;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }else if(resultado > 200 && resultado < 301){
         resultado = 0x04;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }else if(resultado > 300 && resultado < 401){
         resultado = 0x08;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }
      else if(resultado > 400 && resultado < 501){
         resultado = 0x10;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }else if(resultado > 500 && resultado < 601){
         resultado = 0x20;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }else if(resultado > 600 && resultado < 701){
         resultado = 0x40;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }else if(resultado > 700 && resultado < 801){
         resultado = 0x80;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }else if(resultado > 800 && resultado < 901){
         resultado = 0x100;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }else if(resultado > 900 && resultado < 1024){
         resultado = 0x200;
         output_b(resultado);
      output_d(resultado >> 8);
      delay_us(10);
      }
}

void guardar2(){
   if(resultado2 > 0 && resultado2 < 100){
         resultado2 = 0x01;
         output_c(resultado2);
         output_e(resultado2 >> 8);       
         delay_us(10);
      }else if(resultado2 > 100 && resultado2 < 201){
         resultado2 = 0x02;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }else if(resultado2 > 200 && resultado2 < 301){
         resultado2 = 0x04;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }else if(resultado2 > 300 && resultado2 < 401){
         resultado2 = 0x08;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }
      else if(resultado2 > 400 && resultado2 < 501){
         resultado2 = 0x10;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }else if(resultado2 > 500 && resultado2 < 601){
         resultado2 = 0x20;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }else if(resultado2 > 600 && resultado2 < 701){
         resultado2 = 0x40;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }else if(resultado2 > 700 && resultado2 < 801){
         resultado2 = 0x80;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }else if(resultado2 > 800 && resultado2 < 901){
         resultado2 = 0x100;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }else if(resultado2 > 900 && resultado2 < 1024){
         resultado2 = 0x200;
         output_c(resultado2);
         output_e(resultado2 >> 8);
         delay_us(10);
      }
}

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

