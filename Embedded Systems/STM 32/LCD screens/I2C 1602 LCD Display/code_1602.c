
//GETTING STARTED
// First in pinout configuration under connectivity select I2C1
// For mode select I2C
// Configure pins for SDA and SCL (tbh i dont think it matters what you set them to).
//************************** */
// in core/Inc put liquidcrystal_i2c.h | In that header file make sure to include the correct _hal.h
//In the same header fille go to line 58 and set address to 0x27 << 1 or 0x3F << 1 based on lcd screen model.
//in core/Src put liquidcrystal_i2c.c (use the file from first practice project since it has the correct DelayUS. Although its using hal_getTick which is not as percise as SysTick or using one of the pins).
// ********************************
//In main.c under int main(void) make sure to do MX_I2C1_Init();


//CODE: extras
//delay function using hal get tick
static void DelayUS(uint32_t us) {
  uint32_t start = HAL_GetTick();// Get current time in milliseconds
  uint32_t delay_ms = us / 1000;// Convert microseconds to milliseconds
  uint32_t target = start + delay_ms;
  while (HAL_GetTick() < target); // Wait until the time has elapsed
}

//better precision (without using a hardware timer), BUT SysTick must be properly configured beforehand
static void DelayUS(uint32_t us) {
    uint32_t start = SysTick->VAL;
    uint32_t ticks = (us * (SystemCoreClock / 1000000));  // Convert µs to clock cycles
    while ((start - SysTick->VAL) < ticks);  // Wait for cycles to pass
}

//using hardware timer(BEST)
// Enable TIM1 as a base timer.
// Set Prescaler so that TIM1 counts in 1µs increments.
#include "stm32f0xx_hal.h"  // Include HAL library

extern TIM_HandleTypeDef htim1;  // Use a timer, e.g., TIM1

static void DelayUS(uint32_t us) {
    __HAL_TIM_SET_COUNTER(&htim1, 0);  // Reset TIM1 counter
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);  // Wait until counter reaches 'us'
}
