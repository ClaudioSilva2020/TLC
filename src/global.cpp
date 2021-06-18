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
#include "dimmer.hpp"




AsyncWebServer tlc_server(80);
Semafore_t semafores[3];

// Handle Id das tasks
TaskHandle_t semHandleA;
TaskHandle_t semHandleB;
TaskHandle_t semHandleP;

// Count para contar iterações.
int count = 0;
/**
 * @brief Versão de firmware da placa
 * 
 */
char version_firmware[11] = "20210505-1";
dimmer_t init_pin;


/**
 * @brief Task responsável por rodar o semáforo A
 * 
 * @param pvParameters Estrutura com o semáforo
 */
void run_semafore_a(void *pvParameters)
{
    /**
     * @brief Cria variáesis auxiliares e vetor com estrutura de semaforos.
     * 
     */
    Semafore_t *semafore_a;
    semafore_a = (Semafore_t *) pvParameters;

    int gree,
      yellow, 
      yellow_blink,
      red;

    gree = semafore_a->temp_g;
    yellow = semafore_a->temp_y;
    red = semafore_a->temp_r;
    yellow_blink = semafore_a->yellow_blink;
    
    if (semafore_a->id==1)
    {
        // Se os tempos forem 0 então o grupo focal fica apagado
        if (((gree | yellow | red) == 0) && (yellow_blink == 0))
        {
            Serial.println("Grupo focal A desligado");  
            for (;;)
            {
                apaga_gfocal_a();
                vTaskDelay(10);
            }
        }else if (yellow_blink == 1)
        {
            for (;;)
            {
                // digitalWrite(SEMAFOROA_VD, 0);
                // digitalWrite(SEMAFOROA_VM, 0);
                digitalWrite(SEMAFOROA_AM, HIGH);
                Serial.print("AMARELO PISCANTE A on: ");
                Serial.println(yellow_blink);
                vTaskDelay(1000/portTICK_PERIOD_MS);
                

                // digitalWrite(SEMAFOROA_VD, 0);
                // digitalWrite(SEMAFOROA_VM, 0);
                digitalWrite(SEMAFOROA_AM, LOW);
                Serial.print("AMARELO PISCANTE A off: ");
                Serial.println(yellow_blink);
                vTaskDelay(1000/portTICK_PERIOD_MS);

                vTaskDelay(10);
            }            
        }else
        {
            for (;;)
            {
                digitalWrite(SEMAFOROA_VD, HIGH);
                digitalWrite(SEMAFOROA_VM, LOW);
                digitalWrite(SEMAFOROA_AM, LOW);
                Serial.print("VERDE 1: ");
                Serial.println(gree);
                vTaskDelay(gree *1000/portTICK_PERIOD_MS);
                
                

                digitalWrite(SEMAFOROA_VD, LOW);
                digitalWrite(SEMAFOROA_VM, LOW);
                digitalWrite(SEMAFOROA_AM, HIGH);
                Serial.print("AMARELO 1: ");
                Serial.println(yellow);
                vTaskDelay(yellow *1000/portTICK_PERIOD_MS);
                
                

                digitalWrite(SEMAFOROA_VD, LOW);
                digitalWrite(SEMAFOROA_VM, HIGH);
                digitalWrite(SEMAFOROA_AM, LOW);
                Serial.print("VERMELHO 1: ");
                Serial.println(red);
                vTaskDelay(red *1000/portTICK_PERIOD_MS);
                
                vTaskDelay(10);
            } 
        }
    }        

}

/**
 * @brief Task responsável por rodar o semáforo B
 * 
 * @param pvParameters Estrutura com o semfáforo.
 */
