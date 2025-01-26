#include "TIMER.h"

 
namespace TIMER{

    ledc_timer_config_t     timer::timer_config{};
    ledc_channel_config_t   timer::tim_channel_config{};    

    timer::timer(const gpio_num_t _ch = GPIO_NUM_14):
            _channelx{_ch}{
        ESP_LOGI(_log_tag, "%s:%d Constructor TIM", __func__, __LINE__); 
        ESP_LOGI(_log_tag, "%s:%d _channelsx{%d}", __func__, __LINE__, _ch);  
    };

    esp_err_t timer::init(void){
        return _init();
    }

    esp_err_t timer::_init(void){

        ESP_LOGI(_log_tag, "%s:%d Start_init_TIMER", __func__, __LINE__);
        esp_err_t status{ESP_OK};

        timer_config.duty_resolution = LEDC_TIMER_10_BIT;
        timer_config.freq_hz = 1600;
        timer_config.speed_mode = LEDC_LOW_SPEED_MODE;
        timer_config.timer_num = LEDC_TIMER_0;
        timer_config.clk_cfg = LEDC_AUTO_CLK;

        ESP_LOGI(_log_tag, "%s:%d Make ledc_timer_config", __func__, __LINE__);
        status |= ledc_timer_config(&timer_config);
        ESP_LOGI(_log_tag, "%s:%d ledc_timer_config:%s", __func__, __LINE__, esp_err_to_name(status));

        ESP_LOGI(_log_tag, "%s:%d Start_init_CHANNEL_TIMER", __func__, __LINE__);

        tim_channel_config.channel = LEDC_CHANNEL_1;
        tim_channel_config.duty = 0;
        tim_channel_config.gpio_num = _channelx;
        tim_channel_config.speed_mode = LEDC_LOW_SPEED_MODE;
        tim_channel_config.hpoint = 0;
        tim_channel_config.timer_sel = LEDC_TIMER_0;
        tim_channel_config.flags.output_invert = 1;
        
        ESP_LOGI(_log_tag, "%s:%d Make ledc_channel_config", __func__, __LINE__);
        status |= ledc_channel_config(&tim_channel_config);
        ESP_LOGI(_log_tag, "%s:%d ledc_timer_config:%s", __func__, __LINE__, esp_err_to_name(status));

        return 0;
    }

    esp_err_t timer::set_PWM_fade(uint32_t tg_duty){
        printf("LEDC fade up to duty = %d\n", (int)tg_duty);
        ledc_set_duty(tim_channel_config.speed_mode, 
                                tim_channel_config.channel,
                                tg_duty);
        return 0;
    }
    esp_err_t timer::update_PWM(void){
        ledc_update_duty(tim_channel_config.speed_mode, 
                            tim_channel_config.channel);
        return 0;
    }
}
