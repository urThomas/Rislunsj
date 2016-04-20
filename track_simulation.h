#ifndef TRACK_SIMULATION_FILE
#define TRACK_SIMULATION_FILE

#include <wiringPi.h>
#include <stdio.h>
#include <math.h>

void init_track_simulation();
double track_simulation(double speed);
void update_car_speed(void);
void init_speed_sensor(void);

#endif
