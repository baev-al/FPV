#include "cli.h"
#include "usbd_cdc_if.h"


// return: 1 - equal, 0 - not equal
static uint8_t strComp(uint8_t * s1, uint8_t * s2)
{
	uint8_t pos = 0;
	uint8_t equality = 0;
	while(s1[pos] != '\0' && s2[pos] != '\0')
	{
		if(s1[pos] != s2[pos])
		{
			break;
		}
		pos++;
	}
	if(s1[pos] == s2[pos])
	{
		equality = 1;
	}
	return equality;
}
/*
 * Commands list:
 *     'version' - return sw version
 */
static uint8_t parse(uint8_t * buf)
{
	uint8_t ok = 1;
	if(strComp((uint8_t*)"version", buf))
	{
		CDC_Transmit_FS((uint8_t*)"\n0.0.0\r\n", 8);
	}
	else
	{
		CDC_Transmit_FS((uint8_t*)"\nUnknown command\r\n", 18);
	}
	return ok;
}

void readForParse(uint8_t* buf, uint32_t *len)
{
	static uint8_t command[MAX_COMMAND_LENGTH];
	static uint8_t pointer = 0;
	uint8_t pos = 0;
	while(pos < *len)
	{
		if(buf[pos] == 0x7F) //backspace
		{
			pointer--;
			pos++;
		}
		else if(buf[pos] == '\r')
		{
			command[pointer++] = '\0';
			parse(command);
			pointer = 0;
			pos++;
		}
		else
		{
			command[pointer++] = buf[pos++];
		}
	}
}
