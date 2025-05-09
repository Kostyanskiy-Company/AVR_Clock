/*
 * ili9341.h
 *
 * Created: 16.04.2020 20:00:00
 *  Author: Kostyanskiy
 *  Notice: 
 */ 


#ifndef ILI9341_H_
#define ILI9341_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
//====================================
#define swap(a,b) {int16_t t=a;a=b;b=t;}
//===Пины к которым подключен дисплей=
#define LCD_CS 0   //Chip Select
#define LCD_DC 2    //Command/Data
#define LCD_RESET 1 //LCD Reset
#define LCD_MISO 4
#define LCD_MOSI 3
#define LCD_SCK 5
//====================================
unsigned int X_SIZE;
unsigned int Y_SIZE;
//===Цвета============================
enum
{
 BLACK =      0x0000,
 NAVY =       0x000F,
 DARKGREEN =  0x03E0,
 DARKCYAN  =  0x03EF,
 MAROON  =    0x7800,
 PURPLE  =    0x780F,
 OLIVE   =    0x7BE0,
 LIGHTGREY =  0xC618,
 DARKGREY =   0x7BEF,
 BLUE   =     0x001F,
 GREEN =      0x07E0,
 CYAN   =     0x07FF,
 RED   =      0xF800,
 MAGENTA =    0xF81F,
 YELLOW =     0xFFE0,
 WHITE  =     0xFFFF,
 ORANGE =     0xFD20,
 GREENYELLOW= 0xAFE5,
 PINK =       0xF81F,	
};
//===Макросы==========================
#define DC_HIGH        PORTB |=  (1<<LCD_DC);
#define DC_LOW         PORTB &=~ (1<<LCD_DC);
#define CS_HIGH        PORTB |=  (1<<LCD_CS);
#define CS_LOW         PORTB &=~ (1<<LCD_CS);
#define RESET_HIGH     PORTB |=  (1<<LCD_RESET);
#define RESET_LOW      PORTB &=~ (1<<LCD_RESET);
//===Базовые функции==================
void SPI_MasterInit (void);
int  SPI_MasterTransmit(uint8_t cData);
void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);
//===Внутренние функции===============
void TFT9341_SendCommand(unsigned char data);
void TFT9341_SendData(unsigned char data);
void TFT9341_SetRotation(unsigned char r);
//===Пользовательские функции=========
void LCDinit(char i);//Ротацыя дисплея с инициализацией
void LCD_Fill(uint16_t color);
void TFTDrawString(unsigned char *str, int x, int y, uint16_t color, uint16_t bg, int size);
void TFTDrawValue(int x, int y, int16_t coll ,unsigned int val, int size);
void TFTDrawRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, uint16_t color);
//====================================
void LCD_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void TFTDrawPixel(int x, int y, uint16_t color);
void TFTDrawLine(uint16_t color,unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void DrawChar(int x, int y, unsigned char c, uint16_t color, uint16_t bg, int size);
void TFT_fillrect(uint16_t x,uint16_t y,uint16_t w,uint16_t h, uint16_t colour);
//====================================
typedef struct ILI9341
{

};
//====================================
#endif /* ILI9341_H_ */