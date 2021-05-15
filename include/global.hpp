/**
 * @file global.hpp
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief Arquivo de definições globais.
 *        Inclui as definições das variaveis utilizadas 
 *        por diversos arquivos.
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _GLOBALS_HPP_

    #define _GLOBALS_HPP_

    #include <Arduino.h>

    #define VERDE_S1    3
    #define AMARELO_S1  2
    #define VERMELHO_S1 1

    #define VERDE_S2    6
    #define AMARELO_S2  4
    #define VERMELHO_S2 5

    /**
     * @brief Versão de Firmware da placa.
     * 
     */
    // char version_firmware[11];

    void init_hardware(void *pvParameters);
    void init_all_pins(void);

#endif
