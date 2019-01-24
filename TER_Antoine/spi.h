#ifndef SPI_H
#define SPI_H

#include <wiringPi.h>

class SPI
{
public:
    SPI();
    static const int SER = 12; //Serial data
    static const int RCLK = 10; //Clock pour pulser les 8 bits d'un coup
    static const int SRCLK = 14; //Clock pour pulser sur un registre
    static void delayMS(int x);
    static void sipo(unsigned char byte);
    static void pulse(int pin);
    static void digitalWriteSPI(unsigned long bytes);
};

#endif // SPI_H
