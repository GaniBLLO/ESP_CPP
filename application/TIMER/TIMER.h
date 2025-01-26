#pragma once 

#include "driver/ledc.h"

#include "esp_log.h"
#include "esp_event.h"

namespace TIMER{
    constexpr static const char* _log_tag{"TIMER"};
    
    class timer{
        protected:
            const gpio_num_t _channelx;
        private:
            esp_err_t _init(void);

            static ledc_timer_config_t      timer_config;
            static ledc_channel_config_t    tim_channel_config;
        public:
            timer(const gpio_num_t _ch);
            ~timer();

            esp_err_t set_PWM_fade(uint32_t tg_duty);
            esp_err_t update_PWM(void);
            esp_err_t init(void);

    };
}
