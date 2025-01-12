#include "LCD_1602.h"


// Clear Display
constexpr int HD44780_CLEAR_DISPLAY                     {0b00000001};

// Return Home 1.52 ms
constexpr uint8_t HD44780_CURSOR_HOME                   {0b00000010};

// Entry Mode Set 37 µs
constexpr uint8_t HD44780_ENTRY_MODE_SET                {0b00000100};
    constexpr uint8_t HD44780_ACCOMPANIES_DISPLAY_SHIFT	{0b00000001};
    constexpr uint8_t HD44780_ENTRY_SHIFTINCREMENT      {0b00000010};
    //constexpr uint8_t HD44780_ENTRY_SHIFTDECREMENT    {0b00000000};

// Display ON/OFF control 37 µs
constexpr uint8_t HD44780_DISPLAY_CONTROL               {0b00001000};
    constexpr uint8_t HD44780_BLINK_ON                  {0b00000001};
    constexpr uint8_t HD44780_CURSOR_ON                 {0b00000010};
    constexpr uint8_t HD44780_DISPLAY_ON                {0b00000100};

// Cursor or Display Shift 37 µs
constexpr uint8_t HD44780_CURSOR_OR_DISPLAY_SHIFT       {0b00010000};
    constexpr uint8_t HD44780_SHIFT_RIGHT               {0b00000100};
    //constexpr uint8_t HD44780_SHIFT_LEFT              {0b00000000};
    constexpr uint8_t HD44780_DISPLAY_SHIFT             {0b00001000};
    //constexpr uint8_t HD44780_CURSOR_MOVE             {0b00000000};

// Function Set 37 µs
constexpr uint8_t HD44780_FUNCTION_SET                  {0b00100000};
    constexpr uint8_t HD44780_5x10_DOTS                 {0b00000100};
    constexpr uint8_t HD44780_5x8_DOTS                  {0b00000000};
    constexpr uint8_t HD44780_2_LINE                    {0b00001000};
    constexpr uint8_t HD44780_1_LINE                    {0b00000000};
    constexpr uint8_t HD44780_8_BIT_MODE                {0b00010000};
    constexpr uint8_t HD44780_4_BIT_MODE                {0b00000000};

constexpr int HD44780_SET_CGRAM_ADDR                    {0b01000000};
constexpr int HD44780_SET_DDRRAM_ADDR                   {0b10000000};


namespace LCD_I2C{
    i2c_device_config_t         LCD_i2c::i2c_dev_config{};
    i2c_master_dev_handle_t     LCD_i2c::i2c_dev_handle{};

    LCD_i2c::LCD_i2c(I2C::i2c& i2c_master):_i2c_master{i2c_master}{
        ESP_LOGI(_log_tag, "%s:%d Constructor LCD_", __func__, __LINE__);
        LCD_address = 0xff;
        cur_col = 16;
        cur_row = 2;
    };

    esp_err_t LCD_i2c::init(void){
        return _init();
    };

    uint8_t LCD_i2c::find_address(void){
        esp_err_t status{ESP_OK};

        for(uint8_t i = 3; i < 0xFF; ++i){
            status = i2c_master_probe(_i2c_master.get_bus_handle(), i, 1000);
            if(status == ESP_OK){
                return i;
            }
        }
        ESP_LOGE(_log_tag, "%s:%d No devices found!", __func__, __LINE__);
        return 0xFF;
    };

    esp_err_t LCD_i2c::_init(void){

        ESP_LOGI(_log_tag, "%s:%d Start_init_LCD1602", __func__, __LINE__);
        esp_err_t status{ESP_OK};

        ESP_LOGI(_log_tag, "%s:%d Searching address", __func__, __LINE__);
        LCD_address = find_address();
        ESP_LOGI(_log_tag, "%s:%d Slave address: 0x%X", __func__, __LINE__, LCD_address);
       
        if(ESP_OK == status){
            i2c_dev_config.dev_addr_length = I2C_ADDR_BIT_LEN_7;
            i2c_dev_config.device_address = LCD_address;
            i2c_dev_config.scl_speed_hz = 100000;
            
            ESP_LOGI(_log_tag, "%s:%d Make i2c_master_bus_add_device", __func__, __LINE__);
            status |= i2c_master_bus_add_device(_i2c_master.get_bus_handle(),
                                                            &i2c_dev_config,
                                                            &i2c_dev_handle);
            ESP_LOGI(_log_tag, "%s:%d i2c_master_bus_add_device:%s", __func__, __LINE__, esp_err_to_name(status));
        }
        return status;
    };

}