#include "ADC.h"

namespace ADC{
    adc_oneshot_unit_init_cfg_t   adc::adc_config{};
    adc_oneshot_unit_handle_t     adc::adc_unit_handle{};
    
    //Конструктор
    adc::adc(void){;}

    esp_err_t adc::init(void){
        return _init();
    }

    esp_err_t adc::_init(void){

        ESP_LOGI(_log_tag, "%s:%d Start_init_ADC", __func__, __LINE__);
        
        esp_err_t status{ESP_OK};

        return status;
    }

}