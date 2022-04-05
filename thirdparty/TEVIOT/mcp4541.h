/*
 * mcp4541.h
 *
 * Created: 2021-12-28 7:59:41 PM
 *  Author: ganes
 */ 


#ifndef MCP4541_H_
#define MCP4541_H_

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

#define SLAVEADDRESS 46

typedef enum {write = 0, read = 1} RW_Bit_t;
typedef enum {writeData = 0, increment = 1, decrement = 2,readData = 3} Command_Operation_t;
typedef enum {volatileWiper0 = 0 ,volatileWiper1=1,wiperLock0=2,wiperLock1=3, tconReg=4,statReg=5,writeprot=0x0f}MemoryMap_t;

uint8_t getCommandbyte( MemoryMap_t memAddr,Command_Operation_t bit);
void readMCP4541( MemoryMap_t memAddr,Command_Operation_t bit, uint8_t *data);
void writeMCP4541( MemoryMap_t memAddr,Command_Operation_t bit, uint8_t data);
void initMCP4541(void);


#endif /* MCP4541_H_ */