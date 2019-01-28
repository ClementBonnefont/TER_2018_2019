#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <wiringPi.h>

class Communication
{
public:
    Communication();
    static const int pinTOR = 26;//input tor
    static int digitalReadValTor();
    static const int SER = 12; //Serial data
    static const int RCLK = 10; //Clock pour pulser les 8 bits d'un coup
    static const int SRCLK = 14; //Clock pour pulser sur un registre
    static void delayMS(int x);
    static void sipo(unsigned long byte);
    static void pulse(int pin);
    static void digitalWriteSPI(unsigned long bytes);
    static unsigned long precedentOctets;
};

#endif // COMMUNICATION_H
