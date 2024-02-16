#include "mpu6500.h"


#define MPU6500_I2C_ADDR (0x68 << 1) //0x68 when addr pin is low

extern I2C_HandleTypeDef hi2c1;

uint8_t mpu6500_readReg(uint8_t regAddr, uint8_t * regData)
{
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c1, MPU6500_I2C_ADDR, regAddr, I2C_MEMADD_SIZE_8BIT, regData, 1, 1000);
	return status == HAL_OK;
}

uint8_t mpu6500_readMem(uint8_t regAddr, uint8_t size, uint8_t * memData)
{
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c1, MPU6500_I2C_ADDR, regAddr, I2C_MEMADD_SIZE_8BIT, memData, size, 1000);
	return status == HAL_OK;
}

uint8_t mpu6500_writeReg(uint8_t regAddr, uint8_t regData)
{
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&hi2c1, MPU6500_I2C_ADDR, regAddr, I2C_MEMADD_SIZE_8BIT, regData, 1, 1000);
	return status == HAL_OK;
}


uint8_t mpu6500_accelSelfTest()
{
	return mpu6500_writeReg(MPU6500_ACCEL_CONFIG, 0xE0); // 0xE0 0b11100000
}

uint8_t mpu6500_getDeviceID()
{
	uint8_t data;
	uint8_t status = mpu6500_readReg(MPU6500_WHO_AM_I, &data);
	return data;
}

uint8_t mpu6500_init()
{
	uint8_t status;
	status = mpu6500_writeReg(MPU6500_GYRO_CONFIG, 0x0);// +-250dps, FCHOICE_B = 0
	status |= mpu6500_writeReg(MPU6500_ACCEL_CONFIG, 0x0);// +-2g
	status |= mpu6500_writeReg(MPU6500_PWR_MGMT_1, 0x1);
	return status;
}

uint8_t mpu6500_getRawAccelData(int16_t * xyzData)
{
	uint8_t data[6];
	uint8_t status = mpu6500_readMem(MPU6500_ACCEL_XOUT_H, 6, data);
	xyzData[0] = (data[0] << 8) + data[1];
	xyzData[1] = (data[2] << 8) + data[3];
	xyzData[2] = (data[4] << 8) + data[5];
	return status;
}

uint8_t mpu6500_getGyroAccelData(int16_t * xyzData)
{
	uint8_t data[6];
	uint8_t status = mpu6500_readMem(MPU6500_GYRO_XOUT_H, 6, data);
	xyzData[0] = (data[0] << 8) + data[1];
	xyzData[1] = (data[2] << 8) + data[3];
	xyzData[2] = (data[4] << 8) + data[5];
	return status;
}
