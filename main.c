
#define SSD1306_128_64
#include <stdbool.h>
#include <stdint.h>
#include <nrf_delay.h> 
#include <boards.h>
#include <nrf52840_mdk.h>
#include <ssd1306.h>

#define SSD1306_CONFIG_CLK_PIN      4
#define SSD1306_CONFIG_MOSI_PIN     5
#define SSD1306_CONFIG_CS_PIN       8
#define SSD1306_CONFIG_DC_PIN       7
#define SSD1306_CONFIG_RST_PIN      6

//#define SSD1306_CONFIG_SCL_PIN      27
//#define SSD1306_CONFIG_SDA_PIN      26


int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);
    bsp_board_led_invert(1);
    nrf_delay_ms(1000);
    bsp_board_led_invert(1);
    ssd1306_init(SSD1306_CONFIG_DC_PIN,
                 SSD1306_CONFIG_RST_PIN,
                 SSD1306_CONFIG_CS_PIN,
                 SSD1306_CONFIG_CLK_PIN,
                 SSD1306_CONFIG_MOSI_PIN);

    ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS, false);

    ssd1306_display();
    ssd1306_draw_circle(SSD1306_LCDWIDTH / 2, SSD1306_LCDHEIGHT / 2, 30, WHITE);
    ssd1306_display();

    /* Configure board. */
    

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


