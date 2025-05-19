//Before hand go into pin config. Click timers and select a timer pin. 
//Prescaler determines how accurate the value will be. For example 1 is less percise than 8000.
//in this case set prescaler to 8000 - 1 and counter period to 65355 - 1.
HAL_TIM_Base_Start(&htim16);
uint16_t timer_val;
  //get current time
  timer_val = __HAL_TIM_GET_COUNTER(&htim16);
  while (1)
  {
   //if enough time passed (1 sec) toogle LED and get new time stamp
	  if (__HAL_TIM_GET_COUNTER(&htim16) - timer_val >= 10000){
		  HAL_GPIO_TogglePin(GPIO_L, GPIO_Pin)
		  timer_val = __HAL_TIM_GET_COUNTER(&htim16);
	  }
  }

//Before hand go into pin config. Click timers and select a timer pin. 
//Counter period 10000 - 1. NVIC settings enable tim16 global interrupt.
  //start timer(interrupt api).
  HAL_TIM_Base_Start_IT(&htim16); //IT - runs in interrupt mode
  while (1)
  {

  }

  void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim == &htim16){
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
}