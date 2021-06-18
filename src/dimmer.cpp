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
#include "dimmer.hpp"

/**
 * @brief Status da rotina de detecção
 * 0 está pronto e 1 está processando;
 */
uint8_t zc_status = 0;
dimmer_t dimmer;
volatile float ADJUSTES = 1.0;

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
 * @brief Seta o brilho no LED
 *        Essa função transforma o valor de porsentagem de 0 a 100%
 *        em ânulo de disparo:
 *        se ângulo = 0 -> 0/120pi = 0 Então o tempo de atraso do disparo é 0,
 *        se ângulo = pi -> pi/120pi = 8333us de atraso mas esse valor é dividido
 *        por 2 pois é considerado apenas meio ciclo da onda, então o atraso fica de 
 *        4166us na onda isso ceifa a metade. * 
 */
void IRAM_ATTR set_shine()
{
    vTaskDelay(((PERCENT_ADJUST - ADJUSTES) * PERIODO)/portTICK_PERIOD_MS);
    digitalWrite(dimmer.DISPARO, HIGH);   

    vTaskDelay(0.5/portTICK_PERIOD_MS);
    digitalWrite(dimmer.DISPARO, LOW);
}

/**
 * @brief Get the zero cross object
 * 
 * @return Retorna sempre 0 se verdadeiro 
 */
void IRAM_ATTR get_zero_cross(void)
{
    dimmer_init();
    if (zc_status == 0)
    {
        zc_status = 1;

        set_shine();
    }   
}





