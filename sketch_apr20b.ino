#include<stdio.h>
#include"FreeRTOS.h"
#include"freertos/task.h"
#include"esp_system.h"
#include"driver/gpio.h"


#define STACK_SIZE 1000
static const int led_pin = LED_BUILTIN;
unsigned long clocktime;


TaskHandle_t handle_task_1 = NULL;
TaskHandle_t handle_task_2 = NULL;
TaskHandle_t handle_task_3 = NULL;
static TimerHandle_t one_shot_timer = NULL;


void task_1(void* parameter) 
{
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 1500; 
  xLastWakeTime = xTaskGetTickCount();
   while(1) 
   {
     Serial.println("Task 1");
   }

}
void task_2(void* parameter)
{
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 2500; 
  xLastWakeTime = xTaskGetTickCount();
   while(1) 
   {
    Serial.println("Task 2");
   }
}
void task_3(void* parameter)
{
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 5500;
  xLastWakeTime = xTaskGetTickCount();
   while(1) {
Serial.println("Task 3");
   }
}
void myTimerCallback(TimerHandle_t xTimer) {

  // Print message if timer 0 expired
  if ((uint32_t)pvTimerGetTimerID(xTimer) == 0) {
    Serial.println("Timer expires");
  }
  }
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  
   xTaskCreate(&task_1, "TaskOne", STACK_SIZE ,NULL,5, &handle_task_1 );
   xTaskCreate(&task_2, "TaskTwo", STACK_SIZE ,NULL,5, &handle_task_2 );
   xTaskCreate(&task_3, "TaskThree", STACK_SIZE ,NULL,5, &handle_task_3 );
   one_shot_timer = xTimerCreate(
                      "One-shot timer",           
                      5000 / portTICK_PERIOD_MS,  
                      pdTRUE,                   
                      (void *)0,                 
                      myTimerCallback);           
                    }
void loop() {
  // put your main code here, to run repeatedly:

}
