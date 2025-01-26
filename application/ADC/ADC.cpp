#include "ADC.h"

namespace ADC{
    adc_oneshot_unit_init_cfg_t     adc::adc_config{};
    adc_oneshot_unit_handle_t       adc::adc_unit_handle{};
    adc_oneshot_chan_cfg_t          adc::adc_config_channel{};
    adc_cali_curve_fitting_config_t adc::adc_callibration{};
    adc_cali_handle_t               adc::adc_callibration_handle{};
    
    //Конструктор
    adc::adc(const adc_channel_t _adc_ch_2def = ADC_CHANNEL_2, const adc_channel_t _adc_ch_3def = ADC_CHANNEL_3):
        _adc_ch_2{_adc_ch_2def},
        _adc_ch_3{_adc_ch_3def}{
            ;
    }

    esp_err_t adc::init(void){
        return _init();
    }

    esp_err_t adc::_init(void){

        ESP_LOGI(_log_tag, "%s:%d Start_init_ADC", __func__, __LINE__);
        
        esp_err_t status{ESP_OK};

        adc_config.unit_id = ADC_UNIT_1;
        adc_config.ulp_mode = ADC_ULP_MODE_DISABLE;

        ESP_LOGI(_log_tag, "%s:%d Calling adc_oneshot_new_unit", __func__, __LINE__);
        status |= adc_oneshot_new_unit(&adc_config, &adc_unit_handle);
        ESP_LOGI(_log_tag, "%s:%d adc_oneshot_new_unit:%s", __func__, __LINE__, esp_err_to_name(status));

        ESP_LOGI(_log_tag, "%s:%d ADC channels init", __func__, __LINE__);
        adc_config_channel.bitwidth = ADC_BITWIDTH_DEFAULT;
        adc_config_channel.atten = ADC_ATTEN_DB_12;


        ESP_LOGI(_log_tag, "%s:%d Calling adc_oneshot_config_channel", __func__, __LINE__);
        status |= adc_oneshot_config_channel(adc_unit_handle, _adc_ch_2, &adc_config_channel);
        ESP_LOGI(_log_tag, "%s:%d adc_oneshot_config_channel 2 INITED!:%s", __func__, __LINE__, esp_err_to_name(status));
        status |= adc_oneshot_config_channel(adc_unit_handle, _adc_ch_3, &adc_config_channel);
        ESP_LOGI(_log_tag, "%s:%d adc_oneshot_config_channel 3 INITED!:%s", __func__, __LINE__, esp_err_to_name(status));
        

        adc_callibration.unit_id = ADC_UNIT_1;
        adc_callibration.atten = ADC_ATTEN_DB_12;
        adc_callibration.bitwidth = ADC_BITWIDTH_DEFAULT;
        
        ESP_LOGI(_log_tag, "%s:%d Calling ADC_callibration", __func__, __LINE__);
        status |= adc_cali_create_scheme_curve_fitting(&adc_callibration, &adc_callibration_handle);
        ESP_LOGI(_log_tag, "%s:%d ADC_callibration success!", __func__, __LINE__);

        if(ESP_OK == status){
            ESP_LOGI(_log_tag, "%s:%d ADC INITED", __func__, __LINE__);
        }
        return status;
    }

    esp_err_t adc::get_adc_value(adc_channel_t _channel, int buff){
        adc_oneshot_read(adc_unit_handle, _channel, &buff);
        ESP_LOGI(_log_tag, "ADC%d Channel[%d] Raw Data: %d", ADC_UNIT_1+1, _channel, buff);
        return 0;
    }

    esp_err_t adc::get_adc_voltage(adc_channel_t _channel, int adc_value, int buff){
        adc_cali_raw_to_voltage(adc_callibration_handle, adc_value ,&buff);
        ESP_LOGI(_log_tag, "ADC%d Channel[%d] Cali Voltage: %d mV", ADC_UNIT_1 + 1, _channel, buff);
        return 0;
    }
    
    
}