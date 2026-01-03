  int button_val = 0;
  while (1)
  {
  //If button is pressed then the LED is on

	  //reads status of gpio button
	  button_val = HAL_GPIO_ReadPin(button_GPIO_Port, button_Pin);
	  // if pressed - turn on
	  if (button_val == 0){
		HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, SET);

	  }
	  else{//if not pressed - turn off
		HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, RESET);
		 }

  }