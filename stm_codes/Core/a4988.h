#ifndef A4988_H
#define A4988_H



// Pin tanımları
#define STEP_PIN GPIO_PIN_12
#define DIR_PIN  GPIO_PIN_13
#define ENA_PIN  GPIO_PIN_14
#define STEP_PORT GPIOD
#define DIR_PORT  GPIOD
#define ENA_PORT  GPIOD

// Fonksiyon prototipleri
void A4988_Init(void);
void A4988_SetSpeed(uint16_t speed);
void A4988_SetDirection(uint8_t direction);
void A4988_Enable(void);
void A4988_Disable(void);
void A4988_Step(void);

#endif // A4988_H
