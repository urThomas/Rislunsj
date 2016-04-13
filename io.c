//FILE - io.c

#include<stdio.h>
#include"io.h"

int MesureCurrent(){
	int abc_value = ADC_read();
	int voltage = (adc_value*Vref)/1024;
	return voltage/resistance;
}