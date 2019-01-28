#include "tor.h"


TOR::TOR()
{
     pinMode(pinTOR, INPUT);

}

int TOR::digitalReadValTor(){
    return digitalRead(pinTOR);
}
