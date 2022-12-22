#include "common_inc.h"
#include <cstdio>

/* User Variables ---------------------------------------------------------*/

//! User-Timers
Timer timerHeartBeat(&htim16, 2);

//! Debug LED LD3

//! Robot instance
Robot robot;

/* Thread Definitions -----------------------------------------------------*/

/* Timer Callbacks -------------------------------------------------------*/

/* Timer Callbacks -------------------------------------------------------*/
void timerHeartBeatCallback()
{
  HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}

/* Interrupt Callbacks -------------------------------------------------------*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_13)
  {
    printf("USER-B1 Interrupt!\n");
    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
  }
}

/* Default Entry -------------------------------------------------------*/
void Main(void)
{
  // Init all communication staff, include USB-CDC/VCP/UART/CAN etc.
  InitCommunication();

  // Start Timer Callbacks.
  timerHeartBeat.SetCallback(timerHeartBeatCallback);
  timerHeartBeat.Start();
}
