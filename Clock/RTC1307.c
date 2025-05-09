/*
 * RTC1307.c
 *
 * Created: 03.05.2020 15:30:08
 * Author : Kostyanskiy
 */ 
#include "RTC_conf.h"

unsigned char C_Dec(unsigned char data)
{
	return((data>>4)*10+(0xF&data));
}

unsigned char C_BinDec(unsigned char data)
{
	return((data/10)<<4)|(data%10);
}

struct DS1307 DS_Read(struct DS1307 *DS)
{
	TWI_StartCondition(); 
	TWI_Write(DS_ID);
	TWI_Write(0);
	TWI_Stop();
	
	_delay_ms(300);
	TWI_StartCondition(); 
	TWI_Write(READ_DS); 
	
	DS->sec = TWI_Read(); 
	DS->min = TWI_Read(); 
	DS->hour = TWI_Read();
	DS->day = TWI_Read(); 
	DS->date = TWI_Read(); 
	DS->month = TWI_Read();
	DS->year = TWI_Read();
	
	TWI_Stop(); 
	
	DS->sec = C_Dec(DS->sec); DS->min = C_Dec(DS->min);
	DS->hour = C_Dec(DS->hour); DS->day = C_Dec(DS->day);
	DS->year = C_Dec(DS->year); DS->month = C_Dec(DS->month);
	DS->date = C_Dec(DS->date);
	
	return *DS;
}

void DS_Write(struct DS1307 *DS)
{
	TWI_StartCondition(); 
	TWI_Write(DS_ID);
	TWI_Write(0);
	TWI_Write(C_BinDec(DS->sec));  //секунды
	TWI_Write(C_BinDec(DS->min));  //минуты
	TWI_Write(C_BinDec(DS->hour)); //часы
	TWI_Write(C_BinDec(DS->day));  //день недели
	TWI_Write(C_BinDec(DS->date)); //дата
	TWI_Write(C_BinDec(DS->month));//месяц
	TWI_Write(C_BinDec(DS->year)); //год
	TWI_Stop(); 
}
