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

#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void loadRandom(struct CRGB *leds_dest) {
  int dest_index = 0;
  int zero = 0;
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      dest_index = XY_canvas(i, j);
      zero = random8() > 15 ? 0 : 1; 
      leds_dest[dest_index] = CRGB(max(random8(), 127)*zero, max(random8(), 127)*zero, max(random8(), 127)*zero);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  // scrollImage(leds, tree, among, 1000);
  // FastLED.show();
  // indexDebug(leds);
  FastLED.clear();
  loadRandom(leds);
  FastLED.show();
  // FastLED.getFPS();
  // FastLED.delay();
  delay(20);
}
