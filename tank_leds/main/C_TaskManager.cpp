#include "C_TaskManager.h"

// ************************************************************************************************
// Local variables
// ************************************************************************************************
static Task_t taskList[MAX_NUM_OF_TASKS];
static uint8_t taskCount = 0;

// ************************************************************************************************
// Public functions
// ************************************************************************************************

// ************************************************************************************************
// Brief         
//
// Param[in]    None
// Param[out]   None
// Return       None
//
// Warning      None
// ************************************************************************************************
void TM_Init()
{
	uint8_t x;

	// Init Task tabel
	for( x = 0; x < MAX_NUM_OF_TASKS; x++ )
	{
		taskList[x].interval_ms = -1;
        taskList[x].timer  = -1;
 	}
}

// ************************************************************************************************
// Brief         
//
// Param[in]    name: A representative name for the task. Only used for debug purpose.
// Param[out]   None
// Return       None
//
// Warning      None
// ************************************************************************************************
void TM_CreateTask( uint16_t u16Interval_ms, TaskCallback callback)
{
    if (taskCount < MAX_NUM_OF_TASKS)
    {
        taskList[taskCount].interval_ms = u16Interval_ms;
        taskList[taskCount].timer       = 0;   // fire immediately on first Execute()
        taskList[taskCount].callback    = callback;

        if (TM_DEBUG)
        {
            Serial.print(F("Task added"));
        }
        taskCount++;
     }
     else
     {
        if (TM_DEBUG)
        {
            Serial.println(F("Task not added: max tasks reached"));
        }
    }
}


// ************************************************************************************************
// Brief        
//
// Param[in]    None
// Param[out]   None
// Return       None
//
// Warning      Must be called every TM_TIMER_INTERVAL_MS
// ************************************************************************************************
void TM_Update_ISR()
{
    for( uint8_t i = 0; i < taskCount; i++ )
    {
        if (taskList[i].timer > 0)
        {
            taskList[i].timer -= TM_TIMER_INTERVAL_MS;
        }
    }
}

// ************************************************************************************************
// Brief        Runs through all tasks, and calls the tasks which are due
//              Called as fast as possible in loop()
//
// Param[in]    None
// Param[out]   None
// Return       None
//
// Warning      Called whenever MCU has nothing else to do
// ************************************************************************************************
void TM_Execute()
{
    for (uint8_t i = 0; i < taskCount; i++)
    {
        if (taskList[i].timer <= 0)
        {
            // Reload the timer before calling the callback so any
            // delay inside the callback doesn't skew the interval.
            taskList[i].timer = taskList[i].interval_ms;

            if (taskList[i].callback)
            {
                taskList[i].callback();
            }
        }
    }
}
