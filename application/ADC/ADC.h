#pragma once

#include "hal/adc_types.h"
#include "esp_adc/adc_oneshot.h"

#include "esp_log.h"
#include "esp_event.h"
#include "GPIO.h"

namespace ADC{
    constexpr static const char* _log_tag{"ADC"};

    class adc{
        // protected:
        //     const gpio_num_t _pin_scl;
        //     const gpio_num_t _pin_sda;
        public:
            //Конструктор
            adc(void);
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
        private:

            esp_err_t _init(void);
            static adc_oneshot_unit_init_cfg_t adc_config;
            static adc_oneshot_unit_handle_t adc_unit_handle;

    };
}//namespace ADC