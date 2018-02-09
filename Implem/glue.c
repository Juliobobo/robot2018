
/*

Sample user code for 2 tasks :

- one fast/high rate  HighTask
- one slow/low rate   LowTask

Periods are in ms (see periods.h)

*/

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "Comportement.h"
#include "Fonctionnement.h"
#include "periods.h"

#include <stdbool.h>

#define speedMax 45

//Buffer pour le mode
static bool bufferMode[2];
static int currentMode = 0;
static int count = 0;
static int distanceInit = 0;
static int leftW;
static int rightW;
static int leftB;
static int rightB;

/*-----------------------------
   OSEK declarations 
-------------------------------
DON'T MODIFY
------------------------------*/
DeclareCounter(SysTimerCnt);
DeclareResource(lcd);
DeclareTask(LowTask);
DeclareTask(HighTask);

void usr_init();

/*------------------------------
 Function to be invoked from a category 2 interrupt
--------------------------------
DON'T MODIFY
------------------------------*/
void user_1ms_isr_type2(void)
{
	StatusType ercd;
	
	/*
	 *  Increment OSEK Alarm System Timer Count
     */
	ercd = SignalCounter( SysTimerCnt );
	if( ercd != E_OK ){
		ShutdownOS( ercd );
	}
}

/* ---- HERE BEGINS YOUR CODE ----*/

/* Init and terminate OSEK */
void ecrobot_device_initialize() {
   /*
      HERE: put here specific code that will be executed ONCE
            when the application starts
      TYPICALLY: initialization of (light) sensors
   */
	ecrobot_init_sonar_sensor(NXT_PORT_S3); //Distance
   	ecrobot_set_light_sensor_active(NXT_PORT_S2); //Gauche
   	ecrobot_set_light_sensor_active(NXT_PORT_S1); //Droite
}

void ecrobot_device_terminate() {
   /*
      HERE: put here specific code that will be executed ONCE
            when the application stops
      TYPICALLY: finalization of (light) sensors
   */
   	ecrobot_term_sonar_sensor(NXT_PORT_S3); //Distance
   	ecrobot_set_light_sensor_inactive(NXT_PORT_S2); //Gauche
   	ecrobot_set_light_sensor_inactive(NXT_PORT_S1); //Droite
}

/*------------------------------
  Definitions
--------------------------------
shared vars, functions etc
------------------------------*/


/* Global user initialization:
   put here any code to be executed:
   - ONCE
   - AFTER devices (and brick) initialization
   - BEFORE the start of reactive loop 
*/
void usr_init(){
	// Init du buffer
	bufferMode[0] = true;
	bufferMode[1] = true;
	
	GetResource(lcd);
	
	display_clear(0);
	display_goto_xy(0,0);
	display_string("White init");
	
	// Init les capteurs sur le blanc
	while(!ecrobot_is_ENTER_button_pressed()) {
		leftW = ecrobot_get_light_sensor(NXT_PORT_S2) + 20;
		rightW = ecrobot_get_light_sensor(NXT_PORT_S1) + 20;
		
		display_clear(1);
		display_goto_xy(0, 0);
			
		display_string("-- White --");
		
		display_goto_xy(0, 1);
		
		display_string("L => ");
		
		display_goto_xy(5, 1);
		display_int(leftW, 3);
		display_goto_xy(0, 2);
		
		display_string("R => ");
		
		display_goto_xy(5, 2);
		display_int(rightW, 3) ;
		display_update();
		
		
		display_goto_xy(0, 4);
		display_string("Press button !");
		
		systick_wait_ms(800);
	}
	
	systick_wait_ms(1000);
	
	// Init les capteurs sur le noir
	while(!ecrobot_is_ENTER_button_pressed()) {
		leftB = ecrobot_get_light_sensor(NXT_PORT_S2);
		rightB = ecrobot_get_light_sensor(NXT_PORT_S1);
		
		display_clear(1);
		display_goto_xy(0, 0);
			
		display_string("-- Black --");
		
		display_goto_xy(0, 1);
		
		display_string("L => ");
		
		display_goto_xy(5, 1);
		display_int(leftB, 3);
		display_goto_xy(0, 2);
		
		display_string("R => ");
		
		display_goto_xy(5, 2);
		display_int(rightB, 3) ;
		display_update();
		
		
		display_goto_xy(0, 4);
		display_string("Press button !");
		
		systick_wait_ms(800);
	}
	
	systick_wait_ms(1000);
	
	//Init de la distance de l'obstacle
	while(!ecrobot_is_ENTER_button_pressed()) {
	
		distanceInit = ecrobot_get_sonar_sensor(NXT_PORT_S3);
		display_clear(1);
		display_goto_xy(0, 0);
			
		display_string("-- Distance --");
		
		display_goto_xy(0, 1);
		
		display_string("Dist => ");
		
		display_goto_xy(9, 1);
		display_int(distanceInit, 3);
		display_update();
		
		display_goto_xy(0, 4);	
		display_string("Press button");
		
		systick_wait_ms(800);
	}
	
	systick_wait_ms(1000);
	
	while(!ecrobot_is_ENTER_button_pressed()){
		display_clear(1);
		display_goto_xy(0, 0);
		display_string("!! Start !!");
		display_goto_xy(0, 2);
		display_string("Press button");
		display_update();
		
		systick_wait_ms(800);
	}
	
	display_clear(1);
	display_goto_xy(0, 0);
	display_string("Init done !");
	display_update();	
	display_clear(1);
	
	
	
	//Init des 2 modules Behavior & Mode
	Comportement_init();
	Fonctionnement_init();
	
	ReleaseResource(lcd);
}

