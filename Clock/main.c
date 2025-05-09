/*
 * Clock.c
 *
 * Created: 03.05.2020 15:06:07
 * Author : Kostyanskiy
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include "ili9341.h"
#include "RTC_conf.h"

#define MAIN_TIME 0

struct DS1307 T[1] = 
{	
	[MAIN_TIME] = {
		.sec = 0,
		.min = 0,
	    .hour = 23,
	    .day = 5,
	    .date = 11,
	    .month = 2,
	    .year = 20,
	}
};

void get_main_time (struct DS1307 *MT)
{
	char buffer [5];
	
	DS_Read(MT);
	
	sprintf(buffer, "%02d:%02d:%02d", MT->hour, MT->min, MT->sec);
	TFTDrawString(buffer, 50, 150, RED, BLACK, 5);
	
	sprintf(buffer, "%02d:%02d:%02d", MT->date , MT->month, MT->year);
	TFTDrawString(buffer, 280, 240, RED, BLACK, 5);
	
}

int main(void)
{
	LCDinit(3);
	LCD_Fill(BLACK);
	TWI_Init();
	
	DS_Write(&T[MAIN_TIME]);
	
    while (1) 
    {	
		get_main_time(&T[MAIN_TIME]);
		_delay_ms(10); 

    }
}

