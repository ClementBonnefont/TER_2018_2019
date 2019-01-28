#include "communication.h"
//#include <QDebug>

#define CLOCK_DRIVERS 28

unsigned long Communication::precedentOctets = 0x00000000 ;

Communication::Communication()
{
    wiringPiSetup();
    pinMode(pinTOR, INPUT);
    pinMode(SER, OUTPUT);
    pinMode(RCLK, OUTPUT);
    pinMode(SRCLK, OUTPUT);
    digitalWrite(SER, 0);
    digitalWrite(SRCLK, 0);
    digitalWrite(RCLK, 0);
    digitalWriteSPI(0);

//    /*Implementation de la clock pour de maj des drivers
//    * Val max 19.2 MHz -- 19200000
//    * Pre divisible par 2¹⁰ soit 4096
//    * 19.2 MHz --> 19200000
//    * 9.6  MHz --> 9600000
//    * 4.8  MHz --> 4800000
//    * 2.4  MHz --> 2400000
//    * 1.2  MHz --> 1200000
//    */

//    /* A DECOMMENTER POUR LE REEL */
//    /*
//    pinMode(CLOCK_DRIVERS, GPIO_CLOCK);
//    // set a 2.4MHz
//    gpioClockSet(CLOCK_DRIVERS, 2400000);
//    */
}

int Communication::digitalReadValTor(){
    return digitalRead(pinTOR);
}

void Communication::delayMS(int x) {
    delayMicroseconds(x * 1000);
}

//charger sur les 3 registres de 8 bit à la fois
void Communication::sipo(unsigned long byte)
{
    int i;
    /*
    qDebug("FFFFFFF");
    qDebug() << (byte & 0xFFFFFFFF);
    qDebug("FF");
    qDebug()<< (byte & 0xFF000000);
    qDebug("00FF");
    qDebug() << (byte & 0x00FF0000);
    qDebug("0000FF");
    qDebug() << (byte & 0x0000FF00);
    qDebug("000000FF");
    qDebug() << (byte & 0x000000FF);
*/

    for (i=0; i<32 ;i++)
    {
        digitalWrite(SER,(byte & (0x80000000 >> i)));
        pulse(SRCLK);
    }

}

//Front montant
void Communication::pulse(int pin)
{
    digitalWrite(pin, 1);
    digitalWrite(pin, 0);
}


void Communication::digitalWriteSPI(unsigned long bytes) {

    if (bytes != Communication::precedentOctets){
        sipo(bytes);
        pulse(RCLK);
        //qDebug("le vecteur a changé, MAJ du vect : ");
        Communication::precedentOctets = bytes;
        //qDebug() << SPI::precedentOctets;
    }

}

