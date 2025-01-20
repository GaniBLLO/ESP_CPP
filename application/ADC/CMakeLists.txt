set(SOURCES ADC.cpp)
idf_component_register(SRCS ${SOURCES}
                            INCLUDE_DIRS .
                            REQUIRES driver esp_adc esp_event GPIO )
