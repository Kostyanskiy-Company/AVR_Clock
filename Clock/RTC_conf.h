/*
 * RTC_conf.h
 *
 * Created: 03.05.2020 15:20:26
 * Author : Kostyanskiy
 */ 


#ifndef RTC_CONF_H_
#define RTC_CONF_H_

#include <avr/io.h>
#include <util/delay.h>

//---------------DS1307----------------

typedef struct DS1307 
{
	char sec,min,hour,day,
	     date,month,year;
};

enum
{
	READ_DS = 0xD1,
	DS_ID = 0xD0,
};

enum day_week
{
	MONDEY,
	TUESDAY,
	WEDNESDAY,
	THURSDEY,
	FRIDAY,
	SATURDAY,
	SUNDEY,
};

 struct DS1307 DS_Read(struct DS1307 *DS);  //������ �� ���������� ������ �� ���������� ���������, ���������� �� ��� ��������
 void DS_Write(struct DS1307 *DS);          //���������� � ���������� ������ �� ���������� ���������

 unsigned char C_Dec(unsigned char data); //��������� �-��
 unsigned char C_BinDec(unsigned char data); //��������� �-��

//---------------TWI----------------
 void TWI_Init();
 char TWI_StartCondition();
 char TWI_WriteByte(char date);
 char TWI_ReadByte();
 void TWI_Stop();

#endif /* RTC_CONF_H_ */