#include "driver/i2c_master.h"

namespace I2C{

    class LCD_I2C{
        public:;
            esp_err_t init(void);

            LCD_I2C(void);
            ~LCD_I2C(void);
            LCD_I2C(const LCD_I2C&);
            LCD_I2C(LCD_I2C&&);
            LCD_I2C& operator=(const LCD_I2C&);
            LCD_I2C& operator=(LCD_I2C&&);
        private:
            static uint8_t address;
            
    };


}//namespace I2C