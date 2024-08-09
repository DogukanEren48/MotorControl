#ifndef MOTOR_COMMAND_H
#define MOTOR_COMMAND_H

#include <stdint.h>


typedef enum {
    DIRECTION_CLOCKWISE,
    DIRECTION_COUNTERCLOCKWISE
} MotorDirection;

#pragma pack(push, 1)
typedef struct {
    uint16_t speed;
    MotorDirection direction;
    uint16_t angle;
    uint16_t duration;
    uint16_t turns;
    uint16_t MyCRC;  // CRC kontrolü için
} MotorCommand;
#pragma pack(pop)

typedef union {
    MotorCommand command;
    uint8_t rawData[sizeof(MotorCommand)];
} CommandUnion;

#endif // MOTOR_COMMAND_H


void set_Motor_Speed(uint16_t speed);
void set_Motor_Direction(MotorDirection direction);
void move_Motor_ToAngle(uint16_t angle);
void set_Motor_Duration(uint16_t duration);
void set_Motor_Turns(uint16_t turns);
