#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);
 
// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;
 
#define BROCHE_ATOM_BTN_ROUGE 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BROCHE_ATOM_BOUTON 39
#define BROCHE_ATOM_PIXEL 27

#define KEY_CHANNEL_ANGLE 0
#define KEY_CHANNEL_LIGHT 1
 
//CRGB keyPixel;
CRGB atomPixel;
 
 
void setup() {
 
  // NE JAMAIS OUBLIER !!!
  Serial.begin(115200);
  Wire.begin();
  myPbHub.begin();
 
}
 
void loop() {
 
  // oscslip key unit
  int press = myPbHub.analogRead(KEY_CHANNEL_ANGLE);
  monOsc.sendInt("/ANGLE", press);
  delay(100);

    // oscslip key unit
    int LUM = myPbHub.analogRead(KEY_CHANNEL_LIGHT);
    monOsc.sendInt("/LIGHT", LUM);
    delay(100);
}