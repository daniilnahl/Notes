// RTC - real time clock. Some microcontrollers have it built in like my nucleo031c6.
// It can track time, date and an alarm can be configured in it.

// How to get started?
// 1. Under Timers select RTC.
// 2. Check boxes for activate clock source and calendar.
// 3. Make sure to set RTC data format to Binary(Under Calendar Time, data format).

//basic setup
RTC_DateTypeDef Date;
RTC_TimeTypeDef Time;

RTC_HandleTypeDef hrtc;

static void MX_RTC_Init(void);
int main(void)
{
  MX_RTC_Init();

  while (1)
  {
	  HAL_RTC_GetTime(&hrtc, &Time, RTC_FORMAT_BIN); //&Time provides the address of the variable, if Time is without & that would create a copy of Time in the function which leads to uncessary memory allocation.
	  HAL_RTC_GetDate(&hrtc, &Date, RTC_FORMAT_BIN); //&Date provides the address of the variable
	  //prints time to a console which I didnt set up
	  printf("%02d-%02d-%2d, ",Date.Date, Date.Month, 2000+Date.Year);
	  printf("%02d:%02d:%02d", Time.Hours, Time.Minutes, Time.Seconds);

	  seconds = Time.Seconds;

	  HAL_Delay(500);
  }
}

//NOTE  MX_RTC_Init() - intializes the alarm automatically. 
//If you want to do it on your own remove if from Mx_RTC_Init and do it in main().
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_RTC_Init();

  //THIS CODE IS USUALLY IN RTC_Init
  RTC_AlarmTypeDef sAlarm = {0};
  /** Enable the Alarm A
    */
    sAlarm.AlarmTime.Hours = 0;
    sAlarm.AlarmTime.Minutes = 0;
    sAlarm.AlarmTime.Seconds = 5;
    sAlarm.AlarmTime.SubSeconds = 0;
    sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
    sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
    sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
    sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
    sAlarm.AlarmDateWeekDay = 1;
    sAlarm.Alarm = RTC_ALARM_A;

    if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
    {
      Error_Handler();
    }
    while (1)
    {
      // Main loop can remain empty as the LED toggle is handled in the callback
    }
  }

  //This functions turns the LED off when alarm matches
  void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
  {
    /* Toggle LED: assumes LED is connected to GPIOA PIN5 */
	HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin);

  }

//Basically there is already inner code that is not seen which throws a call to 
//HAL_RTC_AlarmAEventCallback() when a time matches alarm. User must define HAL_RTC_AlarmAEventCallback().