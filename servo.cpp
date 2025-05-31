#include <cstdint>
#include "Servo.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"

static uint16_t usToPwmLevel(uint16_t us) {
    return (us * 125) / 10;  // Based on 64 clkdiv and wrap=24999
}

Servo::Servo(unsigned int gpio_pin) {
    _pin = gpio_pin;
    gpio_set_function(_pin, GPIO_FUNC_PWM);
    unsigned int slice = pwm_gpio_to_slice_num(_pin);
    pwm_config cfg = pwm_get_default_config();
    pwm_config_set_clkdiv(&cfg, 64.0f);
    pwm_config_set_wrap(&cfg, 24999);
    pwm_init(slice, &cfg, true);
}

void Servo::setPulseUs(uint16_t us) {
    unsigned int slice = pwm_gpio_to_slice_num(_pin);
    unsigned int channel = pwm_gpio_to_channel(_pin);
    pwm_set_chan_level(slice, channel, usToPwmLevel(us));
}

