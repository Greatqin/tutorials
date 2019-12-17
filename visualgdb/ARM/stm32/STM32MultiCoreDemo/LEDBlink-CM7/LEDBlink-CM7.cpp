#include <stm32_hal_legacy.h>
#include <stm32h7xx_hal.h>

#ifdef __cplusplus
extern "C"
#endif
    void
    SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

int main(void)
{
    HAL_Init();

    __GPIOI_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.Pin = GPIO_PIN_12;

    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStructure);

    for (;;)
    {
        HAL_GPIO_WritePin(GPIOI, GPIO_PIN_12, GPIO_PIN_SET);
        HAL_Delay(500);
        HAL_GPIO_WritePin(GPIOI, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_Delay(500);
    }
}
