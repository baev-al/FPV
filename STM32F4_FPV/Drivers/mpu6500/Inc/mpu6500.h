#ifndef MPU6500_H
#define MPU6500_H 1

#include "stm32f4xx_hal.h"

// Register map
#define MPU6500_GYRO_CONFIG		0x1B
#define MPU6500_ACCEL_CONFIG	0x1C
#define MPU6500_ACCEL_XOUT_H 	0x3B
#define MPU6500_GYRO_XOUT_H		0x43
#define MPU6500_PWR_MGMT_1		0x6B
#define MPU6500_PWR_MGMT_2		0x6C
#define MPU6500_WHO_AM_I 		0x75

uint8_t mpu6500_readReg(uint8_t regAddr, uint8_t * regData);
uint8_t mpu6500_readMem(uint8_t regAddr, uint8_t size, uint8_t * memData);
uint8_t mpu6500_writeReg(uint8_t regAddr, uint8_t regData);

uint8_t mpu6500_init();
uint8_t mpu6500_getDeviceID();
uint8_t mpu6500_accelSelfTest();
uint8_t mpu6500_getRawAccelData(int16_t * xyzData);
uint8_t mpu6500_getGyroAccelData(int16_t * xyzData);

#endif
