#ifndef LED_SENSOR_H
#define LED_SENSOR_H

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

struct led_sensor_config {
    struct gpio_dt_spec led_gpio;
};

struct led_sensor_data {
    bool led_state;
    int  toggle_count;
    char message[64];
};

#ifdef __cplusplus
extern "C" {
#endif

int led_sensor_set_message(const struct device *dev, const char *msg);
int led_sensor_set_toggle_count(const struct device *dev, int count);

#ifdef __cplusplus
}
#endif

#endif 