/*
 * TWI.c
 *
 *  Created: 03.05.2020 15:31:15
 *  Author : Kostyanskiy
 */ 
#include "RTC_conf.h"


void TWI_Init() //Speed TWI 100000 KHz
{
	//TWCR = (1<<TWEN);
	TWSR = (1<<TWPS0); //  CPUclk/4
	TWBR = 0x12; //18
}

char TWI_StartCondition()
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));//подождем пока установится TWIN
}

char TWI_Write(unsigned char date)
{
	TWDR = date;
	TWCR = (1<<TWINT)|(1<<TWEN);//включим передачу байта
	while (!(TWCR & (1<<TWINT)));//подождем пока установится TWIN
}

char TWI_Read()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));//ожидание установки бита TWIN
	return TWDR;//читаем регистр данных
}


void TWI_Stop()
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}