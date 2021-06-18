/**
 * @file tlc_wifi_manager.cpp
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief Arquivo de configurações e gerenciamento de rede do projeto
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ESPAsyncWebServer.h"
#include <Arduino.h>
#include "WiFi.h"
#include "tlc_wifi_manager.hpp"





tlc_wifi_manager_t wifi_tlc;








IPAddress local_IP(wifi_tlc.IP_LOCAL);
IPAddress gateway(wifi_tlc.GATEWAY);
IPAddress subnet(wifi_tlc.SUBNET);
IPAddress primaryDNS(wifi_tlc.DNS1);
IPAddress secondarDNS(wifi_tlc.DNS2);



void wifi_init_tlc(void)
{
   /* if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondarDNS))
    {
        Serial.println("Falha a configurar o wifi");
    }*/

    if (!SPIFFS.begin(true))
    {
        Serial.println("Não conseguiu inicializar SPIFFS");
        return;
    }

    Serial.print("Criando rede WIFI: ");
    Serial.println(wifi_tlc.SSID);
    WiFi.softAP(wifi_tlc.SSID, wifi_tlc.PASSWRD);
    
    Serial.println(" ");
    Serial.print("Wifi Criado como: ");
    Serial.println(wifi_tlc.SSID);
    Serial.println("Com o endereço IP:");
    Serial.println(WiFi.softAPIP());       
}






