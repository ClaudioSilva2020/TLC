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

    /**
     * @brief Versão de Firmware da placa.
     * 
     */
    // char version_firmware[11];

    void init_hardware(void *pvParameters);
    void init_all_pins(void);

#endif
