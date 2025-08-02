# What is freeRTOS on ESP32?
##  How to go around **Creating a task**, given that the task has been defined before setup()?
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
## What is a Watchdog?
**ESP IDF** offers three types of watchdogs:
1. Hardware Watchdog Timers
2. Interrupt Watchdog Timer (IWDT):*ensures that ISRs (Interrupt Service Routines) are not blocked for a prolonged period of time.*
3. Task Watchdog Timer (TWDT):  *detects instances of tasks running without yielding for a prolonged period.* - what i need in this project.

### What is TWDT?
*"The Task Watchdog Timer (TWDT) is used to monitor particular tasks, ensuring that they are able to execute within a given timeout period." - ESP-idf Programming Guide*

Basically, just checks if a task is running and is not yielding to others task, which means some sort of infinite loop. 

**FUNCTIONS**
- *esp_task_wdt_init(const esp_task_wdt_config_t *config)* to initialize the TWDT and subscribe the idle tasks.
  - *config is a pointer to a const esp_task_wdt_config_t type which is a struct, that holds all the necessary setting for TWDT.
  - ```
    esp_task_wdt_config_t wdt_cfg {
    uint32_t timeout_ms;      // TWDT timeout duration in milliseconds - how much time to give a task before activating watchdog and saying something is wrond.
    uint32_t idle_core_mask; - (1 << portNUM_PROCESSORS) - 1 is a bitmask that sets one bit for each CPU core (so for a two‑core chip it becomes 0b11). That mask tells the Task WDT to automatically “watch” the idle task on each of those cores.
    //if set to 0, auto idle-task monitor is disabled, thus only tasks that are manually added get watched.
    bool     trigger_panic;   // true = panic+reset on timeout; false = warn+backtrace only - when something is wrong and task doesnt do its task within the given limit by 1st parameter here I tell it to panic and do something or to ignore it.
    };
    ```
- *esp_task_wdt_add()* - subscribes other tasks to the TWDT.
- Once subscribed, *esp_task_wdt_reset()* should be called from the task to feed the TWDT.
- *esp_task_wdt_delete()* unsubscribes a previously subscribed task.
- *esp_task_wdt_deinit()* unsubscribes the idle tasks and deinitializes the TWDT.
- *esp_task_wdt_add_user()* to subscribe an arbitrary user of the TWDT. This function returns a user handle to the added user.
- *esp_task_wdt_reset_user()* must be called using the user handle in order to prevent a TWDT timeout.
- *esp_task_wdt_delete_user()* unsubscribes an arbitrary user of the TWDT.

**CONFIG**
*CONFIG_ESP_TASK_WDT_TIMEOUT_S* - sets the default timeout period. Set to as long as you expect any single task needs to monopolize the CPU.

## What is Inter-task Communication?
Its communication between tasks. There are couple ways to make it happen.

### What is Queue?
Queue a data structure based on FIFO concept (first in first out). Queue stores task 1's output and task 2 in a loop digests those outputs. Basically, it receives when there's something in the queue and waits when there is nothing there.

- **HOW TO CREATE a QUEUE?** - *xQueueCreate*. x here becasue return is some special type x.
- **HOW TO DELETE a QUEUE?** - *vQueueDelete*. v here because return is void.
- **HOW TO SEND TO BACK OF QUEUE?** - *xQueueSend*.
- **HOW TO SEND TO FRONT OF QUEUE?** - *xQueueSendToFront*.
- **HOW TO RECEIVE FROM QUEUE?** - *xQueueReceive*.

## How does freeRTOS fit within ESP32 ecosystem?
From my search, I found that ESP 32 System API is built on top of freeRTOS. Basically, ESP-IDF (Espressif IoT Development Framework) uses a modified (SMP‑capable: a computing architecture in which two or more identical processor cores share the same main memory and are managed by a single operating‑system kernel) FreeRTOS kernel for task scheduling, timers, queues, and other OS functionality. The System API you call in your application (e.g. task creation, inter‑task communication, timing) are simply thin wrappers around those FreeRTOS primitives, with some ESP‑IDF–specific enhancements (“FreeRTOS Additions”) to support multi‑core operation and IDF‑style hooks.



## Misc Stuff for freeRTOS on ESP 32

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