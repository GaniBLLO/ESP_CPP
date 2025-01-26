set(SOURCES SPI.cpp SPI_LCD.cpp)
idf_component_register(SRCS ${SOURCES}
                            INCLUDE_DIRS .
                            REQUIRES driver esp_event)
