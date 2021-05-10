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
#include "global.h"
#include "stl_structs.h"


/**
 * @brief Versão de firmware da placa
 * 
 */
const char version_firmware[11] = "20210505-1";

/**
 * @brief Task responsável por inicializar o harsware da placa
 * 
 * @param pvParameters parâmetros pasados para a task
 */
void init_hardware(void *pvParameters)
{
    digitalWrite(VERDE_S1, 1);
    digitalWrite(AMARELO_S1, 0);
}