#include "D_LED.h"

// ************************************************************************************************
// Local variables
// ************************************************************************************************
uint16_t u16BlinkInterval_ms = 500;
const int ledRed = 0;
const int ledRed2 = 3;
const int ledYel = 1;
const int ledYel2 = 4;
const int ledGree = 2;
const int ledGree2 = 5;

// ************************************************************************************************
// Public functions
// ************************************************************************************************

// ************************************************************************************************
// Brief        Init LED pins and status
//
// Param[in]    None
// Param[out]   None
// Return       None
//
// Warning      Meget simpel implementering, kun til demo-formål
// ************************************************************************************************
void D_LED_Init( void )
{
    pinMode( LED_BUILTIN, OUTPUT );
    pinMode( ledRed, OUTPUT );
    pinMode( ledRed2, OUTPUT );
    pinMode( ledYel, OUTPUT );
    pinMode( ledYel2, OUTPUT );
    pinMode( ledGree, OUTPUT );
    pinMode( ledGree2, OUTPUT );
}

// ************************************************************************************************
// Brief        Køre de 5 alm. lysdioder
//
// Param[in]    None
// Param[out]   None
// Return       None
//
// Warning      None
// ************************************************************************************************
void D_LED_RED_Task( void )
{
    int ledPower = rand() % 156 + 100;
    // digitalWrite( ledRed, HIGH ); // HIGH og LOW kan bruges til at tænde og slukke - Disse bruges særligt med digitalWrite hvor analogWrite er PWM baseret
    analogWrite( ledRed, ledPower);
}
void D_LED_RED2_Task( void )
{
    int ledPower = rand() % 156 + 100;
    // digitalWrite( ledRed, HIGH ); // HIGH og LOW kan bruges til at tænde og slukke - Disse bruges særligt med digitalWrite hvor analogWrite er PWM baseret
    analogWrite( ledRed2, ledPower);
}
void D_LED_YELLOW_Task( void )
{
    int ledPower = rand() % 156 + 100;
    // digitalWrite( ledRed, HIGH ); // HIGH og LOW kan bruges til at tænde og slukke - Disse bruges særligt med digitalWrite hvor analogWrite er PWM baseret
    analogWrite( ledYel, ledPower);
}
void D_LED_YELLOW2_Task( void )
{
    int ledPower = rand() % 156 + 100;
    // digitalWrite( ledRed, HIGH ); // HIGH og LOW kan bruges til at tænde og slukke - Disse bruges særligt med digitalWrite hvor analogWrite er PWM baseret
    analogWrite( ledYel2, ledPower);
}
void D_LED_GREEN_Task( void )
{
    int ledPower = rand() % 156 + 100;
    // digitalWrite( ledRed, HIGH ); // HIGH og LOW kan bruges til at tænde og slukke - Disse bruges særligt med digitalWrite hvor analogWrite er PWM baseret
    analogWrite( ledGree, ledPower);
}


// ************************************************************************************************
// Brief        Set the blink interval 
//
// Param[in]    u16Interval_ms : The Interval in ms
// Param[out]   None
// Return       None
//
// Warning      None
// ************************************************************************************************
void D_LED_SetBlinkInterval( uint16_t u16NewInterval_ms )
{
    u16BlinkInterval_ms = u16NewInterval_ms;
}

// ************************************************************************************************
// Private functions
// ************************************************************************************************

