#pragma once

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_mac.h"

#include <algorithm>
#include <mutex>
#include <cstring>
// #include "freertos/FreeRTOS.h"
// #include "freertos/semphr.h"

#define pdSecond pdMS_TO_TICKS(1000)

namespace WIFI{
    constexpr static const char* _log_tag{"WiFi"};

    constexpr static const char* ssid{"TP-LINK_0392"};
    constexpr static const char* password{"87919097"};

    class Wifi{
        public:

            enum class state_e{
                NOT_INIT,
                INITED,
                WAITING_FOR_CREDENTIALS,
                READY_TO_CONNECT,
                CONNECTING,
                WAITING_FOR_IP,
                CONNECTED,
                DISCONNECTED,
                ERROR
            };
            Wifi(void);
            ~Wifi(void);
            Wifi(const Wifi&);
            Wifi(Wifi&&);
            Wifi& operator=(const Wifi&);
            Wifi& operator=(Wifi&&);

            esp_err_t init(void);
            esp_err_t begin(void);

            constexpr const state_e& get_state(void){ 
                return _state;
            }
            constexpr static const char* get_mac(void){
                return mac_add_cstr;
            }
        private:
            void state_machine(void);
            static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);
            static void wifi_event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);
            static void ip_event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);

            static esp_err_t _get_mac(void);
            static char mac_add_cstr[13];

            static std::mutex init_mutx;
            static std::mutex connect_mutx;
            static std::mutex state_mutx;
            // static SemaphoreHandle_t first_call_mutx;
            // static StaticSemaphore_t first_call_mutx_buffer;
            // static bool first_call;

            static esp_err_t _init(void);
            static wifi_init_config_t wifi_init_config;
            static wifi_config_t wifi_config;
            static state_e _state;  
        
    };
}//namesapce WIFI