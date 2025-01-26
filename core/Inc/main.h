#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define pdSecond pdMS_TO_TICKS(1000)

#include "esp_event.h"
#include "nvs_flash.h"

#include "GPIO.h"
#include "Wifi.h"
#include "I2C.h"
#include "LCD_1602.h"
#include "SPI.h"
#include "ADC.h"
#include "TIMER.h"

/*===========================================SPI Not yet*/ 
#define SPI_CS      18
#define SPI_MISO    21
#define SPI_MOSI    20
#define SPI_CLK     19

/*===========================================SPI_LCD Not yet*/ 
#define A0_LCD      GPIO_NUM_16
#define RST_LCD     GPIO_NUM_17

/*===========================================I2C*/
#define I2C_SCL     GPIO_NUM_7
#define I2C_SDA     GPIO_NUM_6

/*===========================================ADC*/
#define ADC_CH2     ADC_CHANNEL_2
#define ADC_CH3     ADC_CHANNEL_3

/*====================================GPIO_INPUT*/
#define PIN_22      GPIO_NUM_22
#define PIN_23      GPIO_NUM_23

/*======================================GPIO_PWM*/
#define PIN_15      GPIO_NUM_15


class MAIN final{
    public:
        esp_err_t setup(void);
        void loop(void);

        Gpio::GPIOOutput    led{GPIO_NUM_8, false};
        WIFI::Wifi          wifi;
        I2C::i2c            I2c{I2C_SCL, I2C_SDA};
        LCD_I2C::LCD_i2c    LCD_I2c{I2c};
        SPI::spi            SPi{SPI_CS, SPI_MISO, SPI_MOSI, SPI_CLK};
        ADC::adc            ADC{ADC_CH2, ADC_CH3};
        TIMER::timer        PWM{PIN_15};
};


