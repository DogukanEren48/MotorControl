#include "a4988.h"

void A4988_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // GPIO Ports Clock Enable
    __HAL_RCC_GPIOD_CLK_ENABLE();

    // Configure GPIO pins
    GPIO_InitStruct.Pin = STEP_PIN | DIR_PIN | ENA_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Disable motor by default
    A4988_Disable();
}

void A4988_SetSpeed(uint16_t speed)
{

}

void A4988_SetDirection(uint8_t direction)
{
    HAL_GPIO_WritePin(DIR_PORT, DIR_PIN, direction ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void A4988_Enable(void)
{
    HAL_GPIO_WritePin(ENA_PORT, ENA_PIN, GPIO_PIN_RESET); // Enable pin low to enable
}

void A4988_Disable(void)
{
    HAL_GPIO_WritePin(ENA_PORT, ENA_PIN, GPIO_PIN_SET); // Enable pin high to disable
}

void A4988_Step(void)
{
    HAL_GPIO_WritePin(STEP_PORT, STEP_PIN, GPIO_PIN_SET);
    HAL_Delay(1); // 1 ms delay
    HAL_GPIO_WritePin(STEP_PORT, STEP_PIN, GPIO_PIN_RESET);
    HAL_Delay(1); // 1 ms delay
}
