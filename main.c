

#include <stdbool.h>
#include <stdint.h>
#include <nrf_delay.h> 
#include <boards.h>
#include <nrf52840_mdk.h>



#define SSD1306_128_64

uint32_t dc = 7;
uint32_t rs = 6;
uint32_t cs = 8;
uint32_t clk = 4;
uint32_t mosi = 5;



int main(void)
{

    /* Configure board. */
    bsp_board_init(BSP_INIT_LEDS);

    /* Toggle LEDs. */
    while (true)
    {
        for (int i = 0; i < LEDS_NUMBER; i++)
        {
            bsp_board_led_invert(i);
            nrf_delay_ms(500);
        }
    }


}


