#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

//#define SLEEP_TIME_MS 1000

/* The devicetree node identifier for the "led0" alias.  :build/zephyr/zephyr.dts  */

//#define LED_NODE DT_ALIAS(led0)      // Use the 'led0' alias defined in the board/board overlay
//#define LED_NODE DT_NODELABEL(led_0)   // Use the 'led_0' node label defined in the board/board overlay
//#define LED_NODE DT_PATH(leds, led_0) // Use the path to the 'led_0' node defined in the board/board overlay
#define LED_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios); ///* node '/leds/led_0' defined in ../zephyr-course/app/boards/nucleo_f446re.overlay:4 */

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    bool led_state = true;

    if (!gpio_is_ready_dt(&led)) return 0;

    if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0) return 0;

    while (1) {
        if (gpio_pin_toggle_dt(&led) < 0) return 0;

        led_state = !led_state;
        LOG_INF("LED state: %s", led_state ? "ON" : "OFF");
        //k_msleep(SLEEP_TIME_MS);
       
        //k_msleep(CONFIG_BLINK_SLEEP_TIME_MS);  // Use the value from Kconfig for BLINK_SLEEP_TIME_MS : Task 3
        k_msleep(CONFIG_APP_HEARTBEAT_PERIOD_MS);  // Use the value from Kconfig for APP_HEARTBEAT_PERIOD_MS : Task 4       
    }
    return 0;
}
