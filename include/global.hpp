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
    #include "WiFi.h"
    #include "ESPAsyncWebServer.h"
    #include "SPIFFS.h"
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <cstdlib>
    #include <string>


    #define ZC_DETECT 16
    #define HARDWARE_SIZE_TSK 4024

    /**
     * @brief Definições das pinagens do semáforo A
     * Semáforo comum.
     */
    #define SEMAFOROA_VD 25
    #define SEMAFOROA_AM 33
    #define SEMAFOROA_VM 32

    /**
     * @brief Definições de pinagens do Semáformo B
     * Semáforo comum.
     */
    #define SEMAFOROB_VD 14
    #define SEMAFOROB_AM 27
    #define SEMAFOROB_VM 26

    /**
     * @brief Sefinições de pinagens do semáforo de P
     * Semáforo de Pedestres.
     */
    #define SEMAFOROP_VD 12
    #define SEMAFOROP_VM 13
    #define PED_DETECT   15

   

    typedef struct
    {
        int id;
        int temp_g;
        int temp_r;
        int temp_y;
        int time;
        int yellow_blink = 0;
    } Semafore_t;

    /**
     * @brief Vetor com os gpios de cada grupo focal
     * 
     */
    // uint32_t gpios_semaforoa[3] = {SEMAFOROA_VD, SEMAFOROA_AM, SEMAFOROA_VM};
    // uint32_t gpios_semaforob[3] = {SEMAFOROB_VD, SEMAFOROB_AM, SEMAFOROB_VM};
    // uint32_t gpios_semaforop[2] = {SEMAFOROP_VD, SEMAFOROP_VM};

    #define FOCOS_NORMAL_AMOUNT 3
    #define FOCOS_PEDESTRE_AMOUT 2
    /**
     * @brief Versão de Firmware da placa.
     * 
     */
    // char version_firmware[11];

    /**
     * @brief Protótipos
     * 
     */
    void run_semafore_a(void *pvParameters);
    void run_semafore_b(void *pvParameters);
    void run_semafore_p(void *pvParameters);
    void init_all_pins(void);
    void apaga_gfocal_a();
    void apaga_gfocal_b();
    void apaga_gfocal_p();

#endif
