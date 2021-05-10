/**
 * @file main.cpp
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief Arquivo principal
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <Arduino.h>
#include "dimmer.h"
#include "stl_structs.h"
#include "global.h""

void setup() 
{
    xTaskCreate(init_hardware,
                "init_hardware",
                HARDWARE_SIZE_TSK,
                NULL,
                0,
                NULL);
    dimmer_init();
  
}

void loop() 
{
  
}