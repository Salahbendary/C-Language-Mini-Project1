/*
 * Vehicle_Control_System.c
 *
 *  Created on: Dec 13, 2021

 ============================================================================
 Name        : Vehicle_Control_System.c
 Author      :  Salah Bendary
 Version     :
 Copyright   : Your copyright notice
 Description : Vehicle Control System
 ============================================================================
 */
#include <stdio.h>
void Turn_on_the_vehicle_engine();
void current_vehicle_state();
void traffic_light_colour ();
void temperature_sensor();
void engine_temperature_sensor();
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char c;
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf(" %c",&c);
	if ( c== 'a' || c=='A' )
	{
		Turn_on_the_vehicle_engine(); }
	else if ( c== 'b' || c=='B')
	{
		printf("Turn off the vehicle engine\n");
		main(); }
	else if ( c== 'c' || c=='C')
	{
		printf("Quit the system\n");
	}
	return 0;
}
void Turn_on_the_vehicle_engine() {
	char c;
	printf( "\n a. Turn off the engine \n "
			"b. Set the traffic light color. \n "
			"c. Set the room temperature (Temperature Sensor) \n "
			"d. Set the engine temperature (Engine Temperature Sensor) \n \n ");
	scanf(" %c",&c);
	if ( c== 'a' || c=='A'){
		main(); }
	else if ( c== 'b' || c=='B'){
		traffic_light_colour();
	}
	else if ( c== 'c' || c=='C'){
		temperature_sensor();
	}
	else if ( c== 'd' || c=='D'){
		engine_temperature_sensor();
	}
	current_vehicle_state();
}
void current_vehicle_state(int *vehicle_speed, int *room_temp,int *engine_temp,char *engine_state,char *AC_state , char *engine_temp_controller_state){

	printf("Vehicle Speed is: %d KM/H \n" , *vehicle_speed);
	printf("Room Temperature is: %d C \n" , *room_temp);
	printf("Engine Temperature is: %d C \n" , *engine_temp);
	printf("Engine State is: %s \n", engine_state );
	printf("AC State is: %s \n", AC_state );
	printf("Engine Temperature Controller State is: %s \n", engine_temp_controller_state );
}
void traffic_light_colour(){
	char c;
	int vehicle_speed=100 , engine_temp=90;
	int room_temp= 35;
	char *engine_state = "ON";
	char *AC_state = "ON" ;
	char *engine_temp_controller_state = "ON";
	printf("Enter the required color either G for Green or O for Orange or R for Red  : \n " );
	scanf(" %c",&c);
	if (c == 'g' || c=='G' ) {
		vehicle_speed = 100;
		room_temp=35;
	}
	else if (c == 'o'  || c=='o') {
		vehicle_speed = 30;
		AC_state = "ON";
		room_temp= room_temp* (5/4)+1;
		engine_temp_controller_state = "ON";
		engine_temp = engine_temp*(5/4)+1;
	}
	else if (c == 'r'  || c=='R' ) {
		vehicle_speed = 0;
		room_temp=35;
	}
	current_vehicle_state(&vehicle_speed,&room_temp,&engine_temp,*&engine_state,*&AC_state,*&engine_temp_controller_state);
	Turn_on_the_vehicle_engine();
}
void temperature_sensor(){
	int t;
	char *engine_state = "ON";
	char *AC_state = "ON" ;
	char *engine_temp_controller_state = "ON";
	int vehicle_speed=100 , engine_temp= 90;
	int room_temp= 35;
	printf("Enter the temperature: \n" );
	scanf(" %d",&t);
	if (t <= 10 ){
		/* “Turn AC ON and set temperature to 20 */
		AC_state = "ON";
		room_temp = 20;
	}
	else if (t >= 30){
		/* “Turn AC ON and set temperature to 20 */
		AC_state = "ON";
		room_temp = 20;
	}
	else {
		AC_state = "OFF";
	}
	current_vehicle_state(&vehicle_speed,&room_temp,&engine_temp,*&engine_state,*&AC_state,*&engine_temp_controller_state);
	Turn_on_the_vehicle_engine();
}
void engine_temperature_sensor(){
	int t;
	char *engine_state = "ON";
	char *AC_state = "ON" ;
	char *engine_temp_controller_state = "ON";
	int vehicle_speed=100 , engine_temp= 90;
	int room_temp= 35;
	printf("Enter the engine temperature: \n" );
	scanf(" %d",&t);
	if (t <= 100 ){
		/* “Engine Temperature Controller” ON and set temperature to 125 */
		engine_temp_controller_state = "ON";
		engine_temp = 125;
	}
	else if (t >= 150){
		/* “Engine Temperature Controller” ON and set temperature to 125 */
		engine_temp_controller_state = "ON";
		engine_temp = 125;
	}
	else {
		engine_temp_controller_state = "OFF";
	}
	current_vehicle_state(&vehicle_speed,&room_temp,&engine_temp,*&engine_state,*&AC_state,*&engine_temp_controller_state);
	Turn_on_the_vehicle_engine();
}
