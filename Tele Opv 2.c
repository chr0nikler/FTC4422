const int kMinimumBatteryLvel = 6300;

task main()
{
  int nCounter = 0;

  while (true)
  {
		if (nImmediateBatteryLevel < kMinimumBatteryLvel)
		{
			//
			// Battery level too low to proceeed.
			//
			PlaySound(soundLowBuzz);
			break;
		}
		nxtDisplayTextLine(0, "Battery Levels");

		//
		// Display the Battery levels
		//
		nxtDisplayTextLine(2, "Avg %3.1fV;Now %3.1f", nAvgBatteryLevel / (float) 1000, nImmediateBatteryLevel / (float) 1000);

	  //
	  // Display the voltage level at which the NXT will "shutdown"
	  //
	  nxtDisplayTextLine(4, "Shutdown at%4.1fV", nShutdownVoltage / (float) 1000);

	  //
	  // DIsplay the voltage level at which the NXT will "shutdown"
	  //
	  nxtDisplayTextLine(5, "Sleep Tmr: %d min", nPowerDownDelayMinutes);

	  //
		// Display the Battery type: rechargeable or one-time only
		//
		if (bNxtRechargable)
			nxtDisplayTextLine(7, "Rechargable");
		else
		  nxtDisplayTextLine(7, "Non-Rechargable");

	  //
	  // You can also immediately power off the NXT as follows:
	  //
	  wait1Msec(10);
	  ++nCounter;
	  if (nCounter > 15000)
	    powerOff();
  }
  return;
}
