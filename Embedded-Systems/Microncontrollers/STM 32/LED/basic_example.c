//   Basic example of how to get a led to blink. 
//   Beforehand you do need to setup the Led_pin. 
//   LED-pin settings:
//      gpio output level - high
//      gpio mode - outpush push pull
//      pull up/down - no pull up/down
//      max output speed - low

//BAD WAY
  while (1)
  {
	  //makes the LED4 blink
	  //toggles the pin on and off causing the led to blink
	  HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin); //Led_pin is the pin name I assigne to PA5.
	  HAL_Delay(500); //while this is on nothing else can happen which is bad for embedded systems because they are usually doing multiple things at once.


  }

//GOOD WAY
  uint32_t now = 0, last_blink = 0;
  while (1)
  {
    now = HAL_GetTick();
    if (now - last_blink >= 500){

    	HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin);
    	last_blink = now;
    }

  }