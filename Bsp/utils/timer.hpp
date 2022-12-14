#ifndef REF_STM32F4_TIMER_HPP
#define REF_STM32F4_TIMER_HPP

#include <cmath>
#include "tim.h"

typedef void (*TimerCallback_t)();

class Timer
{
private:
  TIM_HandleTypeDef* htim;
  uint32_t freq;
  uint16_t PSC = 60;
  uint16_t ARR = 10000;

  void CalcRegister(uint32_t _freqHz);

public:
  explicit Timer(TIM_HandleTypeDef* _htim, uint32_t _freqHz);

  void SetCallback(TimerCallback_t _timerCallback);

  void Start();
  void Stop();
};

#endif  // REF_STM32F4_TIMER_HPP
