#include <stdio.h>
#include "pico/stdlib.h"

#define BTA 05
#define BTB 06
#define LED 11

uint taxa = 1000;

void alterarTaxaLed(uint gpio, uint32_t events)
{
    if (gpio == BTA && taxa < 1900)
    {
        taxa += 100;
        printf("| Taxa = %d |\n", taxa);
    }
    if (gpio == BTB && taxa > 100)
    {
        taxa -= 100;
        printf("| Taxa = %d |\n", taxa);
    }
}

int main()
{
    stdio_init_all();

    gpio_set_function(BTA, GPIO_FUNC_SIO);
    gpio_set_dir(BTA, GPIO_IN);
    gpio_pull_up(BTA);
    gpio_set_irq_enabled_with_callback(BTA, GPIO_IRQ_EDGE_RISE, true, &alterarTaxaLed);

    gpio_set_function(BTB, GPIO_FUNC_SIO);
    gpio_set_dir(BTB, GPIO_IN);
    gpio_pull_up(BTB);
    gpio_set_irq_enabled_with_callback(BTB, GPIO_IRQ_EDGE_RISE, true, &alterarTaxaLed);

    gpio_init(LED);
    gpio_set_dir(LED, true);

    while (true)
    {

        gpio_put(LED, true);
        sleep_ms(taxa);
        gpio_put(LED, false);
        sleep_ms(taxa);
    }

    return 0;
}
