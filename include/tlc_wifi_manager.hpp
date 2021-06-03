/**
 * @file tlc_wifi_manager.hpp
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief Arquivo de cabecalio para definições de rede do projeto.
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _TLC_WIFI_MANAGER_HPP_

    #define __TLC_WIFI_MANAGER_HPP_
    #include <Arduino.h>
    #include "WiFi.h"
    #include "ESPAsyncWebServer.h"
    #include "SPIFFS.h"
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstdlib>
    #include <string>
    #include <AsyncTCP.h>  
    #include "global.hpp"
    #include "stl_structs.hpp"
    

    typedef struct tlc_wifi_manager
    {
        const char* SSID = "TLC";
        const char* PASSWRD = "87250187";
        uint8_t IP_LOCAL[5] = {192, 168, 1, 46};
        uint8_t GATEWAY [5]  = {192, 168 ,1 ,1};
        uint8_t SUBNET [5] = {255 ,255 ,0 ,0};
        uint8_t DNS1 [5] = {8, 8, 8 ,8 ,8};
        uint8_t DNS2 [5] = {8, 8, 8, 4, 4};
    }tlc_wifi_manager_t;
    
    void wifi_init_tlc(void);
    void spiffs_tlc_service(void);






#endif