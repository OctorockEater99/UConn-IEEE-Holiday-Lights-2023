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
const unsigned char* uconn[5] = {u, c, o, n, n};
const unsigned char* huskies[7] = {h, u, s, k, i, e, s};

void loadRandom(struct CRGB *leds_dest) {
  int dest_index = 0;
  int zero = 0;
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      dest_index = XY_canvas(i, j);
      zero = random8() > 100 ? 0 : 1; 
      leds_dest[dest_index] |= CRGB(max(random8(), 127)*zero, max(random8(), 127)*zero, max(random8(), 127)*zero);
    }
  }
}

void randomDemo(int duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    loadRandom(leds);
    FastLED.show();
    for (int i = 0; i < 50; i++) {
      fadeToBlackBy(leds, NUM_LEDS, 15);
      FastLED.show();
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
  /* scroll through uconn letters
   * random lights blink/fade
   * scroll through ieee letters
   * flash christmas tree
   * flash candy cane
   * snowing demo (if possible)
   * randomly flash xxxxxxx :)
  */

  scrollImageSequence(leds, uconn, 5, 300);
  delay(500);

  FastLED.clear(true);
  delay(1000);

  loadImage(leds, candycane);
  FastLED.show();
  delay(1000);

  FastLED.clear(true);
  delay(1000);

  randomDemo(5000);
  FastLED.clear(true);
  delay(1000);

  scrollImageSequence(leds, huskies, 7, 300);
  delay(500);

  if (random8() < 16) {
    loadImage(leds, among);
    FastLED.show();
    delay(1000);
    FastLED.clear(true);
    delay(1000);
  }

  loadImage(leds, tree);
  FastLED.show();
  delay(1000);
  FastLED.clear();
  delay(1000);

  //indexDebug(leds);
}
