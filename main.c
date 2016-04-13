// FILE - main.c
//

#include<stdio.h>
#include<time.h>
#include<math.h>
#include"ADC_driver.h"
//#include<wiringPi.h>
#include<softPwm.h>
//#include"track_simulation.h"
//#include"io.h"


int main(int argc, char** arg){
        /*
        int torque = calculate_torque(3.3, 5);
        printf("torque = %d, floatnumber = %f \n", torque, 5.5);
        */
	
	/*	
	
	ADC_init();
	while(1){
		printf("reading from ADC: %i \n", ADC_read());
	}
	*/
	wiringPiSetupGpio();
	int pwm_error = softPwmCreate(24, 10, 100);
	if (pwm_error != 0 ){
		printf("PWM-setup error\n");
	}
	
	while (1){
		for(int i = 0; i < 100; i++){
			softPwmWrite(24, i );
		}
	}
	
		softPwmWrite(24, 50 );
	while(1){}

        return 0;
}

