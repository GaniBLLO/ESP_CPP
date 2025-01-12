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

class MAIN final{
    public:
        esp_err_t setup(void);
        void loop(void);

        Gpio::GPIOOutput led{GPIO_NUM_8, false};
        WIFI::Wifi wifi;
        I2C::i2c I2c{GPIO_NUM_7, GPIO_NUM_6};
        LCD_I2C::LCD_i2c LCD_I2c{I2c};
};


