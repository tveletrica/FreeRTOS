/******************************************************************************
* Creating Task
* This example shows how to create a task in ESP32 using ESP-IDF
* This code is part of the course "Programe o ESP32 com ESP-IDF 5" by Fábio Souza
* The course is available on https://cursos.embarcados.com.br
*
* This example code Creative Commons Attribution 4.0 International License.
* When using the code, you must keep the above copyright notice,
* this list of conditions and the following disclaimer in the source code.
* (http://creativecommons.org/licenses/by/4.0/)

* Author: Fábio Souza
* This code is for teaching purposes only.
* No warranty of any kind is provided.
*******************************************************************************/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG1 = "TASK MAIN ";     //tag to identify the log messages
static const char *TAG2 = "TASK BLINK 1";     //tag to identify the log messages
static const char *TAG3 = "TASK BLINK 2 ";     //tag to identify the log messages
static const char *TAG4 = "TASK COUNT ";     //tag to identify the log messages

#define LED_PIN 33                        //led pin
#define LED_PIN2 26                    //led pin2


/*Task Blink prototipe */
void vTaskBlink(void *pvParameters ); 
void vTaskBlink2(void *pvParameters); 
void vTaskCount(void *pvParameters );




/*task handle*/
TaskHandle_t xTaskBlinkHandle = NULL;
TaskHandle_t xTaskBlinkHandle2 = NULL;
TaskHandle_t xTaskCountHandle = NULL;



/*app_main*/
void app_main(void)
{

    ESP_LOGI(TAG1,"Iniciando o programa");     //log message

      xTaskCreate(
        vTaskBlink,                 //function with the code of the task
        "TaskBlink",                //Task name
        2048,                       //stack size
        NULL,                       //task parameters
            1,                          //task priority
        &xTaskBlinkHandle           //task handle
        );
        

    xTaskCreate(
        vTaskBlink2,                 //function with the code of the task
        "TaskBlink2",                //Task name
        2048,                       //stack size
        NULL,                       //task parameters
        1,                          //task priority
        &xTaskBlinkHandle2            //task handle
        );

    xTaskCreate(
        vTaskCount,                 //function with the code of the task
        "TaskCount",                //Task name
        2048,                       //stack size
        NULL,                       //task parameters
        2,                          //task priority
        &xTaskCountHandle            //task handle
        );

}
/* Task Blink LED */
void vTaskBlink(void *pvParameters )
{
    bool status = false;                            //variable to store the LED status
    
    ESP_LOGI(TAG2,"Iniciando a task Blink");         //log message
    
    /*LED PIN configuration*/
    //gpio_reset_pin(LED_PIN);                        //reset the pin
    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT);   //set the pin as output

    //loop 
    while(1)
    {
        gpio_set_level(LED_PIN,status^=1);                              //LED status
        ESP_LOGI(TAG2,"TASK Blink LED[%d]: %d", LED_PIN,status);         //log message
        vTaskDelay(pdMS_TO_TICKS(1000));                                //delay of 1 second
    }
}
/* Task Blink2 LED */
void vTaskBlink2(void *pvParameters )
{
    bool status = true;                           //variable to store the LED status
    
    ESP_LOGI(TAG3,"Iniciando a task Blink");         //log message
    
    /*LED PIN configuration*/
    //gpio_reset_pin(LED_PIN);                        //reset the pin
    gpio_set_direction(LED_PIN2,GPIO_MODE_OUTPUT);   //set the pin as output
    int i = 0;
    //loop 
    while(1)
    {
        gpio_set_level(LED_PIN2,status^=1);                              //LED status
        ESP_LOGI(TAG3,"TASK Blink LED[%d]: %d", LED_PIN2,status);         //log message
        vTaskDelay(pdMS_TO_TICKS(1000));                                        //delay of 1 second
    }

}

/* Task COUNT */
void vTaskCount(void *pvParameters )
{
                    
    ESP_LOGI(TAG4,"Iniciando a task Count");  //log message
    int i = 0;
    //loop                              
    while(1){
        ESP_LOGI(TAG4,"TASK - Counter: %d",i++);  //log message
        if(i == 10){
            vTaskSuspend(xTaskBlinkHandle2);
            gpio_set_level(LED_PIN2,0);                              //LED status

        } else if(i == 20){
            vTaskSuspend(xTaskBlinkHandle);
            gpio_set_level(LED_PIN,0);                              //LED status
        } else if (i == 30){
            vTaskResume(xTaskBlinkHandle);  
        }else if (i == 40){
            vTaskResume(xTaskBlinkHandle2);  
            i = 0;
        }
        vTaskDelay(pdMS_TO_TICKS(1000));            //delay of 1 second

        
        
    
}
}
                                    