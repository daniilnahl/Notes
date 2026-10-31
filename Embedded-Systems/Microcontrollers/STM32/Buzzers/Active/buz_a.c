// Make sure to configure a pin that can output enough voltage to activate the buzzer.
// code:
 while (1)
  {	//SIMPLE  ACTIVE BUZZER CONTROL
	  HAL_GPIO_WritePin(buuzzer2_GPIO_Port, buuzzer2_Pin, RESET);
	  HAL_Delay(500);
	  HAL_GPIO_WritePin(buuzzer2_GPIO_Port, buuzzer2_Pin, SET);
	  HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }