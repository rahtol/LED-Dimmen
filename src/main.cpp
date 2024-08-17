#include <Arduino.h>

uint16_t duty;
uint16_t adcRead;
bool onOff;

void setup() {
    Serial.begin(115200);

    uint32_t rc_ledcSetup = ledcSetup(1, 10000, 10);
    Serial.printf("ledcSetup=%d\n", rc_ledcSetup);
    ledcAttachPin(4, 1);
    duty = 512;

    pinMode(0, INPUT_PULLUP);
    adcRead = 128;

    onOff = true;
}

void loop() {
    if (duty % 16 == 0) {
        adcRead = analogRead(0);
        Serial.printf("duty=%d, adcRead=%d, onOff=%d\n", duty, adcRead, onOff);
    };

    duty = (duty + 8) % 1024;

    if(adcRead < 128) {
        ledcWrite(1, duty);
    }
    else if (adcRead > 4096-128) {
        ledcWrite(1, (onOff ? 1023 : 0));
        onOff = !onOff;        
    }
    else {
        ledcWrite(1, adcRead / 4);
    }

    delay(100);
}

