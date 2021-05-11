/**
 * @file dimmer.c
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief  Código referente ao controle de brilho e acionamento
 *         dos focos semafóricos
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include "stl_structs.hpp"

/**
 * @brief Inicialização do dimmer.
 * 
 * @return retorna sempre 0 se ok 
 */
int dimmer_init(void)
{
    /*
     * 
     */
    return 0;
}

/**
 * @brief Get the zero cross object
 * 
 * @return Retorna sempre 0 se verdadeiro 
 */
int get_zero_cross(void)
{
    digitalRead(ZERO_C);
}




