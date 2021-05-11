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


void setup() 
{
  init_all_pins();
  
  xTaskCreate(init_hardware,
              "init_hardware",
              HARDWARE_SIZE_TSK,
              NULL,
              5,
              NULL);
  
}

void loop() 
{

}