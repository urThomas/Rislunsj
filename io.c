//FILE - io.c

#include<stdio.h>
#include"io.h"
#include"ADC_driver.h"


int MesureCurrent(){
	int adc_value = ADC_read();
	int voltage = (adc_value*Vref)/1024;
	return voltage/resistance;
}
