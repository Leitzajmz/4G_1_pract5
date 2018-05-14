#include <18F4620.h>
#device adc=10 
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

//#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

void configuracionDePuertos();
void inicializarPuertos();
void evaluarConversion(long conversion);
void resultadoChannelZero(long resultado);
void resultadoChannelOne(long resultado1);

long resultado = 0x00, resultado2 = 0x00, flag = 0x00;
  long mostrarResultado;
  
#int_ad
void ISR_AD(){
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
      if (flag = 0x01){
         canal = 0x00;
         set_adc_channel(canal);
         delay_ms(1);
        resultado = read_adc();
         evaluarConversion(resultado);
         resultadoChannelZero(mostrarResultado);
         delay_us(10);
         
         canal = 0x01;
         set_adc_channel(canal);
         delay_ms(1);
         resultado2 = read_adc();
         evaluarConversion(resultado2);
         resultadoChannelOne(mostrarResultado);
         delay_us(10);
         flag = 0x00;
      }
   }
}

/*FUNCIONES*/

void evaluarConversion(long conversion){
 
   if(conversion >= 0 && conversion < 100){
      mostrarResultado = 0x01;
   } else if(conversion > 99 && conversion < 200){
      mostrarResultado = 0x02;
   } else if(conversion > 199 && conversion < 300){
      mostrarResultado = 0x04;
   } else if(conversion > 299 && conversion < 400){
      mostrarResultado = 0x08;
   } else if(conversion > 399 && conversion < 500){
      mostrarResultado = 0x10;
   }else if(conversion > 499 && conversion < 600){
      mostrarResultado = 0x20;
   } else if(conversion > 599 && conversion < 700){
      mostrarResultado = 0x40;
   } else if(conversion > 699 && conversion < 800){
      mostrarResultado = 0x80;
   } else if(conversion > 799 && conversion < 900){
      mostrarResultado = 0x100;
   } else if(conversion > 899 && conversion < 1024){
      mostrarResultado = 0x200;
   }
}

void resultadoChannelZero(long resultado){
   output_b(resultado);
   output_d(resultado>>8);
}


void resultadoChannelOne(long resultado1){
   output_c(resultado1);
   output_e(resultado1>>8);
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