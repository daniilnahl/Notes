Under connectivity select one of the USART.
Turn its mode to Asynchronous.
OPTIONAL: Check box for NVIC Interrupr whichs allows the microcontroller to automatically interrupt the current program execution whenever the USART receives data. (Efficient CPU usage).
 if the box is not checked microcontroller will keep checking USART register (essentially temp memory slot).
 if the box is checked microcontroller will only check when something happens.

Generate code, then go to MX_USART2_UART_Init function if you want to modify anything.


#include <string.h>

//predefined time out value to use across different functions
#define TIMEOUT 100

char msg[] = "Hello Sigma\n";
HAL_UART_Transmit(&huart2, (const uint8_t*) msg, strlen(msg), TIMEOUT);


//NOTE TO SELF (nucleo31c6)
//for some fucking reason I dont know becuase i cant seem to figure it out
//i can only get output using UASRT2 on COM5 port. USART1 DOENST WORK. 