void run_semafore_b(void *pvParameters)
{
    /**
     * @brief Cria variáesis auxiliares e vetor com estrutura de semaforos.
     * 
     */
    Semafore_t *semafore_b;
    semafore_b = (Semafore_t *) pvParameters;

    int gree,
      yellow,
      yellow_blink, 
      red;

    gree = semafore_b->temp_g;
    yellow = semafore_b->temp_y;
    red = semafore_b->temp_r;
    yellow_blink = semafore_b->yellow_blink;
    if (semafore_b->id==2)
        {
        if (((gree | yellow | red) == 0) && (yellow_blink == 0))
        {
            Serial.println("Grupo focal B desligado");  
            for (;;)
            {
                apaga_gfocal_b();
                vTaskDelay(10);
            }
        
        }else if (yellow_blink == 1)
        {
            for (;;)
            {
                // digitalWrite(SEMAFOROB_VD, 0);
                // digitalWrite(SEMAFOROB_VM, 0);
                digitalWrite(SEMAFOROB_AM, HIGH);
                Serial.print("AMARELO PISCANTE B on: ");
                Serial.println(yellow_blink);
                vTaskDelay(1000/portTICK_PERIOD_MS);
                

                // digitalWrite(SEMAFOROB_VD, 0);
                // digitalWrite(SEMAFOROB_VM, 0);
                digitalWrite(SEMAFOROB_AM, LOW);
                Serial.print("AMARELO PISCANTE B off: ");
                Serial.println(yellow_blink);
                vTaskDelay(1000/portTICK_PERIOD_MS);

                vTaskDelay(10);
            }
            
        }
        else
        {
            for (;;)
            {
                digitalWrite(SEMAFOROB_VD, LOW);
                digitalWrite(SEMAFOROB_VM, HIGH);
                digitalWrite(SEMAFOROB_AM, LOW);
                Serial.print("VERMELHO 2: ");
                Serial.println(red);
                vTaskDelay(red *1000/portTICK_PERIOD_MS);
                

                digitalWrite(SEMAFOROB_VD, HIGH);
                digitalWrite(SEMAFOROB_VM, LOW);
                digitalWrite(SEMAFOROB_AM, LOW);
                Serial.print("VERDE 2: ");
                Serial.println(gree);
                vTaskDelay(gree *1000/portTICK_PERIOD_MS);
                

                digitalWrite(SEMAFOROB_VD, LOW);
                digitalWrite(SEMAFOROB_VM, LOW);
                digitalWrite(SEMAFOROB_AM, HIGH);
                Serial.print("AMARELO 2: ");
                Serial.println(yellow);
                vTaskDelay(yellow *1000/portTICK_PERIOD_MS);
                
                vTaskDelay(10);
            }
        }
    }
}
    
void run_semafore_p(void *pvParameters)
{
    Semafore_t *semafore_p;
    semafore_p = (Semafore_t *) pvParameters;

    int gree,
      detect_p;

    gree = semafore_p->temp_g;

    if (semafore_p->id == 3)
    {
        if (gree == 0)
        {
            Serial.println("Não tem semáforo de pedestres.");
            for (;;)
            {
                apaga_gfocal_p();
                vTaskDelay(10);
            }
        }else
        {
            for (;;)
            {
                detect_p = digitalRead(PED_DETECT);

                if (detect_p == 0)
                {
                Serial.println("Detectou pedestre");
                vTaskDelay(10000/portTICK_PERIOD_MS);

                vTaskDelete(semHandleA);
                vTaskDelete(semHandleB);
                Serial.println("Deletou tasks");

                apaga_gfocal_a();
                apaga_gfocal_b();
                apaga_gfocal_p();
                digitalWrite(SEMAFOROB_AM, HIGH);
                digitalWrite(SEMAFOROA_AM, HIGH);
                vTaskDelay(3*1000/portTICK_PERIOD_MS);    

                digitalWrite(SEMAFOROB_AM, LOW);
                digitalWrite(SEMAFOROA_AM, LOW);
                digitalWrite(SEMAFOROB_VM, HIGH);
                digitalWrite(SEMAFOROA_VM, HIGH);
                Serial.println("Acendeu vermelhos");

                digitalWrite(SEMAFOROP_VD, HIGH);
                digitalWrite(SEMAFOROP_VM, LOW);
                Serial.print("VERDE P:");
                Serial.println(gree);
                vTaskDelay(gree*1000/portTICK_PERIOD_MS);
                digitalWrite(SEMAFOROP_VD, LOW);
                for (size_t i = 0; i < 10; i++)
                {
                    digitalWrite(SEMAFOROP_VM, HIGH);
                    Serial.println("VERMELHO PH:");
                    vTaskDelay(250/portTICK_PERIOD_MS);
                    digitalWrite(SEMAFOROP_VM, LOW);
                    Serial.println("VERMELHO PL:");
                    vTaskDelay(250/portTICK_PERIOD_MS);
                }
                apaga_gfocal_a();
                apaga_gfocal_b();
                digitalWrite(SEMAFOROP_VM, HIGH);
                xTaskCreate(run_semafore_a, "run_semafore_a", 4024*5, (void *) &semafores[0],  12, &semHandleA);
                xTaskCreate(run_semafore_b, "run_semafore_b", 4024*5, (void *) &semafores[1],  12, &semHandleB);
                }else
                {
                digitalWrite(SEMAFOROP_VM, HIGH);
                vTaskDelay(10);
                }
                vTaskDelay(10);
            }
        }
    }
}

