#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     magnet,              sensorHiTechnicMagnetic)
#pragma config(Sensor, S3,     IR,                  sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     lightSensor,         sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

int x = 0;

void lightsensed()
{
  while(nNxtButtonPressed != 3)
  {
   nxtDisplayTextLine(1, "Light Value is %d", SensorValue[lightSensor]);
  }
 x = SensorValue[lightSensor];
}

void initclaw()
{
  motor[motorA] = 50;
  wait1Msec(1000);
  motor[motorA] = 0;
}





void initializeRobot()
{

  initclaw();
  lightsensed();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();
  waitForStart(); // Wait for the beginning of autonomous phase.
  time1(T1) = 0;
  motor[motorD] = 80;
  motor[motorE] = 80;
  wait1Msec(2000);

  motor[motorD] = 0;
  motor[motorE] = 0;
  wait1Msec(1000);

  motor[motorD] = -40;
  motor[motorE] = 40;
  wait1Msec(1600);

  motor[motorD] = 0;
  motor[motorE] = 0;
  wait1Msec(1000);

  motor[motorD] = 60;
  motor[motorE] = 60;
  wait1Msec(2000);




  while (time1(T1) < 30000)
  {

  if (SensorValue[lightSensor] <= x + 2)
  {
     motor[motorD] = 10;
     motor[motorE] = 10;
     wait1Msec(1500);
     break;
  }
  if (SensorValue[IR] < 3)
  {
    motor[motorD] = -40;
    motor[motorE] = 40;
  }
  else if (SensorValue[IR] > 3 && SensorValue[IR] < 5)
  {
    motor[motorD] = -40;
    motor[motorE] = 40;
  }
  else if (SensorValue[IR] > 7)
  {
    motor[motorD] = 40;
    motor[motorE] = -40;
  }
  else if (SensorValue[IR] > 5 && SensorValue[IR] < 7)
  {
    motor[motorD] = 40;
    motor[motorE] = -40;
  }
  else if (SensorValue[IR] > 4 &&   SensorValue[IR] < 6)
  {
    motor[motorD] = 20;
    motor[motorE] = 20;
  }


  nxtDisplayTextLine(5, "Value is : %4d" + SensorValue[IR]);
  }
  motor[motorD] = 0;
  motor[motorE] = 0;


  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////



}
