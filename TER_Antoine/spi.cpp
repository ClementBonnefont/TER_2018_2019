#include "spi.h"

SPI::SPI()
{
//    wiringPiSetup();
//    pinMode(SER, OUTPUT);
//    pinMode(RCLK, OUTPUT);
//    pinMode(SRCLK, OUTPUT);
//    digitalWrite(SER, 0);
//    digitalWrite(SRCLK, 0);
//    digitalWrite(RCLK, 0);
//    digitalWriteSPI(0);
}

void SPI::delayMS(int x) {
//    delayMicroseconds(x * 1000);
}

//Charger sur un registre de 8 bits
void SPI::sipo(unsigned char byte)
{
    int i;
    for (i=0;i<8;i++)
    {
//        digitalWrite(SER,((byte & (0x80 >> i)) > 0));
        pulse(SRCLK);
    }
}

//Front montant
void SPI::pulse(int pin)
{
//    digitalWrite(pin, 1);
//    digitalWrite(pin, 0);
}


void SPI::digitalWriteSPI(unsigned long bytes) {
    sipo((bytes & 0xFF000000) >> 24);
    sipo((bytes & 0x00FF0000) >> 16);
    sipo((bytes & 0x0000FF00) >> 8);
    sipo(bytes & 0x000000FF);
    pulse(RCLK);
    delayMS(200);
}
