/**
 * @file main.cpp
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>
#include <FreeRTOS.h>
#include "stl_structs.hpp"
#include "global.hpp"
#include "WiFi.h"
#include "SPIFFS.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "dimmer.hpp"
#include "tlc_wifi_manager.hpp"



void setup() 
{
  Serial.begin(115200); //inicia a Serial
  init_all_pins();
  apaga_gfocal_a();
  apaga_gfocal_b();
  apaga_gfocal_p();
  wifi_init_tlc();
  spiffs_tlc_service();
  // attachInterrupt(digitalPinToInterrupt(ZC_DETECT), set_shine, RISING);
  
}

void loop() 
{
    
}