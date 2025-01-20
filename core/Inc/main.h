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

/*===========================================SPI*/
#define SPI_CS      18
#define SPI_MISO    21
#define SPI_MOSI    20
#define SPI_CLK     19

/*===========================================I2C*/
#define I2C_SCL     GPIO_NUM_7
#define I2C_SDA     GPIO_NUM_6

/*===========================================ADC*/



class MAIN final{
    public:
        esp_err_t setup(void);
        void loop(void);

        Gpio::GPIOOutput    led{GPIO_NUM_8, false};
        WIFI::Wifi          wifi;
        I2C::i2c            I2c{I2C_SCL, I2C_SDA};
        LCD_I2C::LCD_i2c    LCD_I2c{I2c};
        SPI::spi            SPi{SPI_CS, SPI_MISO, SPI_MOSI, SPI_CLK};
};


