// ************************************************************************************************
// Hej Kåre, her er mit bud på hvordan opgaven kunne løses. Jeg har brugt lidt AI til at hjælpe mig igennem
// opgaven. Det ville være rart med en gennemgang af hvordan det ellers kunne se ud.
// ************************************************************************************************
// ************************************************************************************************
// Includes
// ************************************************************************************************
// C and Arduino includes:
#include <Arduino.h>
#include <stdio.h>

// Pico includes:
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Application includes:
#include "C_TaskManager.h"
#include "D_LED.h"

// ************************************************************************************************
// Local variables
// ************************************************************************************************
// Timer for systick (Task Manager tick)
static repeating_timer_t timerSystick;

// String som benyttes til at printe status:
char strStatus[64];

// ************************************************************************************************
// Brief        Timer1 1ms ISR. Simply calls the TaskManager every 1 ms
//
// Param[in]    None
// Param[out]   None
// Return       None
//
// Warning      None
// ************************************************************************************************
static bool systick_callback( repeating_timer_t *rt )
{
    TM_Update_ISR();
    return true;    // keep the timer running
}

// ************************************************************************************************
// Brief        Start the 1 ms repeating hardware timer.
//              Uses alarm pool 0 (default), hardware alarm 0.
//
//              add_repeating_timer_us( -1000, ... ) schedules the next callback 1000 µs after
//              the *previous callback returned*, giving a stable 1 ms period regardless of callback
//              execution time.  Use +1000 if you want 1 ms from the *start* of each callback instead.
//
// Param[in]    None
// Param[out]   None
// Return       None
//
// Warning      None
// ************************************************************************************************
static void initSystickTimer( void )
{
    // Negative period → delay is measured from the END of the callback,
    // avoiding drift if the callback itself takes a few microseconds.
    bool ok = add_repeating_timer_us( -1000, systick_callback, NULL, &timerSystick );
    if ( !ok )
    {
        Serial.println( "ERROR: Could not allocate repeating timer!" );
    }
}

// ************************************************************************************************
// Arduino setup() function
// ************************************************************************************************
void setup()
{
    // Open COM port:
    Serial.begin( 115200 );

    // Initialise the task manager
    TM_Init();
    D_LED_Init();

    // Create tasks:
    TM_CreateTask( 1000, D_LED_Task );
    TM_CreateTask( 110, D_LED_RED_Task );
    TM_CreateTask( 120, D_LED_RED2_Task );
    TM_CreateTask( 130, D_LED_YELLOW_Task );
    TM_CreateTask( 140, D_LED_YELLOW2_Task );
    TM_CreateTask( 150, D_LED_GREEN_Task );

    // Add more tasks here...

    // Start the 1 ms hardware timer
    initSystickTimer();

    Serial.println(F("Application running..."));
}

// ************************************************************************************************
// Arduino loop() — Run the task manager as fast as possible
// ************************************************************************************************
void loop()
{
    TM_Execute();
}
