#pragma once

#include "hal/adc_types.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"

#include "esp_log.h"
#include "esp_event.h"
#include "GPIO.h"

namespace ADC{
    constexpr static const char* _log_tag{"ADC"};

    class adc{
        protected:
            const adc_channel_t _adc_ch_2;
            const adc_channel_t _adc_ch_3;
        public:
            //Конструктор
            adc(const adc_channel_t _adc_ch_2, const adc_channel_t _adc_ch_3);
            //Деструктор
            ~adc(void);
            //Конструктор копирования
            adc(const adc&);
            //Конструктор перемещения
            adc(adc&&);
            //Опрератор присваивания с копированием
            adc& operator=(const adc&);
            //Опрератор присваивания с перемещением
            adc& operator=(adc&&);

            esp_err_t init(void);
            esp_err_t get_adc_value(adc_channel_t _channel, int buff);
            esp_err_t get_adc_voltage(adc_channel_t _channel, int adc_value, int buff);
            
        private:
            esp_err_t _init(void);
            static adc_oneshot_unit_init_cfg_t      adc_config;
            static adc_oneshot_unit_handle_t        adc_unit_handle;

            static adc_oneshot_chan_cfg_t           adc_config_channel;

            static adc_cali_curve_fitting_config_t  adc_callibration;
            static adc_cali_handle_t                adc_callibration_handle;
    };
}//namespace ADC