
#include <stdio.h>
#include <wiringPi.h>

int ADC_init(){
  if (wiringPiSPISetup (0, 1000000) < 0) return -1 ;
}

int ADC_read(){
  uint8_t buff[3];
  int adc;
  buff[0] = 1;
  //buff[1]: The four higest bits are the CONFIGURE BITS FOR THE MCP3008, 
  //0x0 gives differential input with CH0 = IN+ and CH! = IN-
  buff[1] = 0x00; 
  buff[2] = 0x00;
  wiringPiSPIDataRW(0, buff, 3);
  adc = ((buff[1]&3) << 8) + buff[2];
  return adc;
}