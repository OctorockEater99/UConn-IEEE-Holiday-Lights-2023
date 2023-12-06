#ifndef FASTLED
#define FASTLED
#include <FastLED.h>
#endif

#ifndef PGMSPACE
#define PGMSPACE
#include <avr/pgmspace.h>
#endif

#ifndef PARAMS
#define PARAMS
//default parameters
#define COLS 14
#define ROWS 16
#define PADDING 4
#define NUM_CANVAS_LEDS ROWS*COLS
#define NUM_LEDS ROWS*(COLS+PADDING)
#define REVERSED true
#endif

#ifndef MATRIX_H
#define MATRIX_H

int XY_canvas(int x, int y, bool reversed = REVERSED);
int XY(int x, int y);

void loadImage(struct CRGB *leds_dest, const unsigned char *image);
void loadColor(struct CRGB *leds_dest, struct CRGB color);
void scrollImage(struct CRGB *led_dest, const unsigned char *img1, const unsigned char *img2, unsigned int d);
void scrollImageSequence(const unsigned char *sequence[], size_t length, unsigned int duration);
void indexDebug(struct CRGB *leds_dest, struct CRGB color = CRGB::Red);

#endif