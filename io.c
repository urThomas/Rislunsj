//FILE - io.c

#include<stdio.h>
#include"io.h"

int MesureCurrent(){
	int voltage = ADC_read();
	return voltage/resistance;
}