#include "GPIO.h"

namespace Gpio{
    [[nodiscard]] esp_err_t GPIOBase::init(void){
        esp_err_t status{ESP_OK};
        
        status |= gpio_config(&_cfg);
        return status;
    }

    [[nodiscard]] esp_err_t GPIOOutput::init(void){
        esp_err_t status{GPIOBase::init()};
        if(ESP_OK == status)
            status |= set(_invert_logic);
            
        return status;
    }

    esp_err_t GPIOOutput::set(const bool state){
        _state = state;
        return gpio_set_level(_pin, _invert_logic ? !state : state);
    }
}