#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     magnet,              sensorHiTechnicMagnetic)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.



task main()
{


  int threshold = 10;

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
    if (joystick.joy1_y1 <= 5 && joystick.joy1_y1 >= -5)    //Run drive motors
    {
      motor[motorD] = 0;
    }

    else
    {
      motor[motorD] = joystick.joy1_y1/2;
    }

    if (joystick.joy1_y2 <= 5 && joystick.joy1_y2 >= -5)
    {
      motor[motorE] = 0;
    }
    else
    {
      motor[motorE] = joystick.joy1_y2/2;
    }

    if(SensorValue[magnet] < 665  && SensorValue[magnet] > 653)  //Magnetic servo stopper
    {
      servo[servo1] = 100;
    }

    else
    {
      servo[servo1] = 255;
    }

    if(joy1Btn(1) == 1)         //NXT servo magnetic scorer
    {
      motor[motorB] = 40;
    }
    if(joy1Btn(2) == 1)
    {
      motor[motorB] = -60;
    }
    if(joy1Btn(1) == 0 && joy1Btn(2) == 0)
    {
      motor[motorB] = 0;
    }
    if(joy1Btn(5) == 1)
    {
      motor[motorC] = 100;
    }
    else if (joy1Btn(6) == 1)
    {
      motor[motorC] = -30;
    }
    else
    {
      motor[motorC] = 0;
    }b






  }
}