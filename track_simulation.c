// FILE - track_simulation.c
#include"track_simulation.h"

//Car parameters

int mass = 100;
float gravitational_const = 9.81;
float frontal_area = 1.3;
float desity_air = 1.2754;
float drag_coefficient = 0.27;
float wheel_radius = 0.15;

int current_track_segment;
unsigned int time_last_call;
double total_distance;

double car_speed;
unsigned int prev_speed_measure_time;
int speed_sencor_pin = 24;


//Dumy vectors for testing
double track_distance = [0 10 20 30 40];
double track_elevation_change = [0 1 -1 1 2 -1];

void init_track_simulation(){
        current_track_segment = 0;
        time_last_call = millis();
        total_distance = 0;
        //track_distance = read_track_distance();
        //track_elevation_change = read_track_elevation();
}

double calculate_torque(double speed, double segment_distance, double eleveation_change){
        double angle = atan(eleveation_change/segment_distance);
        double elevation_force = mass*gravitational_const*sin(angle);
        double drag_force = 0.5*desity_air*(speed*speed)*drag_coefficient*frontal_area;
        return (elevation_force+drag_force)*speed;
}

double track_simulation(speed){

	unsigned int time_now = millis();
	total_distance += speed*(double)(time_now - time_last_call);
	time_last_call = time_now;

	if (track_distance[current_track_segment] < total_distance) {current_track_segment+=1};

	double tourque_reference = calculate_torque(speed, track_distance[current_track_segment], track_elevation_change[current_track_segment]);
	return tourque_reference;
}

void update_car_speed(void){
        unsigned int time_now = millis();
        unsigned int revolution_time = time_now - prev_speed_measure_time;
        prev_speed_measure_time = millis();
        car_speed = (1/revolution_time)*wheel_radius; //speed in m/s
}

void init_speed_sensor(void){
        wiringPiISR (speed_sencor_pin, INT_EDGE_RISING,  &update_car_speed);

}
