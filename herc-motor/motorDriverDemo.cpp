#include <Arduino.h>

#include <util/delay.h>

#include "motordriver_4wd.h"
#include "seeed_pwm.h"
void setup();
void loop();
//#line 1 "src/motorDriverDemo.ino"
//#include "motordriver_4wd.h"
//#include "seeed_pwm.h"

void setup()
{
    MOTOR.init();
}

void loop()
{
    MOTOR.setSpeedDir(80, DIRF);
    _delay_ms(3000);
   MOTOR.setSpeedDir(80, DIRR);
    _delay_ms(3000);
}
/*********************************************************************************************************
 * END FILE
 *********************************************************************************************************/


