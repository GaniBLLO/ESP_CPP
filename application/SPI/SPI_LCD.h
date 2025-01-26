#pragma once

#include "SPI.h"

#include "esp_log.h"
#include "esp_event.h"

namespace SPI_LCD{
    constexpr static const char* _log_tag{"SPI_LCD"};
    
    class spi_lcd{
        private:
            SPI::spi& _spi_master;
            uint8_t LCD_address;
            uint8_t cur_col,cur_row;

            esp_err_t _init(void);
            
        public:
            spi_lcd(SPI::spi& spi_master);
            ~spi_lcd();

            esp_err_t init(void);

    };
}
