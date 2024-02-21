#ifndef CLI_H
#define CLI_H 1

#include "stdint.h"

#define MAX_COMMAND_LENGTH	50

void readForParse(uint8_t* buf, uint32_t *len);

#endif
