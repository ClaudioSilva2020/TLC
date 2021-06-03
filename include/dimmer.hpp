/**
 * @file dimmer.h
 * @author Cláudio Silva (claudioccdsilva@gmail.com)
 * @brief  protótipos de funções e macros referentes 
 *         ao acionamento dos focos semafóricos.
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _DIMMER_H_

    #define _DIMMER_H_


    #include <Arduino.h>



    const float PERCENT_ADJUST = 1.0; 
    #define PERIODO 7.000

    
    typedef struct dimmer
    {
        uint8_t ZCDETECT = 16;
        uint8_t DISPARO = 26; 

    }dimmer_t;


    extern int dimmer_init(void);
    extern void set_shine();
    extern void get_zero_cross(void);
#endif
