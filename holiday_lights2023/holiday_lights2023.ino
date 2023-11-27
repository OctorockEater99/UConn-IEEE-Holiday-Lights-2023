#ifndef FASTLED
#define FASTLED
#include <FastLED.h>
#endif

#ifndef PGMSPACE
#define PGMSPACE
#include <avr/pgmspace.h>
#endif

#include "matrix.h"
#include "images.h"

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  loadImage(leds, tree);
  FastLED.show();
  delay(500);

  FastLED.clear(true); // true writes the cleared data to the leds
  delay(50);

  loadColor(leds, CRGB::Red);
  FastLED.show();
  delay(100);

  FastLED.clear(true);
  delay(50);

  // FastLED.getFPS();
  // 
}
