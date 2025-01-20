#include "SPI.h"
/*
   Пины для работы с экраном 
   CS________18
   MSIO______21
   MOSI______20
   CLK_______19                */

   
namespace SPI{

    spi_bus_config_t                spi::spi_config{};
    spi_device_interface_config_t   spi::spi_dev_interface_cfg{};
    spi::spi(const int CS = 18, const int MISO = 21, 
                const int MOSI = 20, const int CLK = 19):
            _CS{CS}, _MISO{MISO}, _MOSI{MOSI}, _CLK{CLK}{

          ESP_LOGI(_log_tag, "%s:%d Constructor SPI", __func__, __LINE__); 
          ESP_LOGI(_log_tag, "%s:%d _CS{%d}, _MISO{%d}, _MOSI{%d}, _CLK{%d}", __func__, __LINE__,
                           CS,MISO,MOSI,CLK);     
    }

    esp_err_t spi::init(void){
        return _init();
    }

    esp_err_t spi::_init(void){

        ESP_LOGI(_log_tag, "%s:%d Start_init_SPI", __func__, __LINE__);
        esp_err_t status{ESP_OK};

        spi_config.miso_io_num = _MISO;
        spi_config.mosi_io_num = _MOSI;
        spi_config.sclk_io_num = _CLK;

        ESP_LOGI(_log_tag, "%s:%d Make spi_bus_initialize", __func__, __LINE__);
        status |= spi_bus_initialize(SPI2_HOST, &spi_config,SPI_DMA_CH_AUTO);
        ESP_LOGI(_log_tag, "%s:%d spi_bus_initialize:%s", __func__, __LINE__, esp_err_to_name(status));

        ESP_LOGI(_log_tag, "%s:%d Start_init_device", __func__, __LINE__);
        if(ESP_OK == status){

            // spi_bus_add_device(SPI2_HOST,)

        }
        return 0;
    }
}
