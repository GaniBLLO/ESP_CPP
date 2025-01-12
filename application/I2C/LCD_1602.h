#pragma once

#include "I2C.h"
#include "driver/i2c_master.h"
#include "esp_log.h"
#include "esp_event.h"

namespace LCD_I2C{
    constexpr static const char* _log_tag{"LCD_I2C"};
    
    class LCD_i2c{
        private:
            I2C::i2c& _i2c_master;
            uint8_t LCD_address;
            uint8_t cur_col,cur_row;

            esp_err_t _init(void);
            static i2c_device_config_t i2c_dev_config;
            static i2c_master_dev_handle_t i2c_dev_handle;
            
        public:
            enum class i2c_state_e{
                CHECKING_ADDRESS,
                LCD_CONNECTED,
                BUSY,
                ERROR 
            };
            LCD_i2c(I2C::i2c& i2c_master);
            ~LCD_i2c();

            esp_err_t init(void);
            uint8_t find_address(void);
            // void setCursor(uint8_t col, uint8_t row);
            // void home(void);
            // void clear(void);
            // void writeChar(char c);
            // void print(std::string str) const;
            // void print(int i) const; 
            // void print(char c) const;

            // void println(std::string str);
            // void println(int i);
            // void println(char c);

    };
}
