// FILE - main.c
//

#include<stdio.h>
#include<time.h>
#include<math.h>
#include"ADC_driver.h"
//#include"track_simulation.h"
//#include"io.h"


// HEIHEIHEIHEIEHIEH
// Heuheu


//bajs



int main(int argc, char** arg){
        /*
        int torque = calculate_torque(3.3, 5);
        printf("torque = %d, floatnumber = %f \n", torque, 5.5);
        */

	ADC_init();
	while(1){
		printf("reading from ADC: %i \n", ADC_read());
	}
        return 0;
}

