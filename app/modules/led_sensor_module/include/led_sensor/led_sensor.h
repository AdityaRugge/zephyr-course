#ifndef LED_SENSOR_H
#define LED_SENSOR_H

#include <zephyr/device.h>

struct led_sensor_config {
    struct gpio_dt_spec led_gpio;
};

struct led_sensor_data {
    bool led_state;       
    int  toggle_count;   
};

#endif 