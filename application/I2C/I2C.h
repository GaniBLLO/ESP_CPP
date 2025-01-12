#pragma once

#include "driver/i2c_master.h"
#include "esp_log.h"
#include "esp_event.h"
#include "GPIO.h"

namespace I2C{
    constexpr static const char* _log_tag{"I2C"};

    class i2c{
        protected:
            const gpio_num_t _pin_scl;
            const gpio_num_t _pin_sda;
        public:
            enum class i2c_state_e{
                I2C_NOT_INITED,
                INITED,
                ERROR 
            };
            //Конструктор
            i2c(const gpio_num_t _scl, const gpio_num_t _sda);
            //Деструктор
            ~i2c(void);
            //Конструктор копирования
            i2c(const i2c&);
            //Конструктор перемещения
            i2c(i2c&&);
            //Опрератор присваивания с копированием
            i2c& operator=(const i2c&);
            //Опрератор присваивания с перемещением
            i2c& operator=(i2c&&);

            esp_err_t init(void);

            constexpr const i2c_state_e& get_state(void){
                return _i2c_state;
            }

            static i2c_master_bus_handle_t get_bus_handle(void) {
                return i2c_bus_handle;
            }
            gpio_num_t get_sda(void){
                return _pin_sda;
            }
            gpio_num_t get_scl(void){
                return _pin_scl;
            }
        private:
            static i2c_state_e _i2c_state;
        
            esp_err_t _init(void);
            static i2c_master_bus_config_t i2c_config;
            static i2c_master_bus_handle_t i2c_bus_handle;

    };


}//namespace I2C