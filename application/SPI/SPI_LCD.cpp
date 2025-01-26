#include "SPI_LCD.h"


namespace SPI_LCD{
    spi_lcd::spi_lcd(SPI::spi& spi_master): 
        _spi_master{spi_master}{
    }

    esp_err_t spi_lcd::init(void){
        return _init();
    }
}