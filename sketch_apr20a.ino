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
TaskHandle_t handle_task_4 = NULL;

TaskHandle_t handle_task_5 = NULL;

void task_1(void* parameter) 
{
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 2000;
  xLastWakeTime = xTaskGetTickCount();
   while(1) 
   {
     Serial.println("Task 1");
   }

}
void task_2(void* parameter)
{
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 3000;
  xLastWakeTime = xTaskGetTickCount();
   while(1) 
   {
   Serial.println("Task 2");
   }
}
void task_3(void* parameter)
{
  TickType_t xLastWakeTime;
  const TickType_t xFrequency = 6000;
  xLastWakeTime = xTaskGetTickCount();
   while(1) {
Serial.println("Task 3");
   }
}
void task_4(void* parameter)
{
  while(1)
  {
    Serial.println("Sender");
  }
}
void task_5(void* parameter)  
{
  while(1)
  {
    Serial.println("Reciver");
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  
   xTaskCreate(&task_1, "TaskOne", STACK_SIZE ,NULL,5, &handle_task_1 );
   xTaskCreate(&task_2, "TaskTwo", STACK_SIZE ,NULL,5, &handle_task_2 );
   xTaskCreate(&task_3, "TaskThree", STACK_SIZE ,NULL,5, &handle_task_3 );
   xTaskCreate(&task_4, "TaskFour", STACK_SIZE ,NULL,5, &handle_task_4 );
   xTaskCreate(&task_5, "TaskFive", STACK_SIZE ,NULL,5, &handle_task_5 );
}
void loop() {
  // put your main code here, to run repeatedly:

}
