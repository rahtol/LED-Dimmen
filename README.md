# A simple ESP32 project using the LEDC library to dim a LED  

An ADC input - preferrably connected to a potentiometer - is used to control the brightness.
Two special cases: (1) an ADC reading below 128 results in automatic fading every ca. 12.8s
(2) an ADC reading above 4096-128 lets the LED flash with 5Hz.
Values in beween directly control the PWM duty cycle and thus LED brightness.

LEDC library uses PWM to realize dimming and is part of ESP32 Arduino framework.  
See "github.com/espressif/arduino-esp32" and "espressif-docs.readthedocs-hosted.com/projects/ardguino-esp32" version 2.0.14

Target: ESP32 from AZ-Delivery.  
Setup: Vscode + Platformio  
Board: "WEMOS D1 MINI ESP32"  
Framework: "Arduino"  
