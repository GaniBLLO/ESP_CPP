set(SOURCES TIMER.cpp)
idf_component_register(SRCS ${SOURCES}
                            INCLUDE_DIRS .
                            REQUIRES driver esp_event)
