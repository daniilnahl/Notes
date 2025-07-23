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
