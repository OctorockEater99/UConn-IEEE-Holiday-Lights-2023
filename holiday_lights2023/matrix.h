#ifndef FASTLED
#define FASTLED
#include <FastLED.h>
#endif

#ifndef PGMSPACE
#define PGMSPACE
#include <avr/pgmspace.h>
#endif

#ifndef MATRIX_H
#define MATRIX_H

#define COLS 14
#define ROWS 16
#define PADDING 4
#define NUM_CANVAS_LEDS ROWS*COLS
#define NUM_LEDS ROWS*(COLS+PADDING)

int XY_canvas(int x, int y);
int XY(int x, int y);

void loadImage(struct CRGB *leds_dest, const unsigned char *image);
void loadColor(struct CRGB *leds_dest, struct CRGB color);
void indexDebug(struct CRGB *leds_dest, struct CRGB color = CRGB::Red);

#endif