void init_all_pins(void)
{   
    /**
     * @brief Seta os pinos que correspondem ao semaforo A como saída
     * 
     */
    for (size_t i = 0; i < FOCOS_NORMAL_AMOUNT; i++)
    {
        // pinMode(gpios_semaforoa[i], OUTPUT);
        // pinMode(gpios_semaforob[i], OUTPUT);
    }

    /**
     * @brief Seta os pinos do semáforo de pedestre como saída
     * 
     */
    for (size_t i = 0; i < FOCOS_PEDESTRE_AMOUT; i++)
    {
        // pinMode(gpios_semaforop[i], OUTPUT);
    }

    /**
     * @brief Seta o pino de detecção de zero como entrada e o pino de disparao
     *        de triguer como saída e o coloca em nível baixo.
     */
    // pinMode(ZC_DETECT, INPUT);
    // pinMode(init_pin.DISPARO, OUTPUT);
    // digitalWrite(init_pin.DISPARO, LOW);
    pinMode(SEMAFOROA_AM, OUTPUT);
    pinMode(SEMAFOROA_VD, OUTPUT);
    pinMode(SEMAFOROA_VM, OUTPUT);

    pinMode(SEMAFOROB_AM, OUTPUT);
    pinMode(SEMAFOROB_VD, OUTPUT);
    pinMode(SEMAFOROB_VM, OUTPUT);

    pinMode(SEMAFOROP_VD, OUTPUT);
    pinMode(SEMAFOROP_VM, OUTPUT);
    pinMode(PED_DETECT, INPUT);

}

void apaga_gfocal_a()
{
  digitalWrite(SEMAFOROA_VD, 0);
  digitalWrite(SEMAFOROA_VM, 0);
  digitalWrite(SEMAFOROA_AM, 0); 
}

void apaga_gfocal_b()
{
  digitalWrite(SEMAFOROB_VD, 0);
  digitalWrite(SEMAFOROB_VM, 0);
  digitalWrite(SEMAFOROB_AM, 0);
}

void apaga_gfocal_p()
{
  digitalWrite(SEMAFOROP_VD, 0);
  digitalWrite(SEMAFOROP_VM, 0);
}

void spiffs_tlc_service(void)
{
    

    Serial.println("Iniciando");
    tlc_server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });
    
    // Route to load style.css file
    tlc_server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/style.css", "text/css");
    });

    tlc_server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request)
    {
        String am_gfocalblinka;
        String am_gfocalblinkb;  

        String vd_gfocala = request->getParam("tgreen1")->value();
        String vm_gfocala = request->getParam("tred1")->value();
        String am_gfocala = request->getParam("tyellow1")->value();
        
        String vd_gfocalb = request->getParam("tgreen2")->value();
        String vm_gfocalb = request->getParam("tred2")->value();
        String am_gfocalb = request->getParam("tyellow2")->value();
        if (request->hasParam("blinkYA"))
        {
            
            semafores[0].yellow_blink = 1;
        }else
        {
            semafores[0].yellow_blink = 0;
        }

         if (request->hasParam("blinkYB"))
        {
            semafores[1].yellow_blink = 1;
        }else
        {
            semafores[1].yellow_blink = 0;
        }

        String vd_gfocalp = request->getParam("tgreen3")->value();

        /**
         * @brief Se o valor de piscar o amarelo for on
         *        então passa o true para a estrutura.
         */
        
        
        
        
    
        semafores[0].temp_g = vd_gfocala.toInt();
        semafores[0].temp_r = vm_gfocala.toInt();
        semafores[0].temp_y = am_gfocala.toInt();
        semafores[0].id = 1;

        semafores[1].temp_g = vd_gfocalb.toInt();
        semafores[1].temp_r = vm_gfocalb.toInt();
        semafores[1].temp_y = am_gfocalb.toInt();
        semafores[1].id = 2;

        semafores[2].temp_g = vd_gfocalp.toInt();
        semafores[2].temp_r = 0;
        semafores[2].temp_y = 0;
        semafores[2].id = 3;

        count ++;
        Serial.print("Iteração: ");
        Serial.println(count);
        if (count > 1)
        {
        vTaskDelete(semHandleA);
        Serial.println("Apagando TaskA");
        vTaskDelete(semHandleB); 
        Serial.println("Apagando TaskB");
        vTaskDelete(semHandleP); 
        Serial.println("Apagando TaskP");
        }

        
        request->send(SPIFFS, "/index.html", "text/html");
        request->send(SPIFFS, "/style.css", "text/css");

        
        xTaskCreate(run_semafore_a, "run_semafore_a", 4024*5, (void *) &semafores[0],  12, &semHandleA); 
        xTaskCreate(run_semafore_b, "run_semafore_b", 4024*5, (void *) &semafores[1],  12, &semHandleB);
        xTaskCreate(run_semafore_p, "run_semafore_p", 4024*5, (void *) &semafores[2],  12, &semHandleP);

        if (count == sizeof(count))
        {
        count = 1;
        Serial.println("Count = 1");
        }
        // semafores[0].yellow_blink = 0;
        // semafores[1].yellow_blink = 0;
    });

    // Inicia servidor
    tlc_server.begin();        
}