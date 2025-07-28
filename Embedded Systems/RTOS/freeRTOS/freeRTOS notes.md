# free RTOS on ESP32

**Creating a task**, given that the task has been defined before setup().
```
...
void setup() {
  BASE CODE:

  xTaskCreate(TaskFunction_t pxTaskCode, const char *const pcName, const uint32_t usStackDepth, void *const pvParameters, UBaseType_t uxPriority, TaskHandle_t *const pxCreatedTask)

  EXPLANATION:

  xTaskCreate(TaskFunction_t (task name), const char *const (description of the task),
  const uint32_t (stack size: more varaibles = higher stack size (bytes)),
  void *const( pass parameters to the task (do NULL if no parameters)),
  UBaseType_t (priority: low number = low priority and high number = high priority),
  TaskHandle_t *const (give the task a handle so that this function could be accesed within other functions));

  EXAMPLE:

  xTaskCreate(TaskFunction_t task1, //function name
  const char *const "Task 1",       //task name
  const uint32_t 1000,              //stack size
  void *const NULL,                 //task paramaters
  UBaseType_t 1,                    //priority
  TaskHandle_t *const NULL)         //task handle
}
...
```






# Misc Stuff for freeRTOS on ESP 32

- Script to see how many bytes are free from stack size allocated. Put this code within a task.
```
  UBaseType_t free_bytes = uxTaskGetStackHighWaterMark(NULL);
  Serial.printf("High-water mark for BMP280: %u bytes\n\n\n", free_bytes);
```

- Delay function expressed in ticks but converted to seconds based on my mcu's clock speed. 1000 ticks = 1000ms = 1 sec.
```
  vTaskDelay(1000 / portTICK_PERIOD_MS); 
```


# Errors explanation
- **Stack Overflow: Stack canary watchpoint triggered "*task name*"**. This error was happening because I was not allocating enough stack size for tasks. When scheduler was switching tasks it checks the canary (guard used to detect stack overflow at the end of each task). It checks each time before running a task. In this case, when a task didn't have enough memory it used canary's memory and overwrote it which in scheduler's 'eyes' made the canary corrupted. If its corrupted then it means a stack overflow exception. Stack overflow calls panic handler, which in return calls esp32's watchdog(a hardware timer used to detect and recover from software or hardware malfunctions) reset, reseting the mcu.