#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <led_sensor/led_sensor.h>

int main(void)
{
    const struct device *dev = DEVICE_DT_GET(DT_NODELABEL(led_sensor_0));

    if (!device_is_ready(dev)) {
        printk("LED Sensor is not ready\n");
        return -ENODEV;
    }

    /* Task 2: API custom */
    led_sensor_set_message(dev, "Hello from main!");
    led_sensor_set_toggle_count(dev, 5);

    while (1) {

        sensor_sample_fetch(dev);
        k_sleep(K_MSEC(500));

        struct sensor_value val;
        sensor_channel_get(dev, SENSOR_CHAN_ALL, &val);
        k_sleep(K_MSEC(500));
    }
    return 0;
}