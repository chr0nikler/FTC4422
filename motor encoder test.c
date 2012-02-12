#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Motor,  motorA,          A,             tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          B,             tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          C,             tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
  nMotorEncoder[motorA] = 0;
  nMotorEncoderTarget[motorA] = 90;
  motor[motorA] = 50;
  wait1Msec(10000);
}

