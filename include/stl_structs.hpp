/**
 * @file stl_structs.h
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _STL_STRUCTS_HPP_

    #define _STL_STRUCTS_HPP_

    #include <Arduino.h>

    #define ZERO_C 2
    #define HARDWARE_SIZE_TSK 1000

    #define VERDE_S1    3
    #define AMARELO_S1  2
    #define VERMELHO_S1 1

    #define VERDE_S2    6
    #define AMARELO_S2  4
    #define VERMELHO_S2 5



    typedef enum _FASE_SEMAFORO
    {
        VERDE = 0,
        AMARELO = 1,
        VERMELHO = 2,
    } fase_semaforica;

    typedef struct stl_structs
    {
        /* data */
    } Semafore;
    
    

#endif