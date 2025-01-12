set(SOURCES I2C.cpp LCD_1602.cpp)
idf_component_register(SRCS ${SOURCES}
                            INCLUDE_DIRS .
                            REQUIRES driver esp_event GPIO )
