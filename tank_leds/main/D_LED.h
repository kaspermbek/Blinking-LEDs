#ifndef D_LED_H
#define D_LED_H

#include <Arduino.h>

// ************************************************************************************************
// Macro, constant, typedefs etc.
// ************************************************************************************************
#define D_LED_TASK_INTERVAL_MS 100

// ************************************************************************************************
// Public function declarations
// ************************************************************************************************
void D_LED_Init( void );
void D_LED_Task( void );
void D_LED_RED_Task( void );
void D_LED_RED2_Task( void );
void D_LED_YELLOW_Task( void );
void D_LED_YELLOW2_Task( void );
void D_LED_GREEN_Task( void );
void D_LED_GREEN2_Task( void );
void D_LED_SetBlinkInterval( uint16_t u16NewInterval_ms );

#endif
