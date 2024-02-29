#include "process.h"
#include "usbd_cdc_if.h"

extern FCstate fcState;

void process(FCstate flContrState)
{
	switch(flContrState)
	{
	case ACC:
		sendAccelGyroToVcom();
		fcState = STANDBY;
		break;
	}
}

void sendAccelGyroToVcom()
{
	//Send 14 bytes: Acel x, y, z; Temp; Gyro x, y, z. Each value int16_t
	static uint16_t dummy[7] = {1, 10, 100, 500, 1000, 2000, 3000};
	for(int i = 0; i < 7; ++i)
	{
		dummy[i]++;
	}
	CDC_Transmit_FS((uint8_t *)dummy, 14);
}
