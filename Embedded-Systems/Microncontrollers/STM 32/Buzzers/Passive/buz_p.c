// SETUP
// Select TIM1 from Timers Menu
// Clock Source - Internal Clock
// Channel2 - PWM Generation CH2 
// Depending on what you want to do these values changes. For this example I used:
//     Prescaler - 127
//     Counter Period - 20


//LOOP to play sounds in increasingly higher tone
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); //This function starts PWM output on Timer 1, Channel 2.
  int x;
  for (x = 5; x < 50; x+=1){
	  __HAL_TIM_SET_AUTORELOAD(&htim1, x*2); // sets the Auto-Reload Register (ARR) of Timer 1
	  __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,x); //
		HAL_Delay(200);
}

1. __HAL_TIM_SET_AUTORELOAD(&htim1, x*2): - this function determines the frequency (pitch)
  Sets the Auto-Reload Register (ARR) of Timer 1 (htim1) to x * 2. ARR determines how long it takes for the timer to count up before resetting. By changing ARR you cna adjust pwm signal frequency.

2. __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, x): - controls the duty cycle (this functions lets the sound play and controls volume).
  Sets the duty cycle of the PWM signal.
3. HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2):
  Starts PWM output on Timer 1, Channel 2. Enables the timer and configures it to generate a PWM waveform on the corresponding GPIO pin.
4. __HAL_TIM_SET_PRESCALER(&htim1, x): - this function sets the prescaler value for Timer 1 (htim1). The prescaler divides the timer clock frequency by a certain value, effectively slowing down the timer's counting speed. This is useful for generating lower frequencies or longer time intervals.
In context of buzzer, determines the speed of playing the sound.
duty cycle - how much time a signal is ON compared to the total time of one cycle (ON + OFF). It’s usually given as a percentage. 
The higher the duty cycle, the stronger the effect (brighter light, louder buzzer, faster motor, etc.).