#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     magnet,              sensorHiTechnicMagnetic)
#pragma config(Sensor, S3,     IR,                  sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     lightSensor,         sensorLightActive)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoStandard)
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

  initializeRobot();
  int threshold = 10;
  waitForStart();   // wait for start of tele-op phase
  while (true)
  {
    nxtDisplayTextLine(3, "Value is : %4d" + nImmediateBatteryLevel);
    nxtDisplayTextLine(2, "Value is : %4d" + externalBatteryAvg);
    nxtDisplayTextLine(5, "Value is : %4d" + SensorValue[magnet]);

    /*if (nImmediateBatteryLevel < 8000 && externalBatteryAvg < 14000)
    {
      PlayTone(100, 5);
    }

    else if (externalBatteryAvg < 14000 && nImmediateBatteryLevel > 8000)
    {
      PlayTone(500, 5);
    }

    else if (externalBatteryAvg > 14000 && nImmediateBatteryLevel < 8000)
    {
      PlayTone(900, 5);
    }*/

    //battery level check

    getJoystickSettings(joystick);
    if(abs(joystick.joy1_y2) > threshold)
    {
      motor[motorE] = joystick.joy1_y2/1.5;
    }
    else
    {
      motor[motorE] = 0;
    }


    if(abs(joystick.joy1_y1) > threshold)
    {
      motor[motorD] = joystick.joy1_y1/1.5;

    }
    else
    {
      motor[motorD] = 0;
    }

    if(SensorValue[magnet] < 665  && SensorValue[magnet] > 653)  //Magnetic servo stopper
    {
      servo[servo1] = 100;

    }

    else
    {
      servo[servo1] = 255;
    }

    if (joystick.joy1_TopHat == 6)
    {
      servo[servo1] = 100;
    }

    if (joystick.joy1_TopHat == 2)
    {
      servo[servo1] = 255;
    }

    if(joy1Btn(1) == 1)         //NXT servo magnetic scorer
    {
      motor[motorB] = 20;
    }
    if(joy1Btn(2) == 1)
    {
      motor[motorB] = -20;
    }
    if(joy1Btn(1) == 0 && joy1Btn(2) == 0)
    {
      motor[motorB] = 0;
    }
    if(joy1Btn(5) == 1)
    {
      motor[motorA] = 95;
    }
    else if (joy1Btn(6) == 1)
    {
      motor[motorA] = -20;
    }
    else
    {
      motor[motorA] = 0;
    }
    if(joy1Btn(7) == 1)
    {
      servo[servo4] = 230;
    }
    else if (joy1Btn(8)== 1)
    {
      servo[servo4] = 0;
    }
    if(joy1Btn(9) == 1)
    {
      servo[servo3] = 200;
      servo[servo5] = 45;
    }
    else if (joy1Btn(10) == 1)
    {
      servo[servo3] = 80;
      servo[servo5] = 155;
    }
    if(joy1Btn(3) == 1)
    {
      motor[motorC] = 7;
    }
    else if(joy1Btn(4) == 1)
    {
      motor[motorC] = -7;
    }
    else
    {
      motor[motorC] = 0;
    }

    //Weiyu's Tophat and alternative rear arm code


    /*if (joystick.joy1_TopHat == 0)
    {
      motor[motorD] = 30;
      motor[motorE] = 30;
    }



    if (joystick.joy1_TopHat == 4)
    {
      motor[motorD] = -30;
      motor[motorE] = -30;
    }*/




  }
}
