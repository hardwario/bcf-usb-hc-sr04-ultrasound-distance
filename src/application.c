#include <application.h>

/*

Ultrasound example HC-SR04

Power:
If you use original HC-SR04 you need to power sensor with 5V.
On Core Module R2.3 and newer you can use +5V contact on PCB near the BOOT pin.
The TRIG signal and ECHO signals doesn't need any level converter. Sensor is OK with 3V input and MCU is ok with 5V input.

If you use 3V variant of this sensor, you can power it from the VCC 3.3V pin on the Core Module

Sensor connection:
===================
P8 - ECHO
P9 - TRIG

*/

// LED instance
twr_led_t led;

// Button instance
twr_button_t button;

twr_hc_sr04_t hc_sr04;

void button_event_handler(twr_button_t *self, twr_button_event_t event, void *event_param)
{
    if (event == TWR_BUTTON_EVENT_PRESS)
    {
        twr_led_set_mode(&led, TWR_LED_MODE_TOGGLE);
    }

    // Logging in action
    twr_log_info("Button event handler - event: %i", event);
}


void hc_sr04_event_handler(twr_hc_sr04_t *self, twr_hc_sr04_event_t event, void *event_param)
{

    float value;
    twr_log_info("Reading distance...");

    if (event != TWR_HC_SR04_EVENT_UPDATE)
    {
        twr_log_info("Problem with distance update");
        return;
    }

    if (twr_hc_sr04_get_distance_millimeter(&hc_sr04, &value))
    {
        twr_log_info("Distance update %f mm", value);
    }
    twr_led_set_mode(&led, TWR_LED_MODE_OFF);

}

void application_init(void)
{
    // Initialize logging
    twr_log_init(TWR_LOG_LEVEL_DUMP, TWR_LOG_TIMESTAMP_ABS);

    // Initialize LED
    twr_led_init(&led, TWR_GPIO_LED, false, false);
    twr_led_pulse(&led, 2000);

    // Initialize button
    twr_button_init(&button, TWR_GPIO_BUTTON, TWR_GPIO_PULL_DOWN, false);
    twr_button_set_event_handler(&button, button_event_handler, NULL);

    twr_hc_sr04_init(&hc_sr04, TWR_GPIO_P9, TWR_HC_SR04_ECHO_P8);
    twr_hc_sr04_set_event_handler(&hc_sr04, hc_sr04_event_handler, NULL);
    twr_hc_sr04_set_update_interval(&hc_sr04, 500);
}
