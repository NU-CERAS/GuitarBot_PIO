#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>

void TaskBlink(void *pvParameters) {
    pinMode(2, OUTPUT);
    while (true) {
        digitalWrite(2, !digitalRead(2));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void setup() {
    xTaskCreate(TaskBlink, "Blink", 2048, NULL, 1, NULL);
}

void loop() {
    // if using Arduino framework, loop() runs as its own task
}
