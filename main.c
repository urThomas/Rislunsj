// FILE - main.c
//

#include<stdio.h>
#include<time.h>
#include<math.h>

#include"track_simulation.h"
//#include"io.h"









int main(int argc, char** arg){
        
        int torque = calculate_torque(3.3, 5);
        printf("torque = %d, floatnumber = %f \n", torque, 5.5);
        

        return 0;
}

