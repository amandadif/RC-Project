//
// Created by Amanda on 5/30/2025.
//

#ifndef RCCARPROJECT_SERVO_H
#define RCCARPROJECT_SERVO_H
#ifndef SERVO_H
#define SERVO_H
#include <cstdint>

class Servo {
public:
    Servo(unsigned int gpio_pin);
    void setPulseUs(uint16_t us);  // Range: 1000–2000 µs
private:
    unsigned int _pin;
};

#endif

#endif //RCCARPROJECT_SERVO_H
