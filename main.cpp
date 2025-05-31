#include "pico/stdlib.h"
#include "Servo.h"

int main() {
    stdio_init_all();
    Servo steering(15);

    while (true) {
        steering.setPulseUs(1500);
        sleep_ms(1000);
        steering.setPulseUs(1000);
        sleep_ms(1000);
        steering.setPulseUs(2000);
        sleep_ms(1000);
    }
}
