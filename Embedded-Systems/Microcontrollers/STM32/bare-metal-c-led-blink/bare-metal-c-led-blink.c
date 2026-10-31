//Bare metal c blinking an LED on stm32h7
#include "main.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_gpio.h"
  //these two lines define pointers to specific registers within memory
  // (BASE + OFFSET)
//  #define GPIOE_MODER (*(volatile unsigned long *) (GPIOE_BASE + 0x00)) //points to GPIO port E mode register
//  #define RCC_AHB4ENR (*(volatile unsigned long *) (RCC_BASE + 0x0E0))  //points to RCC AHB4 peripheral clock enable register.


 /* --- Base Addresses --- */
// Global starting address for all STM32 peripherals
#define PERIPH_BASE         (0x40000000UL)
// Domain 3 memory region offset
#define D3_OFFSET           (0x18000000UL)
// Domain 3 base address (0x58000000)
#define D3_PERIPH_BASE      (PERIPH_BASE + D3_OFFSET)
// Bus offset
#define AHB4PERIPH_OFFSET   (0x00020000UL)
// AHB4 bus base address (0x58020000)
#define AHB4PERIPH_BASE     (D3_PERIPH_BASE + AHB4PERIPH_OFFSET)

/* --- Peripheral Offsets --- */
// GPIO Port H offset along the AHB4 bus
#define GPIOH_OFFSET        (0x1C00UL)
// Base address for Port H (0x58021C00)
#define GPIOH_BASE_T        (AHB4PERIPH_BASE + GPIOH_OFFSET)
// Reset and Clock Control offset
#define RCC_OFFSET          (0x4400UL)
// Base address of RCC (0x58024400)
#define RCC_BASE_T            (AHB4PERIPH_BASE + RCC_OFFSET)

/* --- Register Offsets --- */
// Clock enable register offset
#define RCC_AHB4EN_R_OFFSET (0x0E0UL)
// GPIO direction mode register offset
#define MODE_R_OFFSET       (0x00UL)
// GPIO output data register offset
#define OD_R_OFFSET         (0x14UL)

/* --- Hardware Register Pointers (Executable Macros) --- */
#define RCC_AHB4EN_R        (*(volatile unsigned long *)(RCC_BASE_T + RCC_AHB4EN_R_OFFSET))
#define GPIOH_MODE_R        (*(volatile unsigned long *)(GPIOH_BASE_T + MODE_R_OFFSET))
#define GPIOH_OD_R          (*(volatile unsigned long *)(GPIOH_BASE_T + OD_R_OFFSET))

/* --- Bitmasks & Aliases --- */
// Bit 7 turns on the Port H clock gate
#define GPIOHEN             (1U << 7)
// Pin 7 mask for setting output states
#define PIN7                (1U << 7)
 //blue user LED
#define LED_PIN             PIN7

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  RCC_AHB4EN_R |= GPIOHEN; //enables clock for GPIO H
  GPIOH_MODE_R |= (1 << 14); //SET BIT 14 TO 1
  GPIOH_MODE_R &= ~(1 << 15); //SET BIT 15 TO 0
  while(1){
	  GPIOH_OD_R ^= LED_PIN; // Toggle the pin state
	  HAL_Delay(2000);
  }
}
