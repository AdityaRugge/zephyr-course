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

led_sensor_set_message(dev, "shell mode");
    printk("Sensor ready LED. Use the shell: sensor fetch/read/info\n");
    return 0;
}