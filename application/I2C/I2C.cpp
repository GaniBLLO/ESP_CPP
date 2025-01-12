#include "I2C.h"

namespace I2C{
    //Инициализурем начальное состояние I2Cx 
    i2c::i2c_state_e            i2c::_i2c_state{i2c_state_e::I2C_NOT_INITED};
    i2c_master_bus_config_t     i2c::i2c_config{};
    i2c_master_bus_handle_t     i2c::i2c_bus_handle{};
    
    //Конструктор
    i2c::i2c(const gpio_num_t _scl = GPIO_NUM_7, const gpio_num_t _sda = GPIO_NUM_6):
        _pin_scl{_scl},
        _pin_sda{_sda}{
    }//ToDo smth

    esp_err_t i2c::init(void){
        return _init();
    }

    esp_err_t i2c::_init(void){

        ESP_LOGI(_log_tag, "%s:%d Start_init_I2C", __func__, __LINE__);
        
        esp_err_t status{ESP_OK};

        if(i2c_state_e::I2C_NOT_INITED == _i2c_state){
            
            if(ESP_OK == status){
                i2c_config.clk_source    = I2C_CLK_SRC_DEFAULT;
                i2c_config.i2c_port      = I2C_NUM_0;
                i2c_config.scl_io_num    = _pin_scl;
                i2c_config.sda_io_num    = _pin_sda;
                i2c_config.glitch_ignore_cnt = 7;
                i2c_config.flags.enable_internal_pullup = true;

                ESP_LOGI(_log_tag, "%s:%d Calling i2c_new_master_bus", __func__, __LINE__);
                status |= i2c_new_master_bus(&i2c_config, &i2c_bus_handle);
                ESP_LOGI(_log_tag, "%s:%d i2c_new_master_bus:%s", __func__, __LINE__, esp_err_to_name(status));

            };
            if(ESP_OK == status){
                ESP_LOGI(_log_tag, "%s:%d I2C INITED", __func__, __LINE__);
                _i2c_state = i2c_state_e::INITED;
            }
        }else if(i2c_state_e::ERROR == _i2c_state){
            ESP_LOGE(_log_tag, "%s:%d FAILED", __func__, __LINE__);
            status = ESP_FAIL;
        }
        return status;
    }

}