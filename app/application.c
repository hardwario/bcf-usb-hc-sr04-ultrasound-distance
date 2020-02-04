#include <application.h>

/*

Ultrasound example HC-SR04

Power:
If you use original HC-SR04 you need to power sensor with 5V.
On Core Module R2.3 and nwer you can use +5V contact on PCB near the BOOT pin.
The TRIG signal and ECHO signals doesn't need any level converter. Sensor is OK with 3V input and MCU is ok with 5V input.

If you use 3V variant of this sensor, you can power it from the VCC 3.3V pin on the Core Module

Sensor connection:
===================
P8 - ECHO
P9 - TRIG

*/

// LED instance
bc_led_t led;

// Button instance
bc_button_t button;

void button_event_handler(bc_button_t *self, bc_button_event_t event, void *event_param)
{
    if (event == BC_BUTTON_EVENT_PRESS)
    {
        bc_led_set_mode(&led, BC_LED_MODE_TOGGLE);
    }

    // Logging in action
    bc_log_info("Button event handler - event: %i", event);
}


void hc_sr04_event_handler(bc_hc_sr04_event_t event, void *event_param)
{

    float value;
    bc_log_info("Reading distance...");

    if (event != BC_HC_SR04_EVENT_UPDATE)
    {
        bc_log_info("Problem with distance update");
        return;
    }

    if (bc_hc_sr04_get_distance_millimeter(&value))
    {
        bc_log_info("Distance update %f mm", value);
    }
    bc_led_set_mode(&led, BC_LED_MODE_OFF);

}

void application_init(void)
{
    // Initialize logging
    bc_log_init(BC_LOG_LEVEL_DUMP, BC_LOG_TIMESTAMP_ABS);

    // Initialize LED
    bc_led_init(&led, BC_GPIO_LED, false, false);
    bc_led_pulse(&led, 2000);

    // Initialize button
    bc_button_init(&button, BC_GPIO_BUTTON, BC_GPIO_PULL_DOWN, false);
    bc_button_set_event_handler(&button, button_event_handler, NULL);

    bc_hc_sr04_init();
    bc_hc_sr04_set_event_handler(hc_sr04_event_handler, NULL);
    bc_hc_sr04_set_update_interval(500);
}
