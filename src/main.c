#include <stm32l476xx.h>

int main(void) {
    // Enable clock access to GPIOA
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // Set pin 5 to output mode (0x10)
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;

    while (1) {
        // Wait some time
        for (int i = 0; i < 100000; i++) {
        }

        // Toggle pin using output data register
        GPIOA->ODR ^= GPIO_ODR_ODR_5;
    }
}