/**
 * @file global.c
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief  Definições das variáveis de vários arquivos
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>
#include "global.hpp"
#include "stl_structs.hpp"


/**
 * @brief Versão de firmware da placa
 * 
 */
char version_firmware[11] = "20210505-1";

/**
 * @brief Task responsável por inicializar o harsware da placa
 * 
 * @param pvParameters parâmetros pasados para a task
 */
void init_hardware(void *pvParameters)
{
    digitalWrite(VERDE_S1, HIGH);
    digitalWrite(AMARELO_S1, LOW);
    vTaskDelay(500/portTICK_PERIOD_MS);

    digitalWrite(VERDE_S1, LOW);
    digitalWrite(AMARELO_S1, HIGH);
    vTaskDelay(500/portTICK_PERIOD_MS);


}

void init_all_pins(void)
{   
    pinMode(AMARELO_S1, OUTPUT);
    pinMode(VERDE_S1, OUTPUT);
}