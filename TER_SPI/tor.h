#ifndef TOR_H
#define TOR_H

#include <wiringPi.h>

class TOR
{
public:
    TOR();

    static const int pinTOR = 26;//input tor
    static int digitalReadValTor();

};

#endif // TOR_H
