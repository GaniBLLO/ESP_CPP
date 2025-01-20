#pragma once

#include "driver/spi_common.h"
#include "driver/spi_master.h"
#include "esp_log.h"

namespace SPI{
    constexpr static const char* _log_tag{"SPI"};

    class spi{
        protected:
            const int _CS;
            const int _MISO;
            const int _MOSI;
            const int _CLK;

        private:

            esp_err_t _init(void);

            static spi_bus_config_t                 spi_config;
            static spi_device_interface_config_t    spi_dev_interface_cfg;
        public:
            //Конструктор
            spi(const int CS, const int MISO, const int MOSI, const int CLK);
            //Деструктор
            ~spi(void);
            //Конструктор копирования
            spi(const spi&);
            //Конструктор перемещения
            spi(spi&&);
            //Опрератор присваивания с копированием
            spi& operator=(const spi&);
            //Опрератор присваивания с перемещением
            spi& operator=(spi&&);


            esp_err_t init(void);
    };
}