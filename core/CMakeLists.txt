set(SOURCES ./Src/main.cpp)
idf_component_register(SRCS ${SOURCES}
                            INCLUDE_DIRS . Inc
                            REQUIRES freertos 
                                        esp_common 
                                        esp_event
                                        nvs_flash
                                        GPIO
                                        I2C
                                        SPI
                                        ADC
                                        Wifi)
