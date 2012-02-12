#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     mag1,           sensorHiTechnicMagnetic)
#pragma config(Sensor, S3,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     mag2,           sensorHiTechnicMagnetic)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
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
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}

void detectball()
{
  if((SensorValue[mag1] > 660 || SensorValue[mag1] < 654))
  {
    servo[servo1] = 255;
    wait1Msec(500);
    motor[motorD] = -100;
    wait1Msec(500);
    motor[motorD] = 0;
    servo[servo1] =100;
    wait1Msec(500);
  }
}

void rollers()
{
  motor[motorD] = -100;
  motor[motorA] = -100;
  motor[motorB] = -100;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  //initializeRobot();

  //waitForStart();   // wait for start of tele-op phase
int threshold = 5;

  while (true)
  {
    nxtDisplayTextLine(3, "Value is %d", SensorValue[mag1]);
    rollers();
	  detectball();

	  getJoystickSettings(joystick);

	  if(abs(joystick.joy1_y2) > threshold)
    {
      motor[motorH] = joystick.joy1_y2/2;
    }
    else
    {
      motor[motorH] = 0;
    }

    if(abs(joystick.joy1_y1) > threshold)
    {
      motor[motorG] = joystick.joy1_y1/2;
    }
    else
    {
      motor[motorG] = 0;
    }

    if(joy1Btn(1))
    {
      motor[motorI] = 30;
    }
    else if(joy1Btn(2))
    {
      motor[motorI] = -30;
    }
    else
    {
      motor[motorI] = 0;
    }
    if(joy1Btn(3))
    {
      motor[motorF] = 20;
    }
    else if(joy1Btn(4))
    {
      motor[motorF] = -20;
    }
    else
    {
      motor[motorF] = 0;
    }
  }
}