/*------------------------------
  Others Function
--------------------------------
- Need to grade in [0;100]
- Check distance
------------------------------*/

_real grade( _real black, _real white, long value ){
	_real gradeValue = (black - value) / (black - white) * 100;
	
	if ( gradeValue > 100 ){
		return 100;
	} else if ( gradeValue < 0 ) { 
		return 0;
	} else {
		return gradeValue;
	}

}

_real checkDistance( int distance ){
	if( distance > distanceInit ) {
		return 15;
	} else {
		return 5;
	}
}

/*------------------------------
  Speed and mode Functions
--------------------------------
- Control engine right and left
- Change mode when there is an obstacle
------------------------------*/

void speedMotor(U8 port_id, _real speed, int place){
	int speed_cast_to_int = (int) (speed * 100);
	
	if( speed_cast_to_int > speedMax ){
		speed_cast_to_int = speedMax;
	}
	 
	if ( speed_cast_to_int < -speedMax ){
		speed_cast_to_int = -speedMax;
	}
	
	display_goto_xy(0, place);
	display_int(speed_cast_to_int,3);
	display_update();
	
	return ecrobot_set_motor_speed(port_id, speed_cast_to_int);
}

void Comportement_O_v_d(_real speed){
	speedMotor(NXT_PORT_A, speed, 1);
}

void Comportement_O_v_g(_real speed){
	speedMotor(NXT_PORT_B, speed, 2);
} 	



void Fonctionnement_O_Mode(_boolean mode){
	bufferMode[(currentMode + 1) % 2] = mode;
}

/*------------------------------
  Tasks definition
--------------------------------
- MUST be declared with the
  OSEK macro "TASK"
- The last instruction MUST be
  TerminateTask()
------------------------------*/

TASK(LowTask) { // Fonctionnement
	
	display_goto_xy(0,0);
	display_string("Block Mode");
	display_update();
	
	 Fonctionnement_I_Cd_n(grade(rightB, rightW, ecrobot_get_light_sensor(NXT_PORT_S1)));
	Fonctionnement_I_distance(checkDistance(ecrobot_get_sonar_sensor(NXT_PORT_S3)));
	
	Fonctionnement_step();
	
	TerminateTask();
}

TASK(HighTask) { // Comportement
	if( count == 0 ){
		currentMode = (currentMode + 1) % 2;
	}
	
	display_goto_xy(0,0);
	
	if( bufferMode[currentMode % 2] ){
		display_clear(1);
		display_goto_xy(1,6);
		display_string("Go ahead");
	} else {
		display_clear(1);
		display_goto_xy(1,3);
		display_string("Obstacle");
		display_goto_xy(1,7);
		display_string("Turn !");
	}
	
	display_update();
	
	// Captor's values
	display_goto_xy(0,4);
	//display_string("Right : ");
	display_int(grade(rightB, rightW, ecrobot_get_light_sensor(NXT_PORT_S1)),3);
	
	display_goto_xy(0,5);
	//display_string("Left : ");
	display_int(grade(leftB, leftW, ecrobot_get_light_sensor(NXT_PORT_S2)),3);
	
	display_update();
	
	
	Comportement_I_Cg(grade(leftB, leftW, ecrobot_get_light_sensor(NXT_PORT_S2)));
	Comportement_I_Cd(grade(rightB, rightW, ecrobot_get_light_sensor(NXT_PORT_S1)));	
	Comportement_I_Mode(bufferMode[currentMode % 2]);
	
	Comportement_step();
	
	count = (count + 1) % 3;
	
	TerminateTask();
}
