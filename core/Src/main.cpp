#include "main.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static MAIN my_main;
int potenciometer_read = 0;

extern "C" void app_main(void){
    ESP_LOGI(LOG_TAG, "Creating defaults event loop");
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_LOGI(LOG_TAG, "Init NVS");
    ESP_ERROR_CHECK(nvs_flash_init());

    ESP_ERROR_CHECK(my_main.setup());

    while (1){
        my_main.loop();
    }
    
}

esp_err_t MAIN::setup(void){
    esp_err_t status{ESP_OK};
    ESP_LOGI(LOG_TAG, "Setup");
    status |= led.init();

    // status |= wifi.init();
    // if(ESP_OK == status)
    //     status |= wifi.begin();

    // status |= I2c.init();
    // if(ESP_OK == status){
    //     status |= LCD_I2c.init(); 
    // }
    
    // status |= ADC.init();
    status |= PWM.init();
    
    return status;
}

void MAIN::loop(void){
    ESP_LOGI(LOG_TAG, "Hello World!");    
    ESP_LOGI(LOG_TAG, "Led_ON");  
    led.set(true);
    vTaskDelay(pdSecond);

    ESP_LOGI(LOG_TAG, "Led_OFF");  
    led.set(false);
    vTaskDelay(pdSecond);

    // for(int i = 0; i< 1022; ++i){
    //     PWM.set_PWM_fade(i);
    //     PWM.update_PWM();
    // }
    // vTaskDelay(pdSecond);
    // for(int i = 1022; i > 0; --i){
    //     PWM.set_PWM_fade(i);
    //     PWM.update_PWM();
    // }
    // ADC.get_adc_value(ADC_CHANNEL_2, potenciometer_read);
    // vTaskDelay(pdSecond);
    // ADC.get_adc_value(ADC_CHANNEL_3, potenciometer_read);
}
    