#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <Arduino.h>

// ************************************************************************************************
// Module setup
// ************************************************************************************************
#define MAX_NUM_OF_TASKS        10
#define TM_TIMER_INTERVAL_MS     1
#define TM_DEBUG                false // Used to enable some debug prints

// ************************************************************************************************
// Task structure
// ************************************************************************************************
typedef void (*TaskCallback)();

typedef struct
{
    int interval_ms;
    int timer;
    TaskCallback callback;
} Task_t;

// ************************************************************************************************
// Public function declarations
// ************************************************************************************************
void TM_Init();
void TM_CreateTask( uint16_t u16Interval_ms, TaskCallback callback);
void TM_Update_ISR();
void TM_Execute();

#endif // TASK_MANAGER_H
