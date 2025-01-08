#include "main.h"

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "MAIN"

static MAIN my_main;

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
    status |= wifi.init();

    if(ESP_OK == status)
        status |= wifi.begin();
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

}