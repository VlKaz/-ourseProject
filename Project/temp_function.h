#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#define SIZE 1000

typedef struct sensor
{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	int8_t t;
} sensor;

int AddInfo(sensor* info, char filename[]);
void Print(sensor* info,int number);
void InfoByMonth(sensor* info, int number, int m);
void InfoByYear(sensor* info, int